//
// Created by Gregorio Villalobos on 10/9/24.
//

#ifndef LIBRO_H
#define LIBRO_H
#include "Material.h"
//esta clase esta manejando unicamente el libro, respetando el primer principio de SOLID
//El segundo principio de SOLID, Abierto/Cerrado, se ejemplifica en esta parte
//puesto que se entiende que es una extension de material, pero la clase no modifica a material. Mismo caso con Revista

class Libro : public Material {
public:
    Libro(const std::string& titulo, const std::string& autor, int numPaginas);
    std::string getTipo() const override;
    std::string mostrar() const override;
    int getNumPaginas() const;
    friend std::ostream& operator<<(std::ostream& os, const Libro& libro);
private:
    int numPaginas;
};
#endif // LIBRO_H

