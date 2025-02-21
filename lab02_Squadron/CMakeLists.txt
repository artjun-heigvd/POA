cmake_minimum_required(VERSION 3.10)
project(LabSquadron)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(LabSquadron src/main.cpp
        src/Squadron.cpp
        src/Squadron.h
        src/Ship.cpp
        src/Ship.h
        src/ShipCargo.cpp
        src/ShipCargo.h
        src/ConcreteShips/TIE.cpp
        src/ConcreteShips/TIE.h
        src/ConcreteShips/TIEInterceptor.cpp
        src/ConcreteShips/TIEInterceptor.h
        src/ConcreteShips/Shuttle.cpp
        src/ConcreteShips/Shuttle.h
        src/ConcreteShips/Dreadnought.cpp
        src/ConcreteShips/Dreadnought.h
        src/TIEModel.cpp
        src/TIEModel.h
)