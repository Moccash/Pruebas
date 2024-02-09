//
// Created by LenovoE450 on 09/02/2024.
//

#ifndef UNTITLED2_ARCHIVODATOS_H
#define UNTITLED2_ARCHIVODATOS_H

#include <vector>
#include <string>
#include "Materia.h"
#include "Estudiante.h"

class ArchivoDatos {
public:
    void guardarDatos(const std::vector<Materia>& listaMaterias, const std::vector<Estudiante>& listaEstudiantes, const std::string& nombreArchivo);
    void leerDatos(const std::string& nombreArchivo);
};
#endif //UNTITLED2_ARCHIVODATOS_H
