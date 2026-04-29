#include "algorithms.h"

namespace algo {

void ForEach(const std::vector<int>& values, std::function<void(int)> func) {
    for (int value : values) {
        func(value);
    }
}

std::vector<int> Transform(const std::vector<int>& values, std::function<int(int)> func) {
    std::vector<int> result;
    result.reserve(values.size());
    for (int value : values) {
        result.push_back(func(value));
    }
    return result;
}

std::vector<int> Filter(const std::vector<int>& values, std::function<bool(int)> predicate) {
    std::vector<int> result;
    for (int value : values) {
        if (predicate(value)) {
            result.push_back(value);
        }
    }
    return result;
}

int CountIf(const std::vector<int>& values, std::function<bool(int)> predicate) {
    int count = 0;
    for (int value : values) {
        if (predicate(value)) {
            count++;
        }
    }
    return count;
}

bool AnyOf(const std::vector<int>& values, std::function<bool(int)> predicate) {
    for (int value : values) {
        if (predicate(value)) {
            return true;
        }
    }
    return false;
}

} // namespace algo
