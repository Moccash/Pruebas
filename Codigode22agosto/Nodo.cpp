//
// Created by LenovoE450 on 24/8/2024.
//*
/*
no importante
#include "Nodo.h"
#ifndef CODIGODE22AGOSTO_NODO_H
#define CODIGODE22AGOSTO_NODO_H

template<class T>
class Nodo {
private:
    T valor;
    Nodo<T>* siguiente;
    Nodo<T>* anterior;

public:
    explicit Nodo(const T& valor) : valor(valor), siguiente(nullptr), anterior(nullptr) {}

    T getValor() const { return valor; }
    Nodo<T>* getSiguiente() const { return siguiente; }
    Nodo<T>* getAnterior() const { return anterior; }

    void setSiguiente(Nodo<T>* nodo) { siguiente = nodo; }
    void setAnterior(Nodo<T>* nodo) { anterior = nodo; }
};

#endif //CODIGODE22AGOSTO_NODO_H

*/