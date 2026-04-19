# Auto
`auto`用于自动类型推导。它让编译器根据变量的初始化表达式来推断其实际类型，从而简化代码、增强可维护性，尤其在模板和复杂类型场景中非常有用。
## 基本用法
```cpp
auto i = 42;                      // i 是 int
auto d = i;                       // d 也是 int
auto s = "hello";                 // s 是 const char*
auto v = std::vector<int>{1,2,3}; // v 是 std::vector<int>
```
必须初始化：auto 不能单独声明，必须由初始值推导类型

## 类型推导规则
### 1.去除引用和 const/volatile（除非显式指定）
```cpp
int x = 5;
const int cx = x;
int& rx = x;

auto a = cx;    // a 是 int（丢弃 const）
auto b = rx;    // b 是 int（丢弃引用）
const auto c = cx; // c 是 const int
auto& d = rx;   // d 是 int&
const auto& e = cx; // e 是 const int&
```

### 2.数组和函数退化
```cpp
int arr[10];
auto p = arr;    // p 是 int*（数组退化为指针）
auto& r = arr;   // r 是 int(&)[10]（保留数组引用）

void func(int);
auto f = func;   // f 是 void(*)(int)（函数退化为函数指针）
auto& g = func;  // g 是 void(&)(int)
```

### 3.初始化列表
```cpp
auto x = {1, 2, 3}; // x 是 std::initializer_list<int>
auto y = {1};       // y 是 std::initializer_list<int>
auto z{1};          // C++17 后 z 是 int（统一初始化，规则有变化）
```
注意：直接使用 `auto z = {1}` 与 `auto z{1}` 在不同标准下有细微差别，建议统一使用 = 或避免歧义。

## 常见使用场景
`auto`和`template`一样，可以简化代码，但是会带来阅读理解的debug上的问题
所以我们尽量在具有简化冗长类型名的情况下使用

### 简化冗长类型名
```cpp
// 没有 auto
std::vector<std::string>::iterator it = vec.begin();

// 使用 auto
auto it = vec.begin();
```

### 配合范围`for`循环
```cpp
for (const auto& elem : container) { ... }
for (auto& elem : container) { ... }   // 修改元素
```

### `Lambda`表达式
```cpp
auto cmp = [](int a, int b) { return a > b; };
std::sort(v.begin(), v.end(), cmp);
```

### 函数返回类型推导
```cpp
auto add(int a, int b) { return a + b; } // 返回类型推导为 int
```

### 结构化绑定
```cpp
std::map<int, std::string> m;
for (const auto& [key, val] : m) { ... }
```

### 泛型`lambda`参数
```cpp
auto lambda = [](auto x, auto y) { return x + y; };
lambda(1, 2);   // int
lambda(1.5, 2.5); // double
```

## 其他问题
### 代理类问题
```cpp
std::vector<bool> vb = {true, false};
auto x = vb[0];   // x 是 std::vector<bool>::reference 的代理对象，不是 bool！
```
像`std::vector<bool>::reference`这样的代理类型，`auto`会直接保存代理对象，可能导致悬垂引用
解决方案是显式转型或使用`bool x = vb[0];`。

### 与 decltype 的区别
- `auto` 丢弃引用和 cv 限定符（除非显式写 auto&、const auto）
- `decltype(expr)` 保留所有类型信息（包括引用和 const）
```cpp
int x = 0;
const int& rx = x;
auto a = rx;           // int
decltype(rx) b = rx;   // const int&
```