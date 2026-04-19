# 模板 template
我们在别的语言中了解过**泛型 Generics**，事实上，模板比范型更为强大，甚至“疯狂”
模板更接近宏定义，本质上就是让编译器按照我的要求，为我写代码
用模板写的函数，本质上是提供一个蓝本，当我调用它时，我可以指定特定参数，这个参数决定了函数使用的实际代码

## 基本方法
在要使用的含函数/类之前，加入一行，在`typename`后定义一个模板名（比方说`T`），随后在函数/类里面所有需要用模板的地方把类型名换成`T`就可以了
注意：`typename` 也可以换成 `class`，效果完全一样；但显然前者更容易理解
```cpp
template <typename T>

template <class T>
```

对于函数，比方说：
```cpp
#include <iostream>

template <typename T>
T max(T a, T b) {
  T reslut = (a > b) ? a : b;
  std::cout << reslut << std::endl; 
  return reslut;
}

int main() {
  max(3, 7);        // 7 (int)
  max(3.14, 2.71);  // 3.14 (double)
  max('a', 'z');    // 'z' (char)
  return 0;
}
```

对于类，又比方说：
```cpp
#include <iostream>
#include <string>

template <typename T>
class Box {
private:
    T content;
public:
    Box(T val) : content(val) {}
    T get() const { return content; }
};

int main() {
    Box<int> intBox(123);
    Box<std::string> strBox("Hello");
    std::cout << intBox.get() << std::endl;   // 123
    std::cout << strBox.get() << std::endl;   // Hello
    return 0;
}
```

## 进阶用法
使用模板的函数/类，本不会在定义他的地方就被构造出来，而在调用他的时候，编译器才会把他构造出来
所以编译器在编译阶段不会检查出任何函数的语法错误
进一步地，我们可以在别的地方用到这些特性

### 1. 非类型模板参数
模板参数不仅可以是类型，也可以是整型、枚举、指针、引用等编译期常量
比方说定义一个大小不明的类型任意的数组：
```cpp
#include <iostream>
#include <string>

template<typename T, int N>
class Array{
  private:
    T m_Array[N];
  public:
    int GetSize() const{return N;}
};

int main(){
  Array<std::string, 5> array;

  std::cout << array.GetSize() << std::endl;

  std::cin.get();
}
```

### 2. 模板特化 Specialization
针对某些特殊类型，可以提供专门的实现，覆盖默认模板，类似与重载操作
```cpp
template <typename T>
class Printer {
public:
    void print(T val) {
        std::cout << "General: " << val << std::endl;
    }
};

// 针对 std::string 的全特化
template <>
class Printer<std::string> {
public:
    void print(std::string val) {
        std::cout << "Special for string: " << val << std::endl;
    }
};
```

### 3. 默认模板参数
可以给模板参数指定默认值（C++11 起函数模板也支持）
```cpp
template <typename T = int, int Size = 10>
class FixedArray {
    T arr[Size];
};

FixedArray<> defaultArray;        // 等价于 FixedArray<int,10>
FixedArray<double, 5> doubleArray;
```

### 4. 变参模板
接受任意数量的模板参数，用于实现元组、递归打印等
```cpp
void print() {}   // 递归终止函数

template <typename T, typename... Args>
void print(T first, Args... args) {
    std::cout << first << " ";
    print(args...);
}

// 使用
print(1, 2.5, "hello", 'a');  // 输出 1 2.5 hello a
```
其中`typename... Args `称为模板参数包，`args...`是函数参数包

## 禁忌用法
一定量的模板可以减少重载的次数，减少代码复杂性
但是如果模板使用过度了，我们会得到一个几乎黑洞的只有编译器和写代码时候的我才玩得最明白的逻辑黑洞
这样不仅导致可读性急剧减少，还导致模板元编程（TMP）可以在编译期完成巨量复杂计算
模板实例化错误可能在深层调用链中爆发，排查时如同大海捞针
