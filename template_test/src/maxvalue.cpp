#include "maxvalue.hpp"

template<typename T>
T maxValue(T a, T b) {
    return (a > b) ? a : b;
}

//required types for explicit instantiation
template int maxValue<int>(int, int);
template float maxValue<float>(float, float);
template char maxValue<char>(char, char);
