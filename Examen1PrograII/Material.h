//
// Created by Gregorio Villalobos on 10/9/24.
//

#ifndef MATERIAL_H
#define MATERIAL_H

#include "Utilities.h"

class Material {
public:
    Material(const std::string& titulo, const std::string& autor);
    virtual ~Material() = default;

    virtual std::string getTipo() const = 0;
    virtual std::string mostrar() const = 0;

    const std::string &getTitulo() const;
    const std::string &getAutor() const;

    friend std::ostream& operator<<(std::ostream& os, const Material& material);
protected:
    std::string titulo;
    std::string autor;
};

#endif // MATERIAL_H

