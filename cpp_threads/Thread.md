# Thread 线程

线程（Thread）是操作系统调度的最小执行单元。一个程序可以包含多个线程，它们共享同一块内存（全局变量、堆空间），但有各自的执行栈和寄存器状态
C++11 引入了 `<thread>` 标准库，让你可以方便地创建和管理线程，而不依赖平台特定的 API（如 Windows 的 `CreateThread` 或 POSIX 的 `pthread`）

## 基本使用
### 引入头文件
```cpp
#include <thread>
#include <iostream>
```

### 创建线程`std::thread t()`
`()`内可以填入函数指针、lambda 表达式或函数对象（Functor）来启动
* `std::thread t(func, args...)`
  创建一个新线程，立即执行 `func(args...)`。
* `t.join()`
  等待线程执行完毕（阻塞调用线程，通常是主线程）。

比方说：
```cpp
void task(int n) {
  std::cout << "Hello from thread! n = " << n << std::endl;
}
int main() {
  std::thread t(task, 5); // 创建线程，执行 task(5)
  t.join(); // 等待线程结束
  return 0;
}
```
* **注意**：如果线程对象销毁前没有 `join()` 或 `detach()`，程序会 `std::terminate`。


### `detach` 与 `join`
- **`join`**：主线程等待子线程结束。
- **`detach`**：子线程独立执行，主线程不等待。线程结束后系统会回收资源。

```cpp
std::thread t(task, 10);
t.detach(); // 子线程独立运行
```
* **注意**：detach 后，你无法再控制或获取线程返回值，必须确保线程运行期间相关数据不会被销毁，否则会产生 **悬空引用**。

---

## Lambda 与线程

用 lambda 表达式可以让线程定义更灵活：

```cpp
std::thread t([](int x){
    std::cout << "Lambda thread: " << x << std::endl;
}, 42);

t.join();
```

---

## 多线程共享数据

因为线程共享内存，访问共享数据时要小心 **数据竞争（race condition）**。

### **示例**

```cpp
#include <mutex>
#include <vector>

std::mutex mtx; // 互斥量
int counter = 0;

void increment() {
    for (int i = 0; i < 1000; ++i) {
        std::lock_guard<std::mutex> lock(mtx); // 自动上锁
        counter++;
    }
}

int main() {
    std::thread t1(increment);
    std::thread t2(increment);

    t1.join();
    t2.join();

    std::cout << "Counter = " << counter << std::endl; // 输出 2000
}
```

* `std::mutex` 用于保护共享资源。
* `std::lock_guard` RAII 风格自动加锁解锁。

---

## **5. 注意事项**

1. **线程对象生命周期**：必须 `join()` 或 `detach()`。
2. **数据共享与同步**：访问共享数据必须加锁，否则可能出现数据竞争。
3. **异常安全**：线程函数抛出异常，如果没有捕获，可能导致程序终止。
4. **线程数量**：过多线程会带来上下文切换开销，通常根据硬件线程数控制。

```cpp
#include <thread>
std::cout << std::thread::hardware_concurrency(); // 获取硬件支持的线程数
```
