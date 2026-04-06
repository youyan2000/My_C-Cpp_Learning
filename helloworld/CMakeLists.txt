cmake_minimum_required(VERSION 3.11)

project("HelloWorld")

include_directories(./inc)

add_executable(helloworld 
               ./src/HelloWorld.c 
               ./src/function.c
)