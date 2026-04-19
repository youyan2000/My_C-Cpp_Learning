# 宏定义 macro definition
宏定义由预处理器处理，在编译前进行文本替换
C++ 中推荐使用 `constexpr`、`inline` 函数、模板等替代宏，但在某些场景（条件编译、日志、通用代码生成）中仍有用武之地

## 基本语法
### 1. 基本宏定义
```cpp
#define PI 3.14159          // 定义常量
#define MAX_BUF 1024        // 定义大小

// 使用后可以 #undef 取消定义
#undef PI
```
### 2. 带参数的宏（类函数宏）
```cpp
#define SQUARE(x) ((x)*(x))      // 注意括号防优先级问题
#define MAX(a,b) ((a)>(b)?(a):(b))
// 错误示例：缺少括号可能导致意外
#define BAD_SQUARE(x) x*x
int r = BAD_SQUARE(2+3);   // 展开为 2+3*2+3 = 11，而非 25
```
重要：参数和整体都要加括号，每个参数独立括号。

### 3. 字符串化操作符 `#`
将宏参数转换为字符串字面量
```cpp
#define STR(x) #x
#define LOG(val) std::cout << #val << " = " << (val) << std::endl;

int a = 10;
LOG(a);          // 输出: a = 10
LOG(hello);      // 输出: hello = hello (hello 当作标识符)
STR(   abc   )   // 展开为 "abc" (前后空格被忽略，中间空格压缩为1个)
```

### 4. 连接操作符 `##`
将两个记号拼接成一个新记号
```cpp
#define CONCAT(a,b) a##b
#define VAR(n) var_##n

int CONCAT(my, Var) = 42;   // 生成标识符 myVar
int VAR(1) = 100;           // 生成 var_1
```
常用于生成变量名、函数名或类型名。

### 5. 可变参数宏 __VA_ARGS__
C++11 起支持，用于接收可变数量的参数
```cpp
#define DEBUG_PRINT(fmt, ...) printf(fmt, __VA_ARGS__)
// 使用时
DEBUG_PRINT("x=%d, y=%d\n", x, y);
// 解决无额外参数时的逗号问题（GNU扩展或C++20的__VA_OPT__）
#define DEBUG(fmt, ...) printf(fmt, ##__VA_ARGS__)   // GNU
// C++20 标准写法
#define DEBUG(fmt, ...) printf(fmt __VA_OPT__(,) __VA_ARGS__)
```

### 6. 条件编译与预定义宏
```cpp
#define DEBUG 1

#if DEBUG
    std::cout << "Debug info" << std::endl;
#endif

// 常用指令： #if, #ifdef, #ifndef, #elif, #else, #endif

// 检测平台或编译器
#ifdef _WIN32
    // Windows 特定代码
#elif __linux__
    // Linux 特定代码
#endif
```

常见预定义宏
```cpp
__cplusplus          // C++ 标准版本，如 201703L
__LINE__             // 当前行号
__FILE__             // 当前文件名
__DATE__             // 编译日期 "MMM DD YYYY"
__TIME__             // 编译时间 "HH:MM:SS"
__func__             // 当前函数名（C++11，不是宏，但类似）
```

## 常见操作
### 头文件保护
```cpp
#ifndef MY_HEADER_H
#define MY_HEADER_H
// 内容
#endif
```
现代编译器支持 `#pragma once`，更简洁

### 断言宏
```cpp
#define ASSERT(cond) do { if (!(cond)) { std::cerr << "Assertion failed: " #cond << " at " << __FILE__ << ":" << __LINE__ << std::endl; std::abort(); } } while(0)
```

### 禁用某个函数（常见于禁用拷贝构造）
```cpp
#define DISABLE_COPY(ClassName) \
  ClassName(const ClassName&) = delete; \
  ClassName& operator=(const ClassName&) = delete
```

### 发行版本切换
```cpp
#if PR_DEBUG == 1
#define LOG(x) std::cout << x << std::endl
#elif defined(PR_RELEASE)
#define LOG(x)
#endif
```
