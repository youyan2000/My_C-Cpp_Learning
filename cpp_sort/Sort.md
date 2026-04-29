# 排序
## `std::sort`
C++为我们提供了一个标准的排序函数

### 引入头文件
`<vector>`和`<algorithm>`

### 使用方法
`std::sort(数组的开端, 数组的结尾, 谓词);`
谓词决定哪个数排在更前面的位置，传入两个数a,b，谓词返回ture就不交换位置，返回false就交换位置

### 示例
```cpp
std::vector<int> values = {3,5,1,4,2};
//常规降序排列
std::sort(values.begin(), values.end());
//自定义升序排列
#include <functional>
std::sort(v.begin(), v.end(), std::greater<int>());
//自定义排列
std::sort(v.begin(), v.end(), [](int a, int b) {
  if(a == 1)
    return false;
  if(b == 1)
    return ture;
  return a > b;
});
```