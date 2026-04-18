cmake_minimum_required(VERSION 3.11)

project("CopyString")

include_directories(./inc)

add_executable(copystring 
               ./src/mystring.cpp 
               ./src/main.cpp
)