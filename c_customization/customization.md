# 自定义数据类型 customization

## c与c++对比
| 类型   | C 语言           | C++ 语言               |
| ------ | ---------------- | ---------------------- |
| struct | 只能存数据       | 能存函数 = class       |
| union  | 只能存数据       | 能存函数、更安全       |
| enum   | 就是整数，不安全 | 支持强类型枚举，更安全 |

## 枚举 enum(enumeration)
把可能的情况一一罗列 → 让取值范围受限
默认第一位为0，可以设置第一位为任何整数，随后向后依次增加
本质上只是让你的代码更美观

### C 风格的**弱枚举 Unscoped Enum**
```c
// 定义：默认第一个常量为 0，依次递增 +1
enum Color {
    RED,    // 0
    GREEN,  // 1
    BLUE    // 2
};

// 自定义值
enum Status {
    OK = 200,
    NOT_FOUND = 404,
    ERROR = 500
};

// 使用（本质上就是整数）
enum Color c = RED;
if (c == 0) { /* C语言中允许这样比较，类型不安全 */ }
```

### C++ **强类型枚举 Scoped Enum / enum class**
解决了 C 枚举的作用域污染和隐式转换问题。
```cpp
// 定义：使用 class 关键字，成员作用域受限
enum class TrafficLight {
    Red,
    Yellow,
    Green
};

// 使用：必须带类型名前缀
TrafficLight light = TrafficLight::Red;

// 错误示范：不能隐式转为 int
// int val = TrafficLight::Red; // 编译报错！

// 正确：需显式转换
int val = static_cast<int>(TrafficLight::Red);
```

## 结构体 struct
使用不同数据而组合成的一种数据

### 定义与声明
```c
struct Student {
  // 数据成员
  int id;
  char name[50];
  float score;
  /* C++ 特有：成员函数
  void printInfo() {
    printf("ID: %d, Name: %s\n", id, name);
  }
  */
}; // 注意：分号不能少
```

### 成员访问运算符：`.` 与 `->`
| 运算符          | 适用对象            | 语法示例      | 含义                              |
| --------------- | ------------------- | ------------- | --------------------------------- |
| . (点运算符)    | 结构体变量 (值类型) | stu.id = 1;   | 直接通过变量名访问成员            |
| -> (箭头运算符) | 结构体指针 (地址)   | pStu->id = 1; | 等价于 (*pStu).id，先解引用再访问 |

代码示例：
```cpp
Student stu1;           // 栈上分配，是一个实体变量
Student* pStu = &stu1;  // 指针指向 stu1

// 方式一：点运算符操作变量
stu1.id = 1001;

// 方式二：箭头运算符操作指针（写法更优雅）
pStu->id = 1001; 
// 等价于 (*pStu).id = 1001;
```

### 内存对齐 Memory Alignment
结构体在内存中的大小不一定等于所有成员大小之和。编译器为了 CPU 读取效率，会插入**填充字节 Padding**
```c
struct A {
  char c;   // 1 字节
  int  i;   // 4 字节 (为了对齐，c 后面会空出 3 个字节)
};
// sizeof(A) 通常为 8，而不是 5。
```

## 联合体 union
所有成员（数据类型可以不同）共享同一块内存空间
联合体的大小等于其最大成员的大小
修改一个成员的值，会影响其他成员的值（因为它们看的是同一块内存里的不同解读方式）

### 基础用法与内存模型
```cpp
union Data {
    int    i;   // 4 字节
    float  f;   // 4 字节
    char   str[20]; // 20 字节
};

int main() {
    union Data data;
    // sizeof(data) 为 20（由最大的 char[20] 决定）
    
    data.i = 10;
    // 此时 data.f 的值是混乱的（把整数10的二进制解释为浮点数）
    
    data.f = 3.14f;
    // 此时 data.i 的值被覆盖了
    
    return 0;
}
```

### 应用场景
- 节省内存：例如一个变量在程序不同阶段可能是 int 类型或 float 类型，用 union 比用 struct 省空间
- 类型双关 (Type Punning)：用于判断浮点数的字节序或实现特殊协议解析（如 IP 地址转 32 位整数）
