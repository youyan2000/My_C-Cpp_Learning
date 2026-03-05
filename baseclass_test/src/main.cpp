#include <iostream>
#include "space.hpp"

using namespace std;

int main(void)
{
   Rectangle Rect;
 
   Rect.setWidth(5);
   Rect.setHeight(7);
 
   //Output the area of the object
   cout << "Total area: " << Rect.getArea() << endl;
 
   return 0;
}
