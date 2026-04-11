# 字符串
字符串本质还是数组，是一个以`\0`作为结束标志的字符数组，是 C 语言最常用的数据结构

## 字符串的定义
### 指针形式
格式：
`char *<指针名> = "<字符串内容>";`未加const，语法合法但不可修改（修改崩溃）
`const char *<指针名> = "<字符串内容>";`加const，明确只读，编译时禁止修改（更安全）

e.g.
```c
char *s1 = "Hello World";
const char *s2 = "Hello World";
```

神秘特性：
- 字符串常量存储在**只读常量区 .rodata**，不可修改
- 相同字符串常量会被编译器优化，指向同一块内存，地址相同
- 指针本身存储在栈区（局部）或全局数据区（全局），仅保存字符串首地址，不复制内容

### 数组形式（栈内存 / 可修改）
格式：
`char 数组名[] = "字符串内容";` 自动补\0
`char 数组名[长度] = {字符1, 字符2, ..., '\0'};` 需要手动补\0

e.g.
```c
char s4[] = "Hello World";
char s5[12] = {'H','e','l','l','o',' ','W','o','r','l','d','\0'};
```

神秘特性：
- 字符串内容存储在 栈区（局部数组）或全局数据区（全局数组），可读可写
- 每个数组占用独立内存空间，即使内容相同，地址也不同

## C的<string.h>
<string.h>是 C语言专门用于字符串操作的头文件

### 1.求字符串长度（strlen）
`size_t strlen(const char *str);`
    功能：计算字符串有效长度（不计\0）
    示例：
e.g.
```c
char s[] = "Hello";
size_t len = strlen(s); // len = 5（不含'\0'）
printf("长度：%zu\n", len); // 打印用%zu（匹配size_t类型）
return 0;
```

### 2.字符串拷贝（strcpy/strncpy）
strcpy（基础拷贝）：`char *strcpy(char *dest, const char *src);`
  将src指向的字符串拷贝到dest，自动复制\0
  需保证dest空间足够，否则会越界
strncpy（安全拷贝）：`char *strncpy(char *dest, const char *src, size_t n);`
  最多拷贝n个字符，避免越界，未拷贝完则不补\0
e.g.
```c
    char dest[20];
    char src[] = "Hello World";
    strcpy(dest, src); // dest = "Hello World"
    strncpy(dest, src, 5); // dest = "Hello"（需手动补'\0'）
```

### 3.字符串拼接（strcat/strncat）
`char *strcat(char *dest, const char *src);`
功能：将src指向的字符串拼接在dest末尾，自动覆盖dest的\0
e.g.
```c
    char s[20] = "Hello ";
    strcat(s, "World"); // s = "Hello World"
```

### 4.字符串比较（strcmp/strncmp）
`int strcmp(const char *str1, const char *str2);`
功能 : 按 ASCII 码逐字符比较，返回值判断大小：
       返回 0：str1 == str2
       返回 < 0：str1 < str2
       返回 > 0：str1 > str2
e.g.
```c
char s1[] = "apple", s2[] = "banana";
printf("%d",strcmp(s1, s2));
```

### 5.其他常用函数
`strchr` : 查找字符在字符串中第一次出现的位置
`strrchr` : 查找字符在字符串中最后一次出现的位置
`strstr` : 查找子串在字符串中出现的位置
`memset` : 初始化字符串（常用清空数组），如memset(s, 0, sizeof(s));

**注** : 函数返回值size_t是无符号整数，不能用int接收（避免负数判断错误）。

## C++的<string>
<string>是 C++ 标准库头文件，封装了string类

### 基本定义与赋值
```cpp
std::string s1;                // 定义空字符串
std::string s2 = "Hello C++";  // 直接赋值
std::string s3(s2);            // 用s2初始化s3（拷贝构造）
s1 = "Hello World";       // 赋值操作（无需函数，直接赋值）
```

### 常用操作（无需调用函数，直接用运算符）

| 操作 | 代码示例          | 说明                              |
| ---- | ----------------- | --------------------------------- |
| 拼接 | s = s1 + s2;      | 直接用 + 拼接，无需 strcat        |
| 比较 | if (s1 == s2)     | 直接用 ==、>、< 比较，无需 strcmp |
| 取值 | char ch = s[0];   | 下标访问，与数组一致              |
| 赋值 | s = "new string"; | 直接赋值，自动管理内存            |

### string类常用成员函数
1. 求长度：`s.size()` 或 `s.length()`
  e.g.
  ```cpp
  std::string s = "Hello";
  int len = s.size(); // len = 5
  ```
2. 拼接：`s.append("xxx")`（补充拼接，等价于 +）
3. 查找：`s.find("xxx")`（查找子串，返回起始下标，找不到返回 string::npos）
4. 清空：`s.clear()`（清空字符串，变为空）
5. 截取子串：`s.substr(起始下标, 长度)`
  e.g.
  ```cpp
  std::string s = "Hello World";
  std::string sub = s.substr(0, 5); // sub = "Hello"
  ```

### C++ string 与 C 语言字符串（char*）的转换
1. string → char*
用c_str()成员函数，返回 const char*（只读，不可修改）
  e.g.
  ```cpp
  std::string s = "Hello";
  const char *p = s.c_str(); // 转换后指向字符串首地址
  ```

2. char* → string
直接赋值，自动转换（无需函数）
  e.g.
  ```cpp
  char *p = "Hello";
  std::string s = p; // 自动转换为string类型
  ```

### 其他神秘特性
#### 字符编码字符串 Character Encoded String
```cpp
const char* name = u8"Hello";//UTF-8字符串，英文占 1 字节，中文占 3 字节
const wchar_t* name2 = L"Hello";//每个字符占 2 字节（Windows）或 4 字节（Linux）
const char16_t* name3 = u"Hello";//每个字符固定 2 字节，16 bit
const char32_t* name4 = U"Hello"; //每个字符固定 4 字节，32 bit
```

#### 原始字符串字面量 Raw String Literal
转义符 `\` 不再必要,你输入什么就会保留什么，`\n`换行都不必要了
```cpp
const char example = R"Line1
                       Line2
                       Line3
                       Line4";
```
