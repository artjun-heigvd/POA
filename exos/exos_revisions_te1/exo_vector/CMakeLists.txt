cmake_minimum_required(VERSION 3.28)
project(exo_vector)

set(CMAKE_CXX_STANDARD 23)

add_executable(exo_vector main.cpp
        Vector.cpp
        Vector.h)
