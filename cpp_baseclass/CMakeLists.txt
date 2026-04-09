cmake_minimum_required(VERSION 3.11)

project("SpaceClass")

include_directories(./inc)

add_executable(spaceclass 
               ./src/space.cpp
               ./src/main.cpp
)

