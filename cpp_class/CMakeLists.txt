cmake_minimum_required(VERSION 3.11)

project("BoxClass")

include_directories(./inc)

add_executable(boxclass 
               ./src/box.cpp
               ./src/log.cpp
               ./src/main.cpp
               ./src/soldier.cpp

)

# project("SoldierClass")

# include_directories(./inc)

# add_executable(soldierclass 
#                ./src/soldier.cpp
#                ./src/main.cpp
# )
