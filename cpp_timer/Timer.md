1. 引入库
#include <chrono>
std::chrono::high_resolution_clock：高精度计时。
std::chrono::steady_clock：单调递增，不受系统时间调整影响。
std::chrono::duration：时间段。
2. 基本用法
auto start = std::chrono::high_resolution_clock::now();
// 代码块
auto end = std::chrono::high_resolution_clock::now();
auto duration = end - start;
std::cout << "Time: " << std::chrono::duration_cast<std::chrono::milliseconds>(duration).count() << "ms\n";
duration_cast 可转换为毫秒、微秒、秒等。
3. RAII Timer（推荐写法）
struct Timer {
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
    Timer() { start = std::chrono::high_resolution_clock::now(); }
    ~Timer() {
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "Elapsed: " << duration << "ms\n";
    }
};
优点：
自动记录开始和结束时间。
函数结束或代码块结束自动输出。
4. 使用场景

性能分析：

{
    Timer timer;
    // 耗时操作
} // 自动输出耗时
测试不同算法效率。
调试代码段执行速度。
5. 小技巧
可以把 Timer 改成模板支持不同单位：
template<typename TimeT = std::chrono::milliseconds>
struct Timer {
    std::chrono::time_point<std::chrono::high_resolution_clock> start;
    Timer() { start = std::chrono::high_resolution_clock::now(); }
    ~Timer() {
        auto end = std::chrono::high_resolution_clock::now();
        auto duration = std::chrono::duration_cast<TimeT>(end - start).count();
        std::cout << "Elapsed: " << duration << "\n";
    }
};
支持秒、微秒、纳秒：
Timer<std::chrono::microseconds> t;