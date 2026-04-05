#ifndef SPACE_H
#define SPACE_H
// Base Class
class Shape 
{
   public:
      void setWidth(int w);
      void setHeight(int h);
      Shape();
   protected:
      int width;
      int height;
};
 
// Derived Class
class Rectangle: public Shape
{
   public:
      Rectangle();
      int getArea();
};
#endif