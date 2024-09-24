//
// Created by ESCINF on 23/09/2024.
//

#ifndef CHATMEDIADOR_H
#define CHATMEDIADOR_H
#include <vector>
#include "Mediador.h"

class chatMediador: public Mediador{/// missing members, overriding members(apunta a los metodos obligados a hacer por la herencia de la superclass) crea los que debe here.
private:
    //ListaSimple *colabadores;
    std::vector<Colaborador*> colaboradores;
public:
    void registrar(Colaborador *colaborador) override;
    void enviar(const std::string &mensaje, Colaborador *remitente) override;
};



#endif //CHATMEDIADOR_H
