//
// Created by LenovoE450 on 26/8/2024.
//

#ifndef ARCHIVOBINARIO_CLIENTE_H
#define ARCHIVOBINARIO_CLIENTE_H

#include "Billetera.h"
#include <sstream>
#include <ostream>

using namespace std;
class Cliente {
private:
    int id;
    string nombre;
    Billetera *miBilletera;
public:
    Cliente(int id=0, const string &nombre="", Billetera *miBilletera= nullptr);

    virtual ~Cliente();

    int getId() const;

    void setId(int id);

    const string &getNombre() const;

    void setNombre(const string &nombre);

    Billetera *getMiBilletera() const;

    void setMiBilletera(Billetera *miBilletera);

    float getDinero() const;

    friend ostream &operator<<(ostream &os, const Cliente &cliente);
};


#endif //ARCHIVOBINARIO_CLIENTE_H
