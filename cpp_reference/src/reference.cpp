#include <iostream>

#define print(x) std::cout << x << std::endl;

void Increment(int& value) {
  value++;
}

int main() {
  int a = 5;
  int& ref = a;
  int* ptr = &a;
  
  ref = 10;
  print(a);
  Increment(a);
  print(a);
  
  std::cin.get();
}