//
// Created by Gregorio Villalobos on 10/9/24.
//

#include "Revista.h"

Revista::Revista(const std::string& titulo, const std::string& autor, int numEdicion)
        : Material(titulo, autor), numEdicion(numEdicion) {}

std::string Revista::mostrar() const {
    std::stringstream ss;
    ss << "Título: " << getTitulo() << ", Autor: " << getAutor()
              << ", Edición: " << numEdicion << std::endl;
    return ss.str();
}

std::string Revista::getTipo() const  { return "Revista"; }

std::ostream& operator<<(std::ostream& os, const Revista& revista) {
    os << static_cast<const Material&>(revista) << ", Edicion: " << revista.numEdicion;
    return os;
}

int Revista::getNumEdicion() const {
    return numEdicion;
}


