#include "maxvalue.hpp"

int main() {
  // Test function template (using explicitly instantiated int, float, char versions)
  std::cout << "=== Function Template ===" << std::endl;
  std::cout << "maxValue(3, 7)       = " << maxValue(3, 7) << std::endl;
  std::cout << "maxValue(3.14, 2.71) = " << maxValue(3.14f, 2.71f) << std::endl;
  std::cout << "maxValue('a', 'z')   = " << maxValue('a', 'z') << std::endl;

  // Test specialization version
  std::cout << "\n=== Template Specialization ===" << std::endl;
  std::cout << "maxValue(\"apple\", \"banana\") = " << maxValue("apple", "banana") << std::endl;

  // Test class template (defined in header file)
  std::cout << "\n=== Class Template + Non-type Parameter ===" << std::endl;
  StaticArray<int, 5> intArr;
  intArr.fill(42);
  std::cout << "intArr size = " << intArr.size() << ", element[2] = " << intArr.get(2) << std::endl;

  StaticArray<std::string, 3> strArr;
  strArr.fill("hello");
  std::cout << "strArr[1] = " << strArr.get(1) << std::endl;

  // Test variadic template (defined in header file)
  std::cout << "\n=== Variadic Template ===" << std::endl;
  std::cout << "printAll: ";
  printAll(1, 2.5, "hello", 'A');
  std::cout << std::endl;

  return 0;
}
