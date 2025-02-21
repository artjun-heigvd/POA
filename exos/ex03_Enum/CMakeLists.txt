cmake_minimum_required(VERSION 3.27)
project(ex03_Enum)

set(CMAKE_CXX_STANDARD 17)

add_executable(ex03_Enum main.cpp
        Season.cpp
        Season.h)
