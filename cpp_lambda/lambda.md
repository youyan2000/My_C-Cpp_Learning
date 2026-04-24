# lambda
Lambda给我们提供一种使用**匿名函数对象 Anonymous function**的方法
我们用lambda创建的函数，只是一个快速的一次性函数，可以方便地在代码中定义临时的、可调用的代码块

## 基本语法
```cpp
[capture](parameters) -> return_type { body }
```
`capture`：捕获列表，指定如何捕获外部变量
- `=`通过复制变量传递
- `&`通过引用传递
- `具体变量名`直接传递变量
`parameters`：参数列表（可选）
`return_type`：返回类型（可选，可自动推导）
`body`：函数体

## 简单示例
```cpp
#include <iostream>
#include <vector>
#include <algorithm>

void ForEach(const std::vector<int>& values, void(*func)(int)) {
  for (int value : values) {
    func(value);
  }
}
int main() {
  std::vector<int> values = {1, 4, 5, 2, 3};
  ForEach(values, [](int value){std::cout << "Value: " << value << std::endl;});
  std::cin.get();
}
```

## 捕获列表
捕获列表是 lambda 最强大的特性：
```cpp
int x = 10, y = 20;

// 值捕获（复制）
auto by_value = [x, y]() { return x + y; };

// 引用捕获
auto by_ref = [&x, &y]() { x++; y++; };

// 隐式捕获
auto all_by_value = [=]() { return x + y; };      // 全部值捕获
auto all_by_ref   = [&]() { x++; y++; };          // 全部引用捕获

// 混合捕获
auto mixed = [=, &y]() { 
    // x 值捕获，y 引用捕获
    return x + y;
};

// C++14 广义捕获
auto unique = [value = std::make_unique<int>(42)]() {
    return *value;
};
```
