cmake_minimum_required(VERSION 3.27)
project(Bin)

set(CMAKE_CXX_STANDARD 17)

add_executable(Bin main.cpp
        Archivo.cpp
        Materia.cpp
        Estudiante.cpp)
