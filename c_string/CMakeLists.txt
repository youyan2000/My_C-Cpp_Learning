cmake_minimum_required(VERSION 3.11)

project("String")

include_directories(./inc)

add_executable(StringTest
               ./src/string_functions.c 
)