//
// Created by LenovoE450 on 24/8/2024.
//

#ifndef CODIGODE22AGOSTO_PERSONA_H
#define CODIGODE22AGOSTO_PERSONA_H


#include <iostream>
#include <sstream>

class Persona {
private:
    int id;
    std::string nombre;
public:
    explicit Persona(int id, const std::string &nombre);


    virtual ~Persona();

    int getId() const;

    void setId(int id);

    const std::string &getNombre() const;

    void setNombre(const std::string &nombre);

    friend std::ostream &operator<<(std::ostream &os, const Persona &persona);

    bool operator==(const Persona &param)const;
};

//main . listaDoble<Persona> lsitap; . persona per# (id, nombre) ~~~~



#endif //CODIGODE22AGOSTO_PERSONA_H
