//
// Created by LenovoE450 on 10/02/2024.
//
#include "materia.h"

Materia::Materia() : nombre(""), creditos(0) {}

Materia::Materia(const std::string& nombre, int creditos) : nombre(nombre), creditos(creditos) {}

void Materia::setNombre(const std::string& nombre) {
    this->nombre = nombre;
}

void Materia::setCreditos(int creditos) {
    this->creditos = creditos;
}

std::string Materia::getNombre() const {
    return nombre;
}

int Materia::getCreditos() const {
    return creditos;
}