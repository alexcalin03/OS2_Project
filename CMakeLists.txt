cmake_minimum_required(VERSION 3.10)
project(OS2_Project)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

add_executable(OS2_Project
    src/main.cpp
    src/matrix.cpp
)
