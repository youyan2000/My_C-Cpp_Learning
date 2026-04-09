#include "space.hpp"

Shape::Shape(){
  width = 0;
  height = 0;
}
RightTriangle::RightTriangle(){
  width = 0;
  height = 0;
}
Rectangle::Rectangle(){
  width = 0;
  height = 0;
}

void Shape::setWidth(int w){
  width = w;
}
void Shape::setHeight(int h){
  height = h;
}

int RightTriangle::getArea(){ 
  return (width * height * 0.5); 
}
int Rectangle::getArea(){
  return (width * height);
}
