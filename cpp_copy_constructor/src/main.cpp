#include <iostream>
#include <string>
#include "mystring.hpp"

int main() {
  MyString str1 = "Hello, World!";
  MyString str2 = str1; // This will invoke the copy constructor

  std::cout << str1 << std::endl;
  std::cout << str2 << std::endl;
  
  return 0;
}