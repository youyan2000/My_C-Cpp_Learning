#include "space.hpp"

int Rectangle::getArea(){ 
      return (width * height); 
   }
void Shape::setWidth(int w){
      width = w;
   }
void Shape::setHeight(int h){
      height = h;
   }
Rectangle::Rectangle(){
      width = 0;
      height = 0;
   }
Shape::Shape(){
      width = 0;
      height = 0;
   }