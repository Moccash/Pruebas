//
// Created by LenovoE450 on 26/8/2024.
//

#include "Cliente.h"

Cliente::~Cliente() {

}

int Cliente::getId() const {
    return id;
}

void Cliente::setId(int id) {
    Cliente::id = id;
}

const string &Cliente::getNombre() const {
    return nombre;
}

void Cliente::setNombre(const string &nombre) {
    Cliente::nombre = nombre;
}

Billetera *Cliente::getMiBilletera() const {
    return miBilletera;
}

void Cliente::setMiBilletera(Billetera *miBilletera) {
    Cliente::miBilletera = miBilletera;
}

Cliente::Cliente(int id, const string &nombre, Billetera *miBilletera) : id(id), nombre(nombre),
                                                                         miBilletera(miBilletera) {}

ostream &operator<<(ostream &os, const Cliente &cliente) {
    os << "id: " << cliente.id << " nombre: " << cliente.nombre << " dinero: " << cliente.getDinero() << endl;
    return os;
}

float Cliente::getDinero () const{
return miBilletera->getDinero();
}