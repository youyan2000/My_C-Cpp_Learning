#include "container_utils.hpp"
#include <iostream>
#include <vector>
#include <map>
#include <string>

void demonstrateAutoInContainers() {
    std::cout << "\n--- demonstrateAutoInContainers() ---\n";

    std::vector<int> numbers = {10, 20, 30, 40};
    auto it = numbers.begin();   // std::vector<int>::iterator
    std::advance(it, 2);
    std::cout << "Iterator after +2: " << *it << std::endl;

    std::cout << "Modify via auto&: ";
    for (auto& val : numbers) {
        val *= 2;
        std::cout << val << " ";
    }
    std::cout << std::endl;

    std::map<int, std::string> idMap = {{1, "Apple"}, {2, "Banana"}, {3, "Cherry"}};
    std::cout << "Structured binding + auto: ";
    for (const auto& [id, name] : idMap) {
        std::cout << "(" << id << "," << name << ") ";
    }
    std::cout << std::endl;
}