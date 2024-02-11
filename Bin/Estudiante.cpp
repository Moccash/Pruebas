//
// Created by LenovoE450 on 10/02/2024.
//
#include "estudiante.h"

Estudiante::Estudiante() : nombre(""), edad(0) {}

Estudiante::Estudiante(const std::string& nombre, int edad) : nombre(nombre), edad(edad) {}

void Estudiante::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}

void Estudiante::setEdad(int edad) {
    this->edad = edad;
}

std::string Estudiante::getNombre() const {
    return nombre;
}

int Estudiante::getEdad() const {
    return edad;
}

void Estudiante::agregarMateria(const Materia& materia) {
    materias.push_back(materia);
}

std::vector<Materia> Estudiante::getMaterias() const {
    return materias;
}