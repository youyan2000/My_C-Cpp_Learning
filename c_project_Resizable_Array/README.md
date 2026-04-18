# 可变数组 Resizable Array / Dynamic Array
## 项目简介

这是一个用**C语言**编写的学习项目，实现了一个**动态可调整大小的整数数组**数据结构。该项目演示了如何在C语言中手动管理内存，实现一个类似于动态数组（如C++中的`std::vector`）的功能。

## 项目目标

- 学习C语言中的内存管理（malloc、realloc、free）
- 理解数据结构的设计和实现
- 实现一个可以动态扩展的数组容器
- 掌握指针和结构体的使用

## 项目结构

```
c_project_Resizable_Array/
├── CMakeLists.txt              # CMake 构建配置文件
├── inc/
│   └── resizeable_array.h      # 数组接口定义（头文件）
├── src/
│   ├── main.c                  # 主程序和演示代码
│   └── resizeable_array.c      # 数组实现（核心逻辑）
└── build/                      # CMake 构建输出目录
```

## 核心数据结构
### Array 结构体

```c
typedef struct {
    int *array;    // 动态分配的整数数组指针
    int size;      // 当前数组中的元素个数
} Array;
```

该结构体包含两个成员：
- **array**：指向动态分配的整数数组的指针
- **size**：数组中当前存储的元素数量

## API 函数说明
### 1. `array_create(int init_size)`
- **功能**：创建一个新数组
- **参数**：`init_size` - 初始容量大小
- **返回值**：返回创建好的 Array 结构体
- **示例**：`Array arr = array_create(5);`

### 2. `array_append(Array *arr, int more_size)`
- **功能**：扩展数组容量（追加更多空位）
- **参数**：`arr` - 数组指针，`more_size` - 要增加的容量大小
- **返回值**：无
- **作用**：当数组满时调用此函数来扩展容量

### 3. `array_free(Array *arr)`
- **功能**：释放数组占用的所有内存
- **参数**：`arr` - 数组指针
- **返回值**：无
- **重要**：使用完数组后必须调用此函数以避免内存泄漏

### 4. `array_size(const Array *arr)`
- **功能**：获取数组中当前元素的个数
- **参数**：`arr` - 数组指针（常量指针，不会修改数组）
- **返回值**：当前元素个数（整数）

### 5. `array_at(Array *arr, int index)`
- **功能**：获取指定索引处元素的指针
- **参数**：`arr` - 数组指针，`index` - 元素索引
- **返回值**：返回指向该元素的 `int*` 指针
- **用途**：可用于读取或修改元素
- **示例**：`*array_at(&arr, 0) = 42;` 将第一个元素设置为42

### 6. `array_print(const Array *arr)`
- **功能**：打印数组中的所有元素
- **参数**：`arr` - 数组指针（常量指针）
- **返回值**：无

## 使用示例

[main.c](src/main.c) 中的演示程序展示了如何使用这个数组：

```c
int main(){
  // 1. 创建大小为5的数组
  Array arr = array_create(5);
  
  // 2. 获取数组大小
  printf("%d\n", array_size(&arr));  // 输出: 5
  
  // 3. 访问和修改元素
  *array_at(&arr, 0) = 42;
  printf("%d\n", *array_at(&arr, 0));  // 输出: 42
  
  // 4. 交互式添加元素
  int number = 0;
  int cnt = 0;
  printf("Now try to create your own array.\n");
  while (number != -1) {
    printf("Enter a number (-1 to stop): ");
    scanf("%d", &number);
    if (number != -1) {
      *array_at(&arr, cnt++) = number;
    }
  }
  
  // 5. 打印所有元素
  array_print(&arr);
  
  // 6. 释放内存
  array_free(&arr);
  return 0;
}
```

## 学习要点

1. **动态内存管理**：使用 `malloc()`、`realloc()` 和 `free()` 函数
2. **指针操作**：通过指针访问和修改数据
3. **结构体设计**：定义数据结构来封装相关数据
4. **函数接口**：设计清晰的 API 来操作数据结构
5. **内存扩展**：当数组满时如何重新分配内存并复制数据

