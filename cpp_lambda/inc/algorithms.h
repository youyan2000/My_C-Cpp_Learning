#ifndef ALGORITHMS_H
#define ALGORITHMS_H

#include <vector>
#include <functional>

namespace algo {

// Apply a function to each element
void ForEach(const std::vector<int>& values, std::function<void(int)> func);

// Transform elements using a unary function
std::vector<int> Transform(const std::vector<int>& values, std::function<int(int)> func);

// Filter elements using a predicate
std::vector<int> Filter(const std::vector<int>& values, std::function<bool(int)> predicate);

// Count elements matching a predicate
int CountIf(const std::vector<int>& values, std::function<bool(int)> predicate);

// Find if any element matches predicate
bool AnyOf(const std::vector<int>& values, std::function<bool(int)> predicate);

} // namespace algo

#endif // ALGORITHMS_H
