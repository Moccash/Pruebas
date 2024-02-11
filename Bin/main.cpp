#include <iostream>
#include <vector>
#include "estudiante.h"
#include "archivo.h"

int main() {
    Estudiante estudiante1("Juan", 30);
    estudiante1.agregarMateria(Materia("Matemáticas", 3));
    estudiante1.agregarMateria(Materia("Física", 4));

    Estudiante estudiante2("Maria", 25);
    estudiante2.agregarMateria(Materia("Química", 3));
    estudiante2.agregarMateria(Materia("Biología", 4));

    std::vector<Estudiante> estudiantes = {estudiante1, estudiante2};

    std::vector<Materia> materias = {
            Materia("Matemáticas", 3),
            Materia("Física", 4),
            Materia("Química", 3),
            Materia("Biología", 4)
    };

    guardarInformacion(estudiantes, materias, "informacion.dat");

    auto informacionCargada = cargarInformacion("informacion.dat");

    std::vector<Estudiante> estudiantesCargados = informacionCargada.first;
    std::vector<Materia> materiasCargadas = informacionCargada.second;

    for (const auto& estudiante : estudiantesCargados) {
        std::cout << "Nombre: " << estudiante.getNombre() << ", Edad: " << estudiante.getEdad() << std::endl;
        std::cout << "Materias:" << std::endl;
        for (const auto& materia : estudiante.getMaterias()) {
            std::cout << "  - " << materia.getNombre() << ", Créditos: " << materia.getCreditos() << std::endl;
        }
    }

    std::cout << "Materias cargadas:" << std::endl;
    for (const auto& materia : materiasCargadas) {
        std::cout << "- " << materia.getNombre() << ", Créditos: " << materia.getCreditos() << std::endl;
    }

    return 0;
}