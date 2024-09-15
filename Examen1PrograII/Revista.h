//
// Created by Gregorio Villalobos on 10/9/24.
//

#ifndef EXAMEN12024_REVISTA_H
#define EXAMEN12024_REVISTA_H
#include "Material.h"
//esta clase esta manejando unicamente la revista, respetando el primer principio de SOLID
class Revista : public Material {
public:
    Revista(const std::string& titulo, const std::string& autor, int numEdicion);
    std::string getTipo() const override;
    std::string mostrar() const override;
    int getNumEdicion() const;
    friend std::ostream& operator<<(std::ostream& os, const Revista& revista);
private:
    int numEdicion;
};

#endif //EXAMEN12024_REVISTA_H
