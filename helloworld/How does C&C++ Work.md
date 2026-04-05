# 编译原理基础

## 编译/链接流程
```mermaid
flowchart LR
    SRC[.c/.cpp 源文件]
    HDR[.h/.hpp 头文件]

    subgraph COMPILER [编译器 gcc/clang]
        direction TB
        PRE[预处理<br/>#include 宏展开]
        COMP[编译<br/>生成汇编]
        ASM[汇编<br/>生成机器码]
    end

    OBJ[.o/.obj 目标文件]

    subgraph LINKER [链接器 ld/lld]
        LINK[符号解析<br/>重定位]
    end

    EXE[.exe/.out/.elf 可执行文件]

    SRC --> PRE
    HDR -->|#include 展开合并| PRE
    PRE --> COMP --> ASM --> OBJ
    OBJ --> LINK --> EXE
```

## 编译(complier)

### 预处理
`# include <>` : 将<>中的文件直接粘贴到指定位置
`# define A b` : 将所有的b用A替换
### 编译
生成`.asm`汇编文件，操作寄存器
调用函数：`call signature of funcation`signature of funcations是函数的签名，看起来是一串乱码。
### 汇编
生成`.obj`机器二进制语言

## 链接(linker)
### *报错*
编译阶段报错：C
链接阶段报错：LINK
### 选择函数入口
通常默认是main()函数
### 读取函数声明
- 函数的 **声明(declaration)** 需要和函数的 **定义(definition)** 相同的名字
- static函数可以仅在单个.c文件中生存
- 在同一.c文件中不要反复声明/定义（要当心include的.h文件）
理论上，声明必须出现在.h中；定义决不能出现在.c中

## GNU(GNU's Not Unix) C/C++ Compiler

GCC是自由软件运动组织GNU的一个子项目, 是C编译器工具, 是GNU C Compiler的缩写；用于编译C和C++文件。

### gcc/g++编译

```bash
# <output_file>为输出的可执行文件或库文件
# <source_file>即为C语言代码文件, 或者编译中间产生的中间文件, 或者库文件
gcc -o <output_file.exe> <source_file.c>
g++ -o <output_file.exe> <source_file.cpp>

# lstdc++ 本质上并非库文件, 实际上是个配置选项, 代表链接时加入C++的库文件
gcc -o <output_file.exe> <source_file.c> -lstdc++
```

**E.G.**
```bash
gcc -o HelloWorld.exe HelloWorld-c.c
g++ -o HelloWorld.exe HelloWorld-cpp.cpp
gcc -o HelloWorld.exe HelloWorld-c.c -lstdc++
```
**库文件小科普**
- 库一般分静态库和动态库. 静态库在编译链接时与可执行文件合为一体, 动态库单独作为文件供可执行文件调用
  - 静态库直接装载到内存, 更占用内存资源, 但执行速度快
  - 动态库只有在用到的时候被装载到内存中, 且可以被多个不同的
程序调用. 因此节省资源, 但调用需要一定的装载时间
- 常见扩展名
  - Windows系统
    - 静态库: .lib, Library
    - 动态库: .dll, Dynamic Link Library
  - Linux系统
    - 静态库: .a, Archive
    - 动态库: .so, Shared Object

### 单个可执行文件的逐步生成

```bash
# -c为compile的缩写, 表示我们仅作编译生成目标文件, 不进行链接与生成可执行文件
gcc -o <output_file.o> -c <source_file.c>
# 该指令将目标文件链接成最终的可执行文件
gcc -o <output_file.exe> <output_file.o>
```

**E.G.**
```bash
gcc -o HelloWorld.o -c HelloWorld.c
gcc -o HelloWorld.exe HelloWorld.o
```

### 多个c文件联合生成可执行文件

```bash
gcc -o <output_file_1.o> -c <source_file_1.c>
gcc -o <output_file_2.o> -c <source_file_2.c>
gcc -o <output_file.exe> <output_file_1.o> <output_file_2.o>
```
一句话实现
```bash
# -o紧跟着的是输出的可执行文件名, 后面剩余的都是所依赖的源码文件或库文件或中间文件
gcc -o <output_file.exe> <source_file_1.c> <source_file_2.c>
```

**E.G.**
```bash
gcc -o HelloWorld.exe HelloWorld.c function.c
```

### 多个c/cpp文件联合生成可执行文件

```bash
gcc -o <output_file_1.o> -c <source_file_1.c>
g++ -o <output_file_2.o> -c <source_file_2.cpp>
gcc -o <output_file.exe> <output_file_1.o> <output_file_2.o> -lstdc++
```
一句话实现
```bash
gcc -o <output_file.exe> <source_file_1.c> <source_file_2.cpp> -lstdc++
```

**E.G.**
```bash
gcc -o test.exe test.c function.1 cpp -lstdc++
```

## Make和CMake
Make和CMake是C/C++项目构建工具。
Make根据`makefile`文件来编译C和C++文件并生成可执行文件。
CMake根据根据`CMakeLists.txt`文件来构建`makefile`文件, 进而根据`makefile`文件来编译C和C++文件并生成可执行文件文件。

下方为常见的`makefile`文件内容：
```makefile
# <demo_name>即为项目名, 用于指示一个项目
# <dependency>为依赖项, 可以是其他的项目名, 也可以是一个或多个文件. 不同文件之间需要用空格隔开
# <related_instructions>为指令名, 是一条或多条gcc等指令
# 该内容可存在多个
<demo_name>: <dependency>
    <related_instructions>
```

下方为常见的`make`指令：
```bash
# 按照<demo_name>的指令与配置, 编译并输出可执行文件
# 执行该指令时, make会自动寻找该路径下的makefile文件
# <demo_name>即为项目名, 用于指示一个项目
# 若make后不跟任何<demo_name>, 则默认是第一个<demo_name>
make <demo_name>
```

下方为常见的`CMakeLists.txt`：
```yaml
# CMake所需的最低版本
cmake_minimum_required(VERSION 3.11)
#项目名称
project("demo_name")
#添加xxx.hpp所在的文件夹（如果是当前文件夹可以不用添加）
include_directories(./inc)
#手动添加需要的源文件，定义可执行文件
add_executable(<demo_name> ./src/<demo_name> ./src/<demo_name>)
```

下方为常见的`cmake`指令：
```bash
# cmake在此文件夹下寻找CMakeLists.txt，并建立build文件夹
cmake -B build
# make在build文件夹下，并运行makefile
make -C build
# 在build文件夹下运行<demo_name>
build/<demo_name>
```

`aux_source_directory`函数：获取某一目录下的全部源文件
用了`aux_source_directory`的`CMakeLists.txt`：
```yaml
cmake_minimum_required(VERSION 3.11)
project(<demo_name>)
include_directories(./inc)
aux_source_directory(./src SRCS)
add_executable(<demo_name> ${SRCS})
```

**E.G.**
```makefile
# 生成所有项目
all: demo_1 demo_2 demo_3 demo_4
# 1对应的项目
demo_1: ./1_test_c/test.c
    gcc -o ./1_test_c/test.exe ./1_test_c/test.c
# 2对应的项目
demo_2: ./2_test_cpp/test.cpp
    g++ -o ./2_test_cpp/test.exe
./2_test_cpp/test.cpp
# 3.1对应的项目
demo_1_step: ./1_test_c/test.c
    gcc -o test.o -c test.c
    gcc -o test.exe test.o
# 3对应的项目
demo_3: ./3_test_multi_c/test.c
./3_test_multi_c/function.c
    gcc -o ./3_test_multi_c/test.exe
./3_test_multi_c/test.c
./3_test_multi_c/function.c
# 4对应的项目
demo_4: ./4_test_multi_c_cpp/test.c
./4_test_multi_c_cpp/function.cpp
    g++ -o ./4_test_multi_c_cpp/test.exe
./4_test_multi_c_cpp/test.c
./4_test_multi_c_cpp/function.cpp
# 删除编译中间文件
clean_o:
    del /s *.o
# 删除所有编译生成文件
clean:
    del /s *.o
    del /s *.exe
```

```bash
# 生成test_c.exe
make demo_1
# 生成test_cpp.exe
make demo_2
# 生成test_c.exe和test_cpp.exe
# 也可以直接make
make all
```
