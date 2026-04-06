cmake_minimum_required(VERSION 3.11)

project("BoxClass")

include_directories(./inc)

add_executable(boxclass 
               ./src/box.cpp
               ./src/log.cpp
               ./src/main.cpp
)