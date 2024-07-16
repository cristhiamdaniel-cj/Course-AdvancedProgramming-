cmake_minimum_required(VERSION 3.10)
project(regression_project)

set(CMAKE_CXX_STANDARD 11)

include_directories(include)

add_executable(regression_project main.cpp src/house.cpp
        ../StructsAvanzadas/Ejercicio1/main.cpp
        ../StructsAvanzadas/Ejercicio1/tests/test_main.cpp)
