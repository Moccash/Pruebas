
#include <vector>
#include "ArchivoDatos.h"
#include "Materia.h"
#include "Estudiante.h"
#include <iostream>
int main() {
    std::vector<Materia> listaMaterias = {
            {"Matemáticas", 101},
            {"Historia", 102},
            {"Biología", 103}
    };

    std::vector<Estudiante> listaEstudiantes = {
            {"Juan", 20},
            {"María", 22},
            {"Pedro", 21}
    };

    ArchivoDatos archivo;
    archivo.guardarDatos(listaMaterias, listaEstudiantes, "datos.bin");
    archivo.leerDatos("datos.bin");

    return 0;
}