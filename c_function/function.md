# 函数调用
函数名就是这个函数的地址

## 函数的根本作用：功能复用
任何一个“运算符”本质上都是一个函数

## 怎么实现函数的多返回值？
### 方案一(也是最佳方案) struct
创造一个struct，包含多个返回值类型，让函数返回这个struct
可读性最好，每个字段都有名字；无额外拷贝开销（现代编译器会优化）
例如：
```c
struct Result {
  int sum;
  int diff;
  double product;
};

Result compute(int a, int b) {
  Result r;
  r.sum = a + b;
  r.diff = a - b;
  r.product = a * b;
  return r;
}

int main(){
  Result res = compute(10, 3);
}
```

### 方案二 reference/point
给函数传入参数的时候，给他几个引用或者指针，把要返回的值直接等于给这几个引用或者指针
从性能角度看，这是最高效的方法，因为它没有进行任何的复制工作，而仅仅是给多个已有的变量赋值
例如：
```c
void compute(int a, int b, int& sum, int& diff, double& product) {
  sum = a + b;
  diff = a - b;
  product = a * b;
}

int main(){
  int s, d;
  double p;
  compute(10, 3, s, d, p);
}
```

### 方案三 array/vector
返回一个数组，这个数组里包含所要返回的值
类型必须相同；需要靠下标或约定访问，可读性差
例如：
```cpp
#include <vector>
vector<int> compute(int a, int b) {
  return {a + b, a - b, a * b};
}

int main(){
  vector<int> res = compute(10, 3);
}
```

### 方案四 tuple
返回一个元组，可以包含不同类型的多个值，用结构化绑定（C++17）方便拆解
缺点字段没有名字，只能靠顺序读或`std::get`
例如：
```cpp
#include <tuple>
tuple<int, int, double> compute(int a, int b) {
  return {a + b, a - b, a * b};
}

int main(){
  // 使用 (C++17)
  auto [sum, diff, product] = compute(10, 3);
  // 或 C++11/14 用 tie
  int s, d;
  double p;
  tie(s, d, p) = compute(10, 3);
}
```

### 方案五 pair
当只需要返回两个值时，`pair`是最轻量级的`tuple`
`pair`包含`first` / `second` 成员，也支持结构化绑定
例如：
```cpp
#include <utility> 

pair<int, double> compute(int a, int b) {
  return {a + b, a * b};
}

int main() {
  // C++17 结构化绑定
  auto [sum, product] = compute(10, 3);
  
  // 传统方式
  pair<int, double> res = compute(10, 3);
  int s = res.first;
  double p = res.second;
}
```

## 调用流程
**CPU用到的寄存器**
- ESP（Extended Stack Pointer）：栈指针寄存器，始终指向栈顶（最上面的栈帧的顶部），入栈时ESP减小（因为栈从高地址向低地址生长），出栈时ESP增大。
- EBP（Extended Base Pointer）：基址指针寄存器，始终指向当前函数栈帧的底部，用于定位当前栈帧中的参数、局部变量（相当于栈帧的“锚点”）。
- EIP（Extended Instruction Pointer）：指令指针寄存器，指向CPU下一条要执行的指令地址，函数调用时会保存当前EIP的值（返回地址），函数执行完后恢复，让程序回到调用处继续执行。

### 1. 参数入栈：
按照「从右到左」的顺序，将函数参数压入栈中（x86架构约定，64位架构有差异）。即先压入b，再压入a。此时ESP指向栈顶（a的位置），参数通过栈传递给被调用函数。

### 2. 保存返回地址：
将当前EIP的值（即main函数中“func(a,b);”的下一条指令地址）压入栈中。这个地址是func执行完后，程序要回到main继续执行的“路标”，也是返回地址的核心作用——确保函数调用结束后，程序能回归原执行流程。此时ESP再次减小，指向返回地址。

### 3. 保存调用函数的EBP（栈帧锚点）：
将main函数的EBP值压入栈中，此时ESP指向该值。这一步的作用是“记住”调用函数（main）的栈帧底部，方便后续返回时恢复main的栈帧，避免栈帧混乱。

### 4. 设置当前函数的EBP：
将ESP的值赋给EBP，此时EBP和ESP指向同一位置，即func函数栈帧的底部（锚点确立）。后续func的局部变量、临时数据，都将基于EBP定位。

### 5. 开辟局部变量空间：
调整ESP的位置（ESP减小，因为栈向低地址生长），开辟出一块内存空间，用于存储func的局部变量（如int x、char y等）。此时ESP指向func栈帧的顶部，栈帧结构正式形成（从EBP到ESP之间的区域，就是func的栈帧）。

### 6. 执行func函数体：
CPU根据EIP指向的func指令地址，依次执行func的代码（从代码区读取指令），执行过程中如需操作局部变量、参数，均通过EBP定位（如通过EBP+偏移量找到参数a、b，通过EBP-偏移量找到局部变量）。

### 7. 保存返回值：
将func的返回值（如return后的结果）存入EAX寄存器（x86架构约定，返回值默认存在EAX中），供main函数读取。

### 8. 释放局部变量空间：
将ESP的值赋给EBP（此时ESP指向func栈帧的底部，即之前保存的main的EBP值），相当于释放了局部变量占用的栈空间（栈帧顶部上移）。

### 9. 恢复main的EBP：
将栈顶的值（之前保存的main的EBP）弹出到EBP寄存器，此时EBP回归到main函数的栈帧底部，完成main栈帧的恢复。同时ESP增大，指向栈顶的返回地址。

### 10. 恢复返回地址：
将栈顶的返回地址（之前保存的main下一条指令地址）弹出到EIP寄存器，此时CPU的EIP指向main函数中“func(a,b);”的下一条指令。

### 11. 参数出栈（可选）：
部分编译器会自动将栈中的参数（a、b）弹出，ESP继续增大，回归到调用func之前的栈顶位置，完成整个栈的恢复。
