cmake_minimum_required(VERSION 3.27)
project(Examen1PrograII)

set(CMAKE_CXX_STANDARD 17)

add_executable(Examen1PrograII main.cpp
        ArchivoManager.h
        ArchivoManager.cpp
        Biblioteca.cpp
        Libro.cpp
        Libro.h
        Revista.cpp
        Revista.h
        Material.cpp
        Material.h
        Utilities.h
        Nodo.h
        ListaDoble.h
        Biblioteca.h)
