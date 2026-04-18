#include <iostream>
#include <cstring>
#include "mystring.hpp"

MyString::MyString(const char* string){
  m_Size = strlen(string);
  m_Buffer = new char[m_Size + 1];
  memcpy(m_Buffer, string, m_Size);
  m_Buffer[m_Size] = 0;
}

std::ostream& operator<<(std::ostream& stream, const MyString& string) {
  stream << string.m_Buffer;
  return stream;
}

MyString::~MyString() {
  delete[] m_Buffer;
}

MyString::MyString(const MyString& other)
    : m_Size(other.m_Size){
  m_Buffer = new char[m_Size + 1];
  memcpy(m_Buffer, other.m_Buffer, m_Size+1);
}
