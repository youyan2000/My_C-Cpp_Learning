#include "student.hpp"
#include "container_utils.hpp"
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <initializer_list>
#include <numeric>
#include <typeinfo>

int main() {
    std::cout << "========== `auto` Features Display ==========\n";

    // ========== 1. basic type deduction ==========
    auto i = 42;
    auto d = 3.14159;
    auto s = std::string("Hello auto");
    std::cout << "\n1. basic deduction: i=" << i << ", d=" << d << ", s=" << s << std::endl;

    // ========== 2. references and const qualifiers ==========
    int x = 100;
    const int cx = x;
    int& rx = x;
    auto a = cx;          // int
    auto& b = rx;         // int&
    const auto& c = cx;   // const int&
    b = 300;
    std::cout << "2. references/const: x=" << x << ", a=" << a << ", c=" << c << std::endl;

    // ========== 3. array decay and reference ==========
    int arr[5] = {1,2,3,4,5};
    auto ptr = arr;       // int*
    auto& ref = arr;      // int(&)[5]
    std::cout << "3. arrays: *ptr=" << *ptr << ", sizeof(ref)=" << sizeof(ref) << std::endl;

    // ========== 4. initializer list ==========
    auto initList = {10, 20, 30};
    int sum = std::accumulate(initList.begin(), initList.end(), 0);
    std::cout << "4. initializer_list sum: " << sum << std::endl;

    // ========== 5. lambda expression ==========
    auto square = [](int n) { return n * n; };
    std::cout << "5. lambda: 7^2 = " << square(7) << std::endl;

    // ========== 6. generic lambda (C++14) ==========
    auto add = [](auto a, auto b) { return a + b; };
    std::cout << "6. generic lambda: 3+4=" << add(3,4)
              << ", 2.5+1.7=" << add(2.5,1.7)
              << ", str+str=" << add(std::string("auto"), " demo") << std::endl;

    // ========== 7. structured bindings (C++17) ==========
    std::map<int, std::string> students = {{1, "Alice"}, {2, "Bob"}};
    std::cout << "7. structured bindings: ";
    for (const auto& [id, name] : students) {
        std::cout << "{" << id << ":" << name << "} ";
    }
    std::cout << std::endl;

    // ========== 8. function return auto ==========
    auto stu = createStudent(101, "Eve", 95.5);
    std::cout << "8. createStudent returns auto: ";
    printStudentInfo(stu);   // uses structured bindings internally

    // ========== 9. vector<bool> proxy trap ==========
    std::vector<bool> flags = {true, false, true};
    auto proxy = flags[0];   // std::vector<bool>::reference
    bool realFlag = flags[0];
    std::cout << "9. vector<bool> proxy: auto type is " << typeid(proxy).name()
              << ", prefer to receive with bool" << std::endl;

    // ========== 10. decltype(auto) example ==========
    std::vector<int> nums = {100, 200, 300};
    auto& firstElem = getFirstElement(nums);  // returns int&
    firstElem = 999;
    std::cout << "10. decltype(auto): nums[0] = " << nums[0] << std::endl;

    // ========== 11. container helper functions (from container_utils) ==========
    demonstrateAutoInContainers();

    // ========== 12. auto with complex pair combinations ==========
    std::vector<std::pair<char, double>> pairs = {{'A', 1.1}, {'B', 2.2}};
    std::cout << "\n12. complex pair iteration: ";
    for (auto& [ch, val] : pairs) {   // structured binding + auto&
        val += 0.5;
        std::cout << "(" << ch << "," << val << ") ";
    }
    std::cout << std::endl;

    std::cout << "\n========== The End ==========\n";
    return 0;
}