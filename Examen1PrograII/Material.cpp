//
// Created by Gregorio Villalobos on 10/9/24.
//

#include "Material.h"

const std::string &Material::getTitulo() const {
    return titulo;
}

const std::string & Material::getAutor() const {
    return autor;
}

Material::Material(const std::string& titulo, const std::string& autor)
        : titulo(titulo), autor(autor) {}

std::ostream& operator<<(std::ostream& os, const Material& material) {
    os << "Titulo: " << material.titulo << ", Autor: " << material.autor;
    return os;
}