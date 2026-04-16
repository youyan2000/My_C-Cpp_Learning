# 内存分配

## 内存分区
- 栈 stack —— 局部变量、函数形参（系统自动分配，块完成后自动释放）
- 堆 heap —— malloc 动态内存（手动申请，手动释放）
- 全局数据区 —— 全局数据、静态变量、字符串常量
- 代码区 —— 可执行代码

高地址
┌─────────────────────
│ 命令行参数、环境变量
├─────────────────────
│ 堆区 (heap) malloc
├─────────────────────
│ 空闲空间
├─────────────────────
│ 栈区 (stack) 局部变量
├─────────────────────
│ 全局/静态数据区
│   ├─ .data 已初始化
│   ├─ .bss  未初始化
│   └─ .rodata 只读常量区 ← 字符串在这！
├─────────────────────
│ 代码区 (.text) 函数、指令
└─────────────────────
低地址

数据在内存中不存在"数据类型"的观念
动态内存分配就是根据需求向系统的堆区申请一个连续的内存空间

## C动态内存分配
引入<stdlib.h>头文件

### malloc 分配一个内存空间
在堆区分配一块指定大小的内存空间，用来存放数据。这块内存空间在函数执行完成后不会被初始化，它们的值是未知的
```c
void *malloc(int num);
```

### calloc 分配一串内存空间
在内存中动态地分配 num 个长度为 size 的连续空间，并将每一个字节都初始化为 0。所以它的结果是分配了 num*size 个字节长度的内存空间，并且每个字节的值都是 0
```c
void *calloc(int num, int size);
```

### relloc 重新分配内存空间
该函数重新分配内存，把内存扩展到 newsize
```c
void *realloc(void *address, int newsize);
```

### free 释放内存空间
该函数释放 address 所指向的内存块,释放的是动态分配的内存空间。
```c
void free(void *address); 
```

## C++动态内存分配
### new
`new`本质上只是一个**操作符 operator**(和`+`/`-`并没有什么区别)
C++的标准库中，`new`就是调用了`malloc()`+对象的构造函数
```cpp
double* pvalue = new double;
double* parray = new double[50];
Entity* pentity = new Entity();
```

### delete
对应地，分配了内存就必须释放内存
C++的标准库中,`delete`就是调用了`free()`+对象的析构函数
```cpp
delete pvalue;
delete[] parray;
delete pentity;
```

