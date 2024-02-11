//
// Created by LenovoE450 on 10/02/2024.
//

#ifndef BIN_ESTUDIANTE_H
#define BIN_ESTUDIANTE_H
#include <string>
#include <vector>
#include "materia.h"

class Estudiante {
public:
    Estudiante();
    Estudiante(const std::string& nombre, int edad);
    void setNombre(const std::string& nombre);
    void setEdad(int edad);
    std::string getNombre() const;
    int getEdad() const;
    void agregarMateria(const Materia& materia);
    std::vector<Materia> getMaterias() const;

private:
    std::string nombre;
    int edad;
    std::vector<Materia> materias;
};
#endif //BIN_ESTUDIANTE_H
