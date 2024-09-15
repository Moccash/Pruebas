#include "Biblioteca.h"
#include "Libro.h"
#include "Revista.h"

int main() {
    try {
        Biblioteca biblioteca;
        std::string archivo = "catalogo.csv";

        try {
            biblioteca.cargarCatalogo(archivo);
        } catch (const std::runtime_error& e) {
            std::cerr << "Error al cargar el catálogo: " << e.what() << std::endl;
        }

        try {
            biblioteca.mostrarCatalogo();
        } catch (const std::exception& e) {
            std::cerr << "Error al mostrar el catálogo: " << e.what() << std::endl;
        }

        system("pause");
        system("cls");

        try {
            biblioteca.agregarMaterial(new Libro("Kokoro", "Natsume Soseki", 250));
            biblioteca.agregarMaterial(new Revista("Acta Mexicana", "Nuevo Autor", 33));
        } catch (const std::bad_alloc& e) {
            std::cerr << "Error al agregar material: memoria insuficiente. " << e.what() << std::endl;
        } catch (const std::exception& e) {
            std::cerr << "Error al agregar material: " << e.what() << std::endl;
        }

        std::cout << std::endl << std::endl << "Nuevo catalogo:" << std::endl << std::endl;

        try {
            biblioteca.mostrarCatalogo();
        } catch (const std::exception& e) {
            std::cerr << "Error al mostrar el catálogo actualizado: " << e.what() << std::endl;
        }

        try {
            biblioteca.guardarCatalogo(archivo);
        } catch (const std::runtime_error& e) {
            std::cerr << "Error al guardar el catálogo: " << e.what() << std::endl;
        }

        system("pause");
    } catch (const std::exception& e) {
        std::cerr << "Excepción no manejada: " << e.what() << std::endl;
    }

    return 0;
}

/*
 * Comentarios de los dos principios de solid que se solicitan en:
 * Libro, Revista, ArchivoManager
 * Primer principio: se refiere a que una clase esta encargada unicamente de las tareas
 * que tienen que ver con esa clase.
 * Segundo principio: nos dice que las clases estan abiertas para la extension de estas,
 * pero que no permiten la modificacion.
 * */