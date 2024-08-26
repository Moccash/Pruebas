//
// Created by LenovoE450 on 24/8/2024.
//

#ifndef CODIGODE22AGOSTO_LISTADOBLE_H
#define CODIGODE22AGOSTO_LISTADOBLE_H

#include "Nodo.h"
#include <sstream>

template<class T>// nombres diferentes, pero mismo tipo
class ListaDoble {
public:

    ListaDoble();
    ~ListaDoble();
    void agregarAlinicio(const T& valor);
    void agregarAlfinal(const T& valor);
    std::string imprimirLista() const;
private:
    Nodo<T>* cabeza;//apunta al inicio
    Nodo<T>* cola;//apunta al final
//puede agregar un metodo size, pero no deberia(?


};

template<class T>
ListaDoble<T>::ListaDoble() {
    cabeza = nullptr;
    cola = nullptr;
}

template<class T>
ListaDoble<T>::~ListaDoble() {
    Nodo<T> *actual = cabeza;
    while (actual != nullptr) {
        Nodo<T> *siguiente = actual->getSiguiente();
        delete actual;
        actual = siguiente;
    }
}

template<class T>
void ListaDoble<T>::agregarAlinicio(const T& valor) {
    Nodo<T>* nuevoNodo = new Nodo<T>(valor);
    if (cabeza == nullptr) {
        cabeza = nuevoNodo;
        cola = nuevoNodo;
    } else {
        nuevoNodo->setSiguiente(cabeza);
        cabeza->setAnterior(nuevoNodo);
        cabeza = nuevoNodo;
    }
}

template<class T>
void ListaDoble<T>::agregarAlfinal(const T& valor) {
    Nodo<T>* nuevoNodo = new Nodo<T>(valor);
    if (cola == nullptr) {
        cabeza = nuevoNodo;
        cola = nuevoNodo;
    } else {
        cola->setSiguiente(nuevoNodo);
        nuevoNodo->setAnterior(cola);
        cola = nuevoNodo;
    }
}

template<class T>
std::string ListaDoble<T>::imprimirLista() const {
    std::stringstream ss;
    ss << "Null <- ";
    Nodo<T> *actual = cabeza;
    while (actual != nullptr) {
        ss << actual->getValor() << " <-> ";
        actual = actual->getSiguiente();
    }
    ss << "Null";
    return ss.str();
}

#endif //CODIGODE22AGOSTO_LISTADOBLE_H
