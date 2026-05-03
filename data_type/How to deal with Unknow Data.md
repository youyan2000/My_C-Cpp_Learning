# 怎么处理未知返回值？
## optional 处理不知道有还是没有的值
当我们没有`std::optional`的时候，我们只能做这样的操作：
```cpp
#include <iostream>
#include <fstream>
std::string ReadFileAsString(const std::string& filepath, bool& outSuccess){
  std::ifstream stream(filepath);
  if (stream){
    std::string result((std::istreambuf_iterator<char>(stream)),
                        std::istreambuf_iterator<char>());
    stream.close();
    outSuccess = true;
    return result;
  }
  outSuccess = false;
  return std::string();
}
int main(){
  bool IsOutSuccess;
  std::string data = ReadFileAsString("data.txt", IsOutSuccess);
  if (IsOutSuccess){
  }
}
```
使用`std::optional`我们可以简化我们的操作：
```cpp
#include <iostream>
#include <fstream>
#include <optional>
std::optional<std::string> ReadFileAsString(const std::string& filepath){
  std::ifstream stream(filepath);
  if (stream){
    std::string result((std::istreambuf_iterator<char>(stream)),
                        std::istreambuf_iterator<char>());
    stream.close();
    return result;
  }
  return {};
}
int main(){
  std::optional<std::string> data = ReadFileAsString("data.txt");
  std::string gotdata = data.value_or("nothing");
  if (data.has_value){
    std::cout << "File is opened!";
  }else{
    std::cout << "File is not opened!";
  }
  std::cout << gotvalue << std::endl;
}
```
`.value_or`所获得的值，或者自行定义的内容
`.has_value`是否获得值
`.value`所获得的值

## variant 处理多种数据类型
比方说：
```cpp
#include <iostream>
#include <variant>
int main(){
  std::variant <std::string, int> data;
  data = "Eugene";
  std:: cout << std::get<std:: string>(data) << "\n";
  if(auto value = std::get_if<std::string>(&data)){
    std::string& v = *value;
  }else{
  }
  data = 2;
  std::cout << std::get<int>(data) << "\n";
  std::cin. get();
}
```
和union的不同之处在于，union的大小是其中所有类型中最大的类型，而variant是所有类型的总和

| 特性 / 方面    | `template`   |`std::variant`       |
| -------------- | -------------------------- | ------------------------------- |
| **类型机制**   | 编译时多态（Compile-time polymorphism）           | 运行时多态（Runtime type-safe union）                                 |
| **类型确定性** | 类型在编译期确定，每个实例都是独立类型            | 类型在运行期确定，变量可存储多种类型之一                              |
| **语法示例**   | `template<typename T> void func(T value) { ... }` | `std::variant<int, double, std::string> v;`                           |
| **使用场景**   | 类型泛化、算法复用、性能优化                      | 需要在同一变量中存储多种可能类型，并在运行时安全访问                  |
| **性能**       | 编译期决定，通常无额外开销                        | 有运行时开销，访问时需要 `std::get` 或 `std::visit`                   |
| **类型安全**   | 完全由编译器检查                                  | 访问时由 `std::get`/`std::visit` 保证类型安全，错误会抛异常或断言失败 |
| **扩展性**     | 易于扩展模板参数（新类型只要模板实例化即可）      | 扩展需要修改 `std::variant` 定义（类型列表固定）                      |
| **内存布局**   | 编译期生成特定类型代码，每种实例独立              | 内存为最大成员大小 + 标记位（存储当前类型索引）                       |
| **调试友好性** | 生成代码复杂，错误信息可能冗长   | 调试时可以查看当前类型索引，更直观    |
| **常见用途**   | 泛型算法、容器、函数模板、类模板     | 可变类型容器、事件系统、联合类型、安全替代 `union`   |

## any 处理未知数据类型
比方说：
```cpp
#include <iostream>
#include <any>
int main(){
  std::any data;
  data = 2;
  data = "Eugene";
  data = std::string("Eugene");

  std::string& string = std::any_cast<std::string&>(data);  
}
```
在处理小于32字节的类型时候，any就是一个安全的union；大于32字节的时候，他就会通过动态分配内存来储蓄变量