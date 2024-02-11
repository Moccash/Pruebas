//
// Created by LenovoE450 on 10/02/2024.
//

#ifndef BIN_MATERIA_H
#define BIN_MATERIA_H
#include <string>

class Materia {
public:
    Materia();
    Materia(const std::string& nombre, int creditos);
    void setNombre(const std::string& nombre);
    void setCreditos(int creditos);
    std::string getNombre() const;
    int getCreditos() const;

private:
    std::string nombre;
    int creditos;
};

#endif //BIN_MATERIA_H
