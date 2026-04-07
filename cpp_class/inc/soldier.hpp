#ifndef SOLDIER_H
#define SOLDIER_H

#include <string>
#include <iostream>

class Soldier {
public:
  std::string name;
  
  // Static member variable: belongs to the class, not a specific soldier
  // Used to track the total number of soldiers
  static int total_count; 

  Soldier(std::string n);

  // Static member function: can only access static member variables
  static void show_total();
};
#endif
