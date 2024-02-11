//
// Created by LenovoE450 on 10/02/2024.
//

#ifndef BIN_ARCHIVO_H
#define BIN_ARCHIVO_H

#include <vector>
#include "estudiante.h"

void guardarInformacion(const std::vector<Estudiante>& estudiantes, const std::vector<Materia>& materias, const std::string& filename);
std::pair<std::vector<Estudiante>, std::vector<Materia>> cargarInformacion(const std::string& filename);

#endif //BIN_ARCHIVO_H
