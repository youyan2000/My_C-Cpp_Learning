cmake_minimum_required(VERSION 3.11)

project("ComplexNumber")

include_directories(./inc)

add_executable(complexnumber 
               ./src/main.cpp 
               ./src/complex.cpp
)