cmake_minimum_required(VERSION 3.27)
project(archivoJson)

set(CMAKE_CXX_STANDARD 17)

add_executable(archivoJson main.cpp
        Persona.h
        Persona.cpp dist/jsoncpp.cpp dist/json/json.h)

