//
// Created by ESCINF on 23/09/2024.
//

#include "chatMediador.h"
void chatMediador::registrar(Colaborador *colaborador)  {
    colaboradores.push_back(colaborador);
}//inserta en lista

void chatMediador::enviar(const std::string &mensaje, Colaborador *remitente)  {
    for(auto& colaborador:colaboradores) {
        if(colaborador != remitente) {
            colaborador->recibir(mensaje);
        }
    }
}//recorrido de lista, trabajar con el patron iterador