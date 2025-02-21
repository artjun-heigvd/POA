cmake_minimum_required(VERSION 3.15)
project(buffy CXX)

set(CMAKE_CXX_STANDARD 23)

add_executable(buffy
        src/main.cpp
        src/Humanoid.cpp
        src/Humanoid.h
        src/humanoids/Buffy.cpp
        src/humanoids/Buffy.h
        src/humanoids/Vampire.cpp
        src/humanoids/Vampire.h
        src/humanoids/Human.cpp
        src/humanoids/Human.h
        src/Field.cpp
        src/Field.h
        src/Renderer.cpp
        src/Renderer.h
        src/Action.cpp
        src/Action.h
        src/subActions/KillAction.cpp
        src/subActions/KillAction.h
        src/subActions/ChaseAction.cpp
        src/subActions/ChaseAction.h
        src/subActions/MoveRandomAction.cpp
        src/subActions/MoveRandomAction.h
        src/utilities/Point.cpp
        src/utilities/Point.h
        src/utilities/Random.cpp
        src/utilities/Random.h
        src/subActions/MoveAction.cpp
        src/subActions/MoveAction.h
        src/subActions/BiteAction.cpp
        src/subActions/BiteAction.h
        src/humanoids/KillerHumanoid.cpp
        src/humanoids/KillerHumanoid.h
)
