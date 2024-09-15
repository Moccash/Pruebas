//
// Created by LenovoE450 on 14/9/2024.
//

#ifndef EXAMENPRUEBA_LISTADOBLE_H
#define EXAMENPRUEBA_LISTADOBLE_H

#include "Nodo.h"
#include "Utilities.h"

template <typename T>
class ListaDoble {
private:
    Nodo<T>* cabeza;
    Nodo<T>* cola;

public:

    ListaDoble() : cabeza(nullptr), cola(nullptr) {}

    Nodo<T>* getCabeza() const {
        return cabeza;
    }

    void agregarAlfinal(T valor) {
        Nodo<T>* nuevoNodo = new Nodo<T>(valor);
        if (cola == nullptr) {
            cabeza = cola = nuevoNodo;
        } else {
            cola->setSiguiente(nuevoNodo);
            nuevoNodo->setAnterior(cola);
            cola = nuevoNodo;
        }
    }

    std::string imprimirLista() const {
        std::stringstream ss;
        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            ss << *(actual->getValor()) << " -> ";
            actual = actual->getSiguiente();
        }
        ss << "NULL";
        return ss.str();
    }

    ~ListaDoble() {
        Nodo<T>* actual = cabeza;
        while (actual != nullptr) {
            Nodo<T>* temp = actual;
            actual = actual->getSiguiente();
            delete temp;
        }
    }
};

#endif //EXAMENPRUEBA_LISTADOBLE_H
