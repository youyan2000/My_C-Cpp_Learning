cmake_minimum_required(VERSION 3.11)

project("Reference")

include_directories(./inc)

add_executable(reference
               ./src/reference.cpp
)