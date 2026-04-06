#include <iostream>
#include "box.hpp"
#include "log.hpp"

using namespace std;

int main( ){
  Log log;
  log.SetLevel(log.INFO);
  log.Warn("This is a warning message.");
  log.Info("This is an info message.");
  log.Error("This is an error message.");

  BoxB Box1;        // declarate Box1，class is BoxB
  BoxB Box2;        // declarate Box2，class is BoxB
  BoxA Box3;        // declarate Box3，class is BoxA
  
  double volume = 0.0;     // save volume of box
 
  // describe box 1
  Box1.height = 5.0; 
  Box1.length = 6.0; 
  Box1.breadth = 7.0;
 
  // describe box 2
  Box2.height = 10.0;
  Box2.length = 12.0;
  Box2.breadth = 13.0;
 
  // volume of box 1
  volume = Box1.height * Box1.length * Box1.breadth;
  cout << "value of Box1 :" << volume <<endl;
 
  // volume of box 2
  volume = Box2.height * Box2.length * Box2.breadth;
  cout << "value of Box2 :" << volume <<endl;
 
  // describe box 3
  Box3.set(16.0, 8.0, 12.0); 
  volume = Box3.get(); 
  cout << "value of Box3 :" << volume <<endl;

  return 0;
}
