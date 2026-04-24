#ifndef STUDENT_HPP
#define STUDENT_HPP

#include <string>
#include <tuple>

auto createStudent(int id, const std::string& name, double score);

template<typename T>
void printStudentInfo(const T& studentTuple) {
  const auto& [id, name, score] = studentTuple;
  std::cout << "ID: " << id << ", Name: " << name << ", Score: " << score << std::endl;
}

#endif