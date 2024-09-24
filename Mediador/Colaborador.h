//
// Created by ESCINF on 23/09/2024.
//

#ifndef COLABORADOR_H
#define COLABORADOR_H
#include <iostream>

class Mediador;

class Colaborador {
protected:
    Mediador *mediador;
    std::string nombre;
public:
    virtual void enviar(const std::string &mensaje) = 0; ///
    virtual void recibir(const std::string &mensaje) = 0; ///cont. + D/////el de adentro prohibe cambiar el valor de esa variable
    [[nodiscard]] const std::string & get_nombre() const {////este const de afuera prohibe cambiar nada inter. de la class
        return nombre;
    }

    void set_nombre(const std::string &nombre) {
        this->nombre = nombre;
    }

    Colaborador(Mediador * const mediador, const std::string &nombre)
        : mediador(mediador),
          nombre(nombre) {
    }
};



#endif //COLABORADOR_H
