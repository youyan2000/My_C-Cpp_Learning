#include <iostream>
#include <vector>
#include <algorithm>
#include <memory>
#include "algorithms.h"

int main() {
    std::cout << "=== C++ Lambda 示例项目 ===\n\n";

    // ============================================================
    // 1. 基本 Lambda 语法
    // ============================================================
    std::cout << "1. 基本 Lambda 语法:\n";
    std::vector<int> values = {1, 4, 5, 2, 3};

    // 简单 lambda
    auto print = [](int v) { std::cout << "  Value: " << v << "\n"; };
    algo::ForEach(values, print);

    // 内联 lambda
    std::cout << "\n  内联 lambda: ";
    algo::ForEach(values, [](int v) { std::cout << v << " "; });
    std::cout << "\n";

    // ============================================================
    // 2. 值捕获 vs 引用捕获
    // ============================================================
    std::cout << "\n2. 捕获列表演示:\n";
    int x = 10, y = 20;

    // 值捕获 - 不影响原变量
    auto by_value = [x, y]() {
        std::cout << "  值捕获：x=" << x << ", y=" << y << "\n";
        return x + y;
    };
    by_value();
    std::cout << "  调用后原变量：x=" << x << ", y=" << y << "\n";

    // 引用捕获 - 影响原变量
    auto by_ref = [&x, &y]() {
        x++; y++;
        std::cout << "  引用捕获：x=" << x << ", y=" << y << "\n";
    };
    by_ref();
    std::cout << "  调用后原变量：x=" << x << ", y=" << y << "\n";

    // ============================================================
    // 3. 隐式捕获
    // ============================================================
    std::cout << "\n3. 隐式捕获:\n";
    int a = 5, b = 10;

    auto all_by_value = [=]() {
        std::cout << "  全部值捕获 [=]: a+b=" << a + b << "\n";
    };

    auto all_by_ref = [&]() {
        std::cout << "  全部引用捕获 [&]: ";
        a += b;
        std::cout << "a=" << a << "\n";
    };

    all_by_value();
    all_by_ref();

    // ============================================================
    // 4. 混合捕获
    // ============================================================
    std::cout << "\n4. 混合捕获:\n";
    int m = 3, n = 7;

    auto mixed = [=, &n]() {
        // m 值捕获，n 引用捕获
        n *= 2;
        std::cout << "  [=, &n]: m=" << m << "(未变), n=" << n << "(已变)\n";
    };
    mixed();

    // ============================================================
    // 5. Lambda 与算法结合
    // ============================================================
    std::cout << "\n5. Lambda 与算法:\n";
    std::vector<int> nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // Transform: 平方
    auto squared = algo::Transform(nums, [](int v) { return v * v; });
    std::cout << "  平方：";
    for (int v : squared) std::cout << v << " ";
    std::cout << "\n";

    // Filter: 偶数
    auto evens = algo::Filter(nums, [](int v) { return v % 2 == 0; });
    std::cout << "  偶数：";
    for (int v : evens) std::cout << v << " ";
    std::cout << "\n";

    // CountIf: 大于 5 的个数
    int count = algo::CountIf(nums, [](int v) { return v > 5; });
    std::cout << "  大于 5 的个数：" << count << "\n";

    // AnyOf: 是否存在大于 8 的数
    bool exists = algo::AnyOf(nums, [](int v) { return v > 8; });
    std::cout << "  是否存在大于 8 的数：" << (exists ? "是" : "否") << "\n";

    // ============================================================
    // 6. C++14 广义捕获 (std::unique_ptr)
    // ============================================================
    std::cout << "\n6. C++14 广义捕获:\n";
    auto unique_capture = [value = std::make_unique<int>(42)]() {
        std::cout << "  unique_ptr 捕获：*value=" << *value << "\n";
        return *value;
    };
    unique_capture();

    // ============================================================
    // 7. 可变 Lambda (mutable)
    // ============================================================
    std::cout << "\n7. 可变 Lambda (mutable):\n";
    int counter = 0;
    auto mutable_lambda = [counter]() mutable {
        counter++;
        std::cout << "  mutable lambda 内部计数：" << counter << "\n";
    };
    mutable_lambda(); // 1
    mutable_lambda(); // 2
    std::cout << "  外部 counter：" << counter << "\n"; // 0 (未变)

    std::cout << "\n=== 演示完成 ===\n";
    return 0;
}
