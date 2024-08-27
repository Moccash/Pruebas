//
// Created by LenovoE450 on 26/8/2024.
//

#ifndef ARCHIVOBINARIO_BILLETERA_H
#define ARCHIVOBINARIO_BILLETERA_H


class Billetera {
private:
    float dinero;
public:
    explicit Billetera(float dinero);

    virtual ~Billetera();// por que el destructor lo coloca con default

    float getDinero() const;

    void setDinero(float dinero);
};


#endif //ARCHIVOBINARIO_BILLETERA_H
