//
// Created by LenovoE450 on 26/8/2024.
//

#include "Billetera.h"

Billetera::Billetera(float dinero) : dinero(dinero) {}

Billetera::~Billetera() {

}

float Billetera::getDinero() const {
    return dinero;
}

void Billetera::setDinero(float dinero) {
    Billetera::dinero = dinero;
}
