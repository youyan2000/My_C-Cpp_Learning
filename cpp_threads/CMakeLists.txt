cmake_minimum_required(VERSION 3.11)

project("WorkerThreads")

include_directories(./inc)

add_executable(workerthreads 
               ./src/worker.cpp
               ./src/main.cpp
)