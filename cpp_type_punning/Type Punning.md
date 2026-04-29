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
### 指针强转(混乱邪恶)
```cpp
float f = *(float*)&a;
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

### cast
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
🟩 std::bit_cast（C++20）——类型双关首选
#include <bit>

int a = 0x3f800000;
float f = std::bit_cast<float>(a);

✔ 特点：

按位复制（bit-level）
类型安全
编译期可优化（零开销）

✔ 要求：

sizeof(T) == sizeof(U)

👉 本质：

安全版类型双关

🟥 reinterpret_cast —— 底层工具（危险）
int a = 0x3f800000;
float* f = reinterpret_cast<float*>(&a);

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
⚪ static_cast —— 默认选择
double value = 5.43;
float f = static_cast<float>(value);

✔ 行为：

数值转换
编译期完成

❗ 注意：

int a = 0x3f800000;
float f = static_cast<float>(a); // ❌不是类型双关
🟦 dynamic_cast —— 多态安全
class Base {
public:
    virtual ~Base() {}
};

class Derived : public Base {};

Base* b = new Derived();
Derived* d = dynamic_cast<Derived*>(b);

✔ 特点：

运行时检查
安全但慢
✔ 失败返回：

nullptr
🟨 const_cast —— 改 const
const int a = 10;
int* p = const_cast<int*>(&a);

❗ 关键规则：

*p = 20; // ❌ UB（如果 a 原本是 const）

✔ 正确使用：

void foo(const int* p) {
    int* mod = const_cast<int*>(p); // 前提：原对象不是 const
}

