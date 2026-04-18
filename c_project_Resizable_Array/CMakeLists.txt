cmake_minimum_required(VERSION 3.11)

project("Resizeable Array")

include_directories(./inc)

add_executable(resizeable_array 
               ./src/resizeable_array.c 
               ./src/main.c
)