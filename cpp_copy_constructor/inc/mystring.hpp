#ifndef MYSTRING_HPP
#define MYSTRING_HPP

#include <iostream>
class MyString{
  private:
    char* m_Buffer;
    unsigned int m_Size;
  public:
    MyString(const char* string);
    friend std::ostream& operator<<(std::ostream& stream, const MyString& string);
    MyString(const MyString& other);
    ~MyString();
};

#endif
