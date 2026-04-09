#include <iostream>
#include "space.hpp"

int main(void){
  RightTriangle Tri;
  Rectangle Rect;
 
  Tri.setWidth(5);
  Tri.setHeight(8);
  Rect.setWidth(5);
  Rect.setHeight(8);
 
  //Output the area of the object
  std::cout << "Total area: " << Tri.getArea() << std::endl;
  std::cout << "Total area: " << Rect.getArea() << std::endl;

  return 0;
}
