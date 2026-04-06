#include <iostream>
#include "log.hpp"

void Log::SetLevel(int level) {
  m_Level = level;
}

void Log::Warn(const std::string& message) {
  if (m_Level >= WARNING) {
    std::cout << "Warning: " << message << std::endl;
  }
}

void Log::Info(const std::string& message) {
  if (m_Level >= INFO) {
    std::cout << "Info: " << message << std::endl;
  }
}

void Log::Error(const std::string& message) {
  if (m_Level >= ERROR) {
    std::cout << "Error: " << message << std::endl;
  }
}