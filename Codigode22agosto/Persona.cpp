//
// Created by LenovoE450 on 24/8/2024.
//

#include "Persona.h"

#include "Persona.h"

//void Persona:: set
int Persona::getId() const {
    return id;
}

void Persona::setId(int id) {
    Persona::id = id;
}

const std::string &Persona::getNombre() const {
    return nombre;
}

void Persona::setNombre(const std::string &nombre) {
    Persona::nombre = nombre;
}

std::ostream &operator<<(std::ostream &os, const Persona &persona) {
    os << "id: " << persona.id << " nombre: " << persona.nombre;
    return os;
}

Persona::Persona(int id,const std::string &nombre) : id(id), nombre(nombre) {}

bool Persona::operator==(const Persona &param) const {
    return this->getId()==param.getId();//rev
}

Persona::~Persona() {

}

//Persona::Persona(const std::string &nombre) : nombre(nombre) {}
