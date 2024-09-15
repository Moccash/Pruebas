//
// Created by LenovoE450 on 14/9/2024.
//

#ifndef EXAMENPRUEBA_NODO_H
#define EXAMENPRUEBA_NODO_H

template <typename T>
class Nodo {
private:
    T valor;
    Nodo* siguiente;
    Nodo* anterior;
public:
    Nodo(T valor) : valor(valor), siguiente(nullptr), anterior(nullptr) {}
    T getValor() const { return valor; }
    Nodo* getSiguiente() const { return siguiente; }
    Nodo* getAnterior() const { return anterior; }
    void setSiguiente(Nodo* siguiente) { this->siguiente = siguiente; }
    void setAnterior(Nodo* anterior) { this->anterior = anterior; }
};

#endif //EXAMENPRUEBA_NODO_H
