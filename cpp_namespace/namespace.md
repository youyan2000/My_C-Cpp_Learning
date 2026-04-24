# 命名空间 namespace
命名空间本质上就是为了解决重名的问题；我们在C语言中通常会使用在函数名前加入一个名称来解决
比方说，在C语言中，我们会调用`HAL_Delay`，而在C++中，我们可以改成`HAL::Delay`

## `using`指令
`using namespace`指令，可以在使用命名空间时就可以不用在前面加上命名空间的名称
这个指令会告诉编译器，后续的代码将使用指定的命名空间中的名称
比方说
```cpp
#include <iostream>
using namespace std;
// 第一个命名空间
namespace first_space{
  void func(){
    cout << "Inside first_space" << endl;
  }
}
// 第二个命名空间
namespace second_space{
  void func(){
    cout << "Inside second_space" << endl;
  }
}
using namespace first_space;
int main(){
  // 调用第一个命名空间中的函数
  func();
  return 0;
}
```
`using namespace`让我们更轻松地使用标准库函数，但是同样给我们带来了灾难
比方说，我们将无法辨别哪些函数来自标准库，哪些函数来自标准库还是我们自己的发明
又比方说，当我们引入一个新的`namespace`时，会导致原来使用的其他`namespace`中重名的函数出现错误

## 重命名
我们可以用 `namespace <新名字> = <旧名字>;`给一个命名空间重命名
```cpp
#include <iostream>
using namespace std;
// my_sapace命名空间
namespace my_space{
  void func(){
    cout << "Inside first_space" << endl;
  }
}
namespace a = my_space;
int main(){
  // 调用my_sapace命名空间中的函数
  a::func();
  return 0;
}
```

## 嵌套命名空间
我们当然可以在一个命名空间内定义另一个命名空间
比方说
```cpp
namespace namespace_name1 {
  namespace namespace_name2 {

  }
}
```
我们也当然通过`::`访问命名空间的成员
```cpp
// 访问 namespace_name2 中的成员
using namespace namespace_name1::namespace_name2;
// 访问 namespace_name1 中的成员
using namespace namespace_name1;
```
