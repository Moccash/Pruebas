//
// Created by LenovoE450 on 26/8/2024.
//

#ifndef ARCHIVOTXT_PERSONA_H
#define ARCHIVOTXT_PERSONA_H

#include <iostream>
#include <sstream>

using namespace std;
class Persona {
private:
    int id;
    string nombre;
    string direccion;
public:
    explicit Persona(int id, string nombre, string direccion);

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


#endif //ARCHIVOTXT_PERSONA_H
