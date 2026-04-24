#include "student.hpp"
#include <iostream>

auto createStudent(int id, const std::string& name, double score) {
  return std::make_tuple(id, name, score);
}