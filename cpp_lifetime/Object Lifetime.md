# 对象生存期 Object Lifetime

对象生存期指对象从创建到销毁的整个过程。C++ 中有多种不同的生存期类型。

## 1. 静态生存期 Static Storage Duration

### 特点
- 在程序启动时创建，程序结束时销毁
- 只初始化一次

### 包括
- 全局变量
- 静态全局变量
- 静态局部变量
- 类的静态成员

### 示例代码
```cpp
#include <iostream>
using namespace std;

int global_var = 100;  // 全局变量，静态生存期

class MyClass {
public:
    static int static_member;  // 静态成员声明
};
int MyClass::static_member = 200;  // 定义，静态生存期

void function() {
    static int static_local = 0;  // 静态局部变量，只初始化一次
    static_local++;
    cout << "Static local: " << static_local << endl;
}

int main() {
    function();  // 输出: 1
    function();  // 输出: 2
    function();  // 输出: 3
    
    cout << "Global: " << global_var << endl;      // 100
    cout << "Static member: " << MyClass::static_member << endl;  // 200
}
```

## 2. 线程局部生存期  Thread Local Storage Duration

### 特点
- C++11 引入
- 每个线程有自己的实例
- 线程开始时创建，线程结束时销毁

### 示例代码
```cpp
#include <iostream>
#include <thread>
#include <vector>

thread_local int thread_local_var = 0;  // 每个线程独立

void thread_function(int id) {
    thread_local_var = id;
    cout << "Thread " << id << ": " << thread_local_var << endl;
    // 每个线程有自己的 thread_local_var 副本
}

int main() {
    thread t1(thread_function, 1);
    thread t2(thread_function, 2);
    
    t1.join();
    t2.join();
}
```

## 3. 自动生存期  Automatic Storage Duration

### 特点
- **最常见**的类型
- 在进入作用域时创建，离开作用域时自动销毁
- 存储在栈上

### 示例代码
```cpp
void function() {
    int local = 10;        // 自动生存期
    double d = 3.14;       // 自动生存期
    string str = "hello";  // 自动生存期
    
    {
        int inner = 20;    // 进入时创建
        // inner 在这里有效
    }  // 离开时销毁 inner
    
    // inner 在这里已经不存在
}  // local, d, str 在这里销毁
```

### 栈的自动管理示例
```cpp
class Trace {
private:
    string name;
public:
    Trace(string n) : name(n) {
        cout << "创建: " << name << endl;
    }
    ~Trace() {
        cout << "销毁: " << name << endl;
    }
};

void function() {
    Trace t1("t1");        // 进入时创建
    {
        Trace t2("t2");    // 进入内层时创建
        Trace t3("t3");
    }  // t2, t3 离开内层时销毁（顺序：t3 先，t2 后）
    
    Trace t4("t4");
}  // t4, t1 离开函数时销毁（顺序：t4 先，t1 后）

int main() {
    cout << "进入 main" << endl;
    function();
    cout << "离开 main" << endl;
}
```

**输出：**
```
进入 main
创建: t1
创建: t2
创建: t3
销毁: t3
销毁: t2
创建: t4
销毁: t4
销毁: t1
离开 main
```

## 4. 动态生存期 (Dynamic Storage Duration)

### 特点
- 手动管理（new/delete 或 malloc/free）
- 存储在堆上
- 程序员负责销毁

### 裸指针管理
```cpp
int main() {
    // 动态分配
    int* p = new int(42);
    MyClass* obj = new MyClass();
    
    // 使用对象
    cout << *p << endl;
    obj->function();
    
    // 必须手动释放
    delete p;
    delete obj;
    
    // 数组动态分配
    int* arr = new int[10];
    delete[] arr;  // 数组要用 delete[]
    
    return 0;
}  // 如果不 delete，对象永远不会销毁（内存泄漏）
```

### 智能指针（现代 C++ 推荐）
智能指针本质上就是裸指针的包装结果，是 C++11 引入的 RAII（资源获取即初始化）工具，用于自动管理动态内存，避免内存泄漏和悬空指针，你需要include <memory>
`unique_ptr`与裸指针大小相同（8 字节），无额外性能损失
`shared_ptr`为两个指针的大小：一个指向对象，一个指向控制块
```cpp
#include <memory>

int main() {
  // unique_ptr - 独占所有权(同一时刻只有一个 unique_ptr 指向对象)
  unique_ptr<int> uptr(new int(10));
  
  // shared_ptr - 共享所有权(同一时刻可以有多个不同名的 unique_ptr 指向对象)
  shared_ptr<int> sptr1(new int(20));
  shared_ptr<int> sptr2 = sptr1;  // 引用计数增加
  
  // weak_ptr - 弱引用
  weak_ptr<int> wptr = sptr1;
  
  // 不需要手动 delete，智能指针自动管理
  return 0;
}  // 智能指针自动释放内存
```

## 5. 临时对象生存期 (Temporary Object Lifetime)

### 特点
- 表达式求值时创建
- 通常到完整表达式结束时销毁

### 示例代码
```cpp
class Temp {
public:
    Temp() { cout << "创建临时对象" << endl; }
    ~Temp() { cout << "销毁临时对象" << endl; }
    int getValue() { return 42; }
};

int main() {
    // 临时对象在表达式结束时销毁
    int result = Temp().getValue();  
    // 创建临时 -> 调用 getValue -> 销毁临时
    
    // const 引用可以延长临时对象生存期
    const Temp& ref = Temp();  
    // 临时对象生存期延长到引用销毁时
    cout << "使用临时对象" << endl;
    
    return 0;
}  // ref 销毁时临时对象才销毁
```

## 生存期对比表

| 类型 | 创建时机 | 销毁时机 | 存储位置 | 关键字 |
|------|---------|---------|---------|--------|
| 静态 | 程序启动 | 程序结束 | 静态存储区 | `static` |
| 线程局部 | 线程启动 | 线程结束 | 线程局部存储 | `thread_local` |
| 自动 | 进入作用域 | 离开作用域 | 栈 | 无（局部变量） |
| 动态 | `new`/`malloc` | `delete`/`free` | 堆 | `new`/`delete` |

## 常见陷阱和最佳实践

### 陷阱 1：返回局部变量的引用/指针
```cpp
int& bad_function() {
    int local = 10;
    return local;  // 错误！返回局部变量的引用
}  // local 销毁，引用悬空

int* also_bad() {
    int local = 20;
    return &local;  // 错误！返回局部变量的指针
}
```

### 陷阱 2：忘记释放动态内存
```cpp
void memory_leak() {
    int* p = new int[1000];
    // 忘记 delete，内存泄漏
}  // p 销毁，但堆内存还在
```

## 总结

- **自动生存期**：最常用，最安全，优先使用
- **静态生存期**：全局状态，谨慎使用
- **动态生存期**：灵活但危险，用智能指针代替裸指针
- **线程局部**：多线程场景下的特殊需求
- **原则**：能用栈就不用堆，能用智能指针就不用裸指针
```

