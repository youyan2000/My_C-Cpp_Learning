#include <iostream>
#include <string>
#include "soldier.hpp"

Soldier::Soldier(std::string n) {
  name = n;
  // Increment total count each time a soldier is created
  // Note: this->total_count is not needed; access via class name is clearer
  total_count++;
  std::cout << name << " has enlisted. Current total: " << total_count << std::endl;
}

void Soldier::show_total() {
  // Cannot access 'name' here, as 'name' belongs to individual objects
  std::cout << "[System Message] Total soldiers in the unit: " << total_count << std::endl;
}

// 【IMPORTANT】Static member variables MUST be initialized outside the class
int Soldier::total_count = 0;

