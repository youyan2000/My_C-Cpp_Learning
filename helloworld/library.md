# 库 Library
## **静态库 Static Library** 与 **动态库 Dynamic Library**
库一般分静态库和动态库

静态库在编译链接时与可执行文件合为一体
直接装载到内存, 更占用内存资源, 但执行速度快

动态库单独作为文件供可执行文件调用
可以在用到的时候被连接装载到内存中, 且可以被多个不同的程序调用
也可以在程序运行时加载
因此节省资源, 但调用需要一定的装载时间

## 库的使用
要成功地在一个项目里面使用一个库，就是在项目里面调用库的函数，我们要确保两件事：
- 编译成功
- 链接成功

### 编译
要编译成功，我们只需要include库的头文件，在`CMakeLists.txt`里我们可以加入这样一行：
```cmake
include_directories(<库的头文件的目录>)
```

### 链接
要链接成功，我们有两种链接方式

#### 静态链接
对于静态连接，我们需要连接**静态库文件 Static Library File**（Windows 下为 .lib，Linux 下为 .a）

在`CMakeLists.txt`里我们可以加入这样一行：
```cmake
# 方法一：直接指定目标链接的库
target_link_libraries(<你的可执行目标名称> <库的名称或路径>)
# 示例：
# target_link_libraries(my_app my_library)

# 方法二：如果库文件不在默认搜索路径中，通常还需要指定库文件目录
link_directories(<库文件所在的目录>)
target_link_libraries(<你的目标> <库名>)
```

#### 动态链接
对于动态连接，我们需要连接**导入库文件 Import Library File**（Windows 下为 .lib，Linux 下通常直接使用 .so 本身）(导入库文件里面放着一堆指向动态库文件的指针)
同时，需要将**动态库文件 Dynamic Library File**（Windows 下为 .dll，Linux 下为 .so）放置到可执行文件能找到的位置（一般为同一目录或系统`PATH/LD_LIBRARY_PATH`中）

在`CMakeLists.txt`中，动态链接的配置与静态链接类似，仍使用`target_link_libraries`
同时，为了保证运行时能正确加载动态库，可以设置 **运行时库搜索路径 Runtime Library Search Path, RPATH** 或自动拷贝 dll 文件
例如
```cmake
target_link_libraries(<你的可执行目标名称> <库名或导入库路径>)
# 例如：
# target_link_libraries(my_app my_shared_lib)
```

## 常见扩展名
- Windows系统
  - 静态库: .lib, Library
  - 动态库: .dll, Dynamic Link Library
- Linux系统
  - 静态库: .a, Archive
  - 动态库: .so, Shared Object
