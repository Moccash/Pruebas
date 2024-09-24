//
// Created by ESCINF on 23/09/2024.
//

#include "Usuario.h"

#include "Mediador.h"
//truc: clic izq. + primera opcion + generate definition in cpp

Usuario::Usuario(Mediador * const mediador, const std::string &nombre)
        : Colaborador(mediador, nombre) {
}

void Usuario::enviar(const std::string &mensaje)  {//preferiblemenmte no tire cout de esa manera, retorne valores
    std::cout <<  get_nombre() << " envia: " << mensaje << std::endl;
    mediador->enviar(mensaje, this);
}

void Usuario::recibir(const std::string &mensaje)  {
    std::cout << get_nombre() << " recibe: " << mensaje << std::endl;
}