//
// Created by LenovoE450 on 29/8/2024.
//

#include "Persona.h"

Persona::Persona(int id, string nombre, string direccion) : id(id), nombre(nombre), direccion(direccion){}

Persona::Persona() {}

Persona::~Persona() {

}

const string &Persona::getDireccion() const {
    return direccion;
}

void Persona::setDireccion(const string &direccion) {
    Persona::direccion = direccion;
}

const string &Persona::getNombre() const {
    return nombre;
}

void Persona::setNombre(const string &nombre) {
    Persona::nombre = nombre;
}

int Persona::getId() const {
    return id;
}

void Persona::setId(int id) {
    Persona::id = id;
}

string Persona::ToString() {
    stringstream s;
    s << getId() << " , " << getNombre() << " , " << getDireccion() << endl;
    return s.str();
}