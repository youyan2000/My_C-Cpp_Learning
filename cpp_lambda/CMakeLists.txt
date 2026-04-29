cmake_minimum_required(VERSION 3.10)
project(LambdaTest VERSION 1.0 LANGUAGES CXX)

# C++14 standard (supports generalized lambda capture)
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")

# Include directories
include_directories(${CMAKE_SOURCE_DIR}/inc)

# Source files
set(SOURCES
    src/main.cpp
    src/algorithms.cpp
)

# Header files
set(HEADERS
    inc/algorithms.h
)

# Executable
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

# Output directory
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)
