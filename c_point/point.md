# 指针 point
指针只是一个保存内存地址的整数

## 常用玩法
取地址符 address-of：`&`   把变量变成对应的地址
解引用符 dereference：`*`  把地址变成对应的变量

## 原始函数指针 raw funtion pointer
当我们要给一个函数传入另一个函数时，我们不能直接把一个函数“传”进去，我们只能把函数的指针作为参数传进去
于是，我们需要函数指针

### 定义
函数指针的定义语法需要匹配函数的返回值和参数列表，格式为：
`返回值类型 (*指针变量名)(参数类型列表);`
示例 1：指向返回 int、接受两个 int 参数的函数
`int (*addPtr)(int, int);`
示例 2：指向返回 void、无参数的函数
`void (*printPtr)();`

```c
// 声明一个指向“返回void，无参数”函数的指针
void (*function)(); 
// 赋值
function = HelloWorld;
// 调用
function();
```

和其他变量一样，我们可以用`typedof`简化我们的定义
```c
// 先定义别名（通常放在文件头部）
typedef void (*HelloWorldFunction)();
// 使用时非常简洁，看起来就像定义一个int一样简单
HelloWorldFunction function; 
// 赋值
function = HelloWorld;
// 调用
function();
```

### 使用实例
```c
#include <stdio.h>
void PrintValue(int value) {
  printf("Value: %d\n", value);
}
void ForEach(int* values, int length, void(*func)(int)) {
  for (int i = 0; i < length; i++) {
    func(values[i]);
  }
}
int main() {
  int values[] = {1, 4, 5, 2, 3};
  int length = sizeof(values) / sizeof(values[0]);
  ForEach(values, length, PrintValue);
  return 0;
}
```

## NULL指针
在变量声明的时候，如果没有确切的地址可以赋值，为指针变量赋一个 NULL 值是一个良好的编程习惯
赋为 `NULL` 值的指针被称为**空指针**
#include <stdio.h>
```c 
int main (){
  int  *ptr = NULL;
  printf("ptr 的地址是 %p\n", ptr  );
  return 0;
}
```
输出结果为 : `ptr 的地址是 0x0`