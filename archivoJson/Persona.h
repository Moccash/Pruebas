//
// Created by LenovoE450 on 29/8/2024.
//

#ifndef ARCHIVOJSON_PERSONA_H
#define ARCHIVOJSON_PERSONA_H


#include <iostream>
#include <fstream>
#include "dist/json/json.h"
#include <sstream>

using namespace std;
class Persona {
private:
    int id;
    string nombre;
    string direccion;
public:
    explicit Persona(int id, string nombre, string direccion);

    Persona();
    //Persona(int id=0, const string &nomre="", const string &direccion="");

    //hacer los set, get y sobrecarga, constructor, destructor
    virtual ~Persona();

    int getId() const;

    void setId(int id);

    const string &getNombre() const;

    void setNombre(const string &nombre);

    const string &getDireccion() const;

    void setDireccion(const string &direccion);

    string ToString();

};


#endif //ARCHIVOJSON_PERSONA_H
