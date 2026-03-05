#include <iostream>
#include "maxvalue.hpp"

int main( )
{
   int a1=3, b1=9;
   std::cout << "Max value is : " << maxValue(a1,b1) << std::endl;
   float a2=3.5, b2=3.2;
   std::cout << "Max value is : " << maxValue(a2,b2) << std::endl;
   char a3='c', b3='d';
   std::cout << "Max value is : " << maxValue(a3,b3) << std::endl;
   return 0;
}
