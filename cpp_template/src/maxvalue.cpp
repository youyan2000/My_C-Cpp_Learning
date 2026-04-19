#include "maxvalue.hpp"

// ---------- Function template definition ----------
template<typename T>
T maxValue(T a, T b) {
    return (a > b) ? a : b;
}

// ---------- Specialization definition ----------
template<>
const char* maxValue<const char*>(const char* a, const char* b) {
    return (std::strcmp(a, b) > 0) ? a : b;
}

// ---------- Explicit instantiation (tells the compiler to generate code for the following types) ----------
template int maxValue<int>(int, int);
template float maxValue<float>(float, float);
template char maxValue<char>(char, char);

// If you need to support double, uncomment the line below
// template double maxValue<double>(double, double);

