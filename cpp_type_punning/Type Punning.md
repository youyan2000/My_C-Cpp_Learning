# 类型双关
类型双关是绕开C++语言的类型系统的方式
C++是强类型的语言，他不像javascript一样不需要做出任何类型声明，也不像C#那样难以绕开类型系统
所以C++是一种原始而高效的语言，但是需要当心他的使用
- - -
## 类型双关的本质
假设你有一段内存，本来是 int，但你硬把它当成 float 来读：
```cpp
int a = 0x3f800000; // IEEE754 里代表 1.0f
float f = *(float*)&a;

std::cout << f << std::endl; // 可能输出 1.0
```
同一块内存：
用 int 看是 0x3f800000
用 float 看是 1.0
严格来说，只有**按位解释**才是类型双关，而值的类型转换并不是，但是我们并没有这么严格
- - -
## 常见实现方式
### 强转(混乱邪恶)
这是我们在C语言中较为常见的方式，比方说
*指针强转*
```c
float f = *(float*)&a;
```
或者可以是
*直接强转*
```c
float f = (int)a;
```
问题：
- 违反 严格别名规则（strict aliasing rule）
- 编译器优化时可能直接炸（结果不确定）

### union(混乱善良)
```cpp
union U {
    int i;
    float f;
};

U u;
u.i = 0x3f800000;
std::cout << u.f << std::endl;
```
C语言里是标准用法
C++中严格来说仍然有未定义行为（但很多编译器支持）

### memcpy（中立善良）
```cpp
int a = 0x3f800000;
float f;
std::memcpy(&f, &a, sizeof(float));
```
完全符合标准
编译器通常会优化成无开销
但是栈的空间总是有限的，不能无限制地申请内存

### casting 类型转换
cast是一种有效的类型双关方式
他们类型安全，编译期可优化，语义清晰
虽然他们中部分没有这么善良，但他们名字的特殊性让他在程序中可以被搜索到，所以我们可以更简单地注意到他们的使用
在这个意义上，他们至少都是中立的
| cast               | 本质行为              | 阵营                                 |
| ------------------ | --------------------- | ------------------------------------ |
| `bit_cast`         | 按位复制 + 新类型解释 | 守序中立：标准、安全、专门干类型双关 |
| `reinterpret_cast` | 按位重解释内存        | 中立邪恶：强行解释内存，可能 UB      |
| `dynamic_cast`     | 运行时类型检查        | 中立善良：严格遵守类型系统，还会检查 |
| `const_cast`       | 去掉/添加 const       | 混乱中立：改规则，但不完全破坏       |
| `static_cast`      | 值转换 / 合法类型转换 | 绝对中立：最“正常”的转换           |

#### `bit_cast`（C++20）类型双关首选
示例
```cpp
#include <bit>

int a = 0x3f800000;
float f = std::bit_cast<float>(a);
```

特点：
- 按位复制（bit-level）
- 类型安全
- 编译期可优化（零开销）

**要求**：
`sizeof(T) == sizeof(U)`

#### `reinterpret_cast`
```cpp
int a = 0x3f800000;
float* f = reinterpret_cast<float*>(&a);
```
❗ 风险：

违反严格别名规则
可能 UB
编译器优化会出问题

✔ 正确使用场景（重要）：

auto reg = reinterpret_cast<volatile uint32_t*>(0x40021000);

👉 典型用途：

嵌入式寄存器
内存映射
硬件访问
#### `static_cast`
```cpp
double value = 5.43;
float f = static_cast<float>(value);
```
特点：
数值转换
编译期完成（几乎没有开销）

#### `dynamic_cast`
用于多态类型之间的安全类型转换（尤其是向下转型）

如果我们在做一些非法的转换：
比方说，一个*角色*父类有*玩家*和*敌人*两子类，我们妄图把一个*敌人*转成*角色*再转成*玩家*，这显然是非法的

**Runtime Type Information, RTTI, 运行时类型信息**会储存实体的真实类型
非法的时候`dynamic_cast`就会给我们返回`nullptr`；合法的时候就会给我们返回转换后的指针
（我们当然可以利用这个特性，来检测一个实体的类型究竟是什么）

示例：
```cpp
class Role {
  public:
    virtual ~Role() {}
};

class Player : public Role {};
class Enemy : public Role {};

Role* player = new Player();
Role* enemy  = new Enemy();

Player* p1 = dynamic_cast<Player*>(player); // ✅ 成功
Player* p2 = dynamic_cast<Player*>(enemy);  // ❌ nullptr

/*判断一个基类指针实际指向的派生类类型*/
if (Player* p = dynamic_cast<Player*>(role)) {
  // 是 Player
}
```

特点：
运行时检查，并计算
不是在编译的时候完成，安全，但也因此有算力的开销

#### `const_cast` 
修改const（因此，使用前提：原对象不是 const）

示例：
```cpp
const int a = 10;
int* p = const_cast<int*>(&a);
```
