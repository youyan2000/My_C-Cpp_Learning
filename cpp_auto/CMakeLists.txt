cmake_minimum_required(VERSION 3.11)

project("AutoDemo")

include_directories(./inc)

add_executable(autodemo 
               ./src/main.cpp
               ./src/student.cpp
               ./src/container_utils.cpp
)