cmake_minimum_required(VERSION 3.27)
project(ex01_Vector)

set(CMAKE_CXX_STANDARD 23)

add_executable(ex01_Vector main.cpp
        Vector.cpp
        Vector.h)
