//
// Created by LenovoE450 on 10/02/2024.
//
#include "archivo.h"
#include <iostream>
#include <fstream>

void guardarInformacion(const std::vector<Estudiante>& estudiantes, const std::vector<Materia>& materias, const std::string& filename) {
    std::ofstream archivoSalida(filename, std::ios::binary);

    if (!archivoSalida.is_open()) {
        std::cerr << "Error al abrir el archivo de salida: " << filename << std::endl;
        return;
    }

    int numEstudiantes = estudiantes.size();
    archivoSalida.write(reinterpret_cast<const char*>(&numEstudiantes), sizeof(int));

    for (const Estudiante& estudiante : estudiantes) {
        int nombreLength = estudiante.getNombre().length();
        archivoSalida.write(reinterpret_cast<const char*>(&nombreLength), sizeof(int));
        archivoSalida.write(estudiante.getNombre().c_str(), nombreLength);
        int edad = estudiante.getEdad();
        archivoSalida.write(reinterpret_cast<const char*>(&edad), sizeof(int));

        std::vector<Materia> materiasEstudiante = estudiante.getMaterias();
        int numMaterias = materiasEstudiante.size();
        archivoSalida.write(reinterpret_cast<const char*>(&numMaterias), sizeof(int));

        for (const Materia& materia : materiasEstudiante) {
            int nombreLength = materia.getNombre().length();
            archivoSalida.write(reinterpret_cast<const char*>(&nombreLength), sizeof(int));
            archivoSalida.write(materia.getNombre().c_str(), nombreLength);
            int creditos = materia.getCreditos();
            archivoSalida.write(reinterpret_cast<const char*>(&creditos), sizeof(int));
        }
    }

    int numMaterias = materias.size();
    archivoSalida.write(reinterpret_cast<const char*>(&numMaterias), sizeof(int));

    for (const Materia& materia : materias) {
        int nombreLength = materia.getNombre().length();
        archivoSalida.write(reinterpret_cast<const char*>(&nombreLength), sizeof(int));
        archivoSalida.write(materia.getNombre().c_str(), nombreLength);
        int creditos = materia.getCreditos();
        archivoSalida.write(reinterpret_cast<const char*>(&creditos), sizeof(int));
    }

    archivoSalida.close();
}

std::pair<std::vector<Estudiante>, std::vector<Materia>> cargarInformacion(const std::string& filename) {
    std::vector<Estudiante> estudiantes;
    std::vector<Materia> materias;

    std::ifstream archivoEntrada(filename, std::ios::binary);
    if (!archivoEntrada.is_open()) {
        std::cerr << "Error al abrir el archivo de entrada: " << filename << std::endl;
        return {estudiantes, materias};
    }

    int numEstudiantes;
    archivoEntrada.read(reinterpret_cast<char*>(&numEstudiantes), sizeof(int));

    for (int i = 0; i < numEstudiantes; ++i) {
        int nombreLength;
        archivoEntrada.read(reinterpret_cast<char*>(&nombreLength), sizeof(int));
        std::string nombre;
        nombre.resize(nombreLength);
        archivoEntrada.read(&nombre[0], nombreLength);
        int edad;
        archivoEntrada.read(reinterpret_cast<char*>(&edad), sizeof(int));
        Estudiante estudiante(nombre, edad);

        int numMaterias;
        archivoEntrada.read(reinterpret_cast<char*>(&numMaterias), sizeof(int));

        for (int j = 0; j < numMaterias; ++j) {
            int nombreLength;
            archivoEntrada.read(reinterpret_cast<char*>(&nombreLength), sizeof(int));
            std::string nombreMateria;
            nombreMateria.resize(nombreLength);
            archivoEntrada.read(&nombreMateria[0], nombreLength);
            int creditos;
            archivoEntrada.read(reinterpret_cast<char*>(&creditos), sizeof(int));
            Materia materia(nombreMateria, creditos);
            estudiante.agregarMateria(materia);
        }

        estudiantes.push_back(estudiante);
    }

    int numMaterias;
    archivoEntrada.read(reinterpret_cast<char*>(&numMaterias), sizeof(int));

    for (int i = 0; i < numMaterias; ++i) {
        int nombreLength;
        archivoEntrada.read(reinterpret_cast<char*>(&nombreLength), sizeof(int));
        std::string nombre;
        nombre.resize(nombreLength);
        archivoEntrada.read(&nombre[0], nombreLength);
        int creditos;
        archivoEntrada.read(reinterpret_cast<char*>(&creditos), sizeof(int));
        Materia materia(nombre, creditos);
        materias.push_back(materia);
    }

    archivoEntrada.close();
    return {estudiantes, materias};
}