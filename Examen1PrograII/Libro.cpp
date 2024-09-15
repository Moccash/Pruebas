//
// Created by Gregorio Villalobos on 10/9/24.
//

#include "Libro.h"

Libro::Libro(const std::string& titulo, const std::string& autor, int numPaginas)
        : Material(titulo, autor), numPaginas(numPaginas) {}

std::string Libro::mostrar() const {
    std::stringstream ss;
    ss << "Título: " << getTitulo() << ", Autor: " << getAutor()
              << ", Páginas: " << numPaginas << std::endl;
    return ss.str();
}

std::string Libro::getTipo() const { return "Libro"; }

std::ostream& operator<<(std::ostream& os, const Libro& libro) {
    os << static_cast<const Material&>(libro) << ", Paginas: " << libro.numPaginas;
    return os;
}


int Libro::getNumPaginas() const {
    return numPaginas;
}




