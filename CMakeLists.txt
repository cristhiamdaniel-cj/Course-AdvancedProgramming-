cmake_minimum_required(VERSION 3.10)
project(Course_AdvancedProgramming_)

set(CMAKE_CXX_STANDARD 11)

# Añadir los archivos de cabecera e implementación
include_directories(${PROJECT_SOURCE_DIR})

add_executable(Course_AdvancedProgramming_
        Taller01/main.cpp
        Taller01/regresion_lineal.cpp)
