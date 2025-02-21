cmake_minimum_required(VERSION 3.15)
project(river CXX)

set(CMAKE_CXX_STANDARD 23)

add_executable(river
        src/main.cpp
        src/Person.cpp
        src/Person.h
        src/Controller.cpp
        src/Controller.h
        src/Container.cpp
        src/Container.h
        src/Boat.cpp
        src/Boat.h
        src/Bank.cpp
        src/Bank.h
        src/typeOfPerson/Child.cpp
        src/typeOfPerson/Child.h
        src/typeOfPerson/Thief.cpp
        src/typeOfPerson/Thief.h
        src/typeOfPerson/Cop.cpp
        src/typeOfPerson/Cop.h
        src/typeOfPerson/Parent.cpp
        src/typeOfPerson/Parent.h
        src/typeOfPerson/typeOfChild/Boy.cpp
        src/typeOfPerson/typeOfChild/Boy.h
        src/typeOfPerson/typeOfChild/Girl.cpp
        src/typeOfPerson/typeOfChild/Girl.h
        src/Result.cpp
        src/RiverGame.cpp
        src/RiverGame.h)
