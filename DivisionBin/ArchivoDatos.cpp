//
// Created by LenovoE450 on 09/02/2024.
//
#include "ArchivoDatos.h"
#include <fstream>
#include <iostream>

void ArchivoDatos::guardarDatos(const std::vector<Materia>& listaMaterias, const std::vector<Estudiante>& listaEstudiantes, const std::string& nombreArchivo) {
    std::ofstream archivoSalida(nombreArchivo, std::ios::binary);

    if (archivoSalida.is_open()) {
        int numMaterias = listaMaterias.size();
        archivoSalida.write(reinterpret_cast<char*>(&numMaterias), sizeof(int));

        for (const Materia& materia : listaMaterias) {
            archivoSalida.write(reinterpret_cast<const char*>(&materia), sizeof(Materia));
        }

        int numEstudiantes = listaEstudiantes.size();
        archivoSalida.write(reinterpret_cast<char*>(&numEstudiantes), sizeof(int));

        for (const Estudiante& estudiante : listaEstudiantes) {
            archivoSalida.write(reinterpret_cast<const char*>(&estudiante), sizeof(Estudiante));
        }

        archivoSalida.close();
    } else {
        std::cerr << "Error al abrir el archivo para escritura." << std::endl;
    }
}

void ArchivoDatos::leerDatos(const std::string& nombreArchivo) {
    std::ifstream archivoEntrada(nombreArchivo, std::ios::binary);

    if (archivoEntrada.is_open()) {
        int numMaterias;
        archivoEntrada.read(reinterpret_cast<char*>(&numMaterias), sizeof(int));

        for (int i = 0; i < numMaterias; ++i) {
            Materia materiaLeida;
            archivoEntrada.read(reinterpret_cast<char*>(&materiaLeida), sizeof(Materia));
            std::cout << "Materia: " << materiaLeida.nombre << ", Codigo: " << materiaLeida.codigo << std::endl;
        }

        int numEstudiantes;
        archivoEntrada.read(reinterpret_cast<char*>(&numEstudiantes), sizeof(int));

        for (int i = 0; i < numEstudiantes; ++i) {
            Estudiante estudianteLeido;
            archivoEntrada.read(reinterpret_cast<char*>(&estudianteLeido), sizeof(Estudiante));
            std::cout << "Estudiante: " << estudianteLeido.nombre << ", Edad: " << estudianteLeido.edad << std::endl;

        }
system("pause");
        archivoEntrada.close();
    } else {
        std::cerr << "Error al abrir el archivo para lectura." << std::endl;
    }
}