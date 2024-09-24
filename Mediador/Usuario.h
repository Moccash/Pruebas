//
// Created by ESCINF on 23/09/2024.
//

#ifndef USUARIO_H
#define USUARIO_H
#include "Colaborador.h"


class Usuario: public Colaborador {
public:
    Usuario(Mediador * const mediador, const std::string &nombre);
    void enviar(const std::string &mensaje) override;
    void recibir(const std::string &mensaje) override;
};



#endif //USUARIO_H
