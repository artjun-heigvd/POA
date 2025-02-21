cmake_minimum_required(VERSION 3.14)
project(LabMatrix)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

add_executable(matrix src/Matrix.cpp src/main.cpp src/operations/Addition.cpp src/operations/Multiplication.cpp src/operations/Subtraction.cpp )

if(MSVC)
    target_compile_options(matrix PRIVATE /W4 /WX)
else()
    target_compile_options(matrix PRIVATE -Wall -Wpedantic -Werror)
endif()


# Include GoogleTest
include(FetchContent)
FetchContent_Declare(
  googletest
  GIT_REPOSITORY https://github.com/google/googletest.git
  GIT_TAG v1.14.0
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  tests
  tests/MatrixTest.cpp
  src/Matrix.cpp src/Matrix.hpp src/operations/Addition.cpp src/operations/Multiplication.cpp src/operations/Subtraction.cpp
)
target_link_libraries(
  tests
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(tests)
