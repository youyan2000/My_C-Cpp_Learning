#ifndef SPACE_H
#define SPACE_H

// Base Class
class Shape 
{
  public:
    void setWidth(int w);
    void setHeight(int h);
    virtual int getArea() = 0; // pure virtual function
    Shape();
  protected:
    int width;
    int height;
};
 
// Derived Class 1
class RightTriangle: public Shape
{
  public:
    RightTriangle();
    int getArea();
};

// Derived Class 2
class Rectangle: public Shape
{
  public:
    Rectangle();
    int getArea();
};

#endif