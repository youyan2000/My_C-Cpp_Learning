#ifndef MAXVALUE_H
#define MAXVALUE_H

#include <iostream>
#include <cstring>
#include <string>

// ---------- 1. Function template declaration (defined in .cpp via explicit instantiation) ----------
template<typename T>
T maxValue(T a, T b);

// Specialization declaration (defined in .cpp)
template<>
const char* maxValue<const char*>(const char* a, const char* b);

// ---------- 2. Class template (definition must be in header file, as it cannot be separated for compilation) ----------
template<typename T, int SIZE>
class StaticArray {
  private:
    T arr[SIZE];
  public:
    void fill(const T& val) {
      for (int i = 0; i < SIZE; ++i) arr[i] = val;
    }
    T get(int index) const { return arr[index]; }
    int size() const { return SIZE; }
};

// ---------- 3. Variadic template (definition must be in header file) ----------
void printAll() {}  // Recursive termination

template<typename First, typename... Rest>
void printAll(First first, Rest... rest) {
  std::cout << first;
  if constexpr (sizeof...(rest) > 0)
    std::cout << ", ";
  printAll(rest...);
}

#endif