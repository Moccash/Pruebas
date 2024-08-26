//
// Created by LenovoE450 on 24/8/2024.
//

#ifndef CODIGODE22AGOSTO_NODO_H
#define CODIGODE22AGOSTO_NODO_H


template<class miTipo>
class Nodo {
public:
    Nodo(const miTipo& valor);

    miTipo getValor() const;

    void setValor(miTipo valor);

    Nodo<miTipo> *getSiguiente() const;

    void setSiguiente(Nodo<miTipo> *siguiente);

    Nodo<miTipo> *getAnterior() const;

    void setAnterior(Nodo<miTipo> *anterior);

    // virtual ~Nodo();

private:
    miTipo valor;
    Nodo<miTipo> *siguiente;
    Nodo<miTipo> *anterior;

};
// puede usar el refactor para cambiar el nombre de una variable
template<class miTipo>
Nodo<miTipo>::Nodo(const miTipo &valor):
        valor(valor), anterior(nullptr), siguiente(nullptr){
    /*this->valor=valor;
    this->anterior=anterior;
    this->siguiente=siguiente;*/
}


template<class miTipo>
Nodo<miTipo> *Nodo<miTipo>::getAnterior() const {
    return anterior;
}
/*
template<class miTipo>
void Nodo<miTipo>::setAnterior(Nodo<miTipo> *anterior) {
    Nodo::anterior = anterior;
}*/

template<class miTipo>
Nodo<miTipo> *Nodo<miTipo>::getSiguiente() const {
    return siguiente;
}
/*
template<class miTipo>
void Nodo<miTipo>::setSiguiente(Nodo<miTipo> *siguiente) {
    Nodo::siguiente = siguiente;
}*/

template<class miTipo>
miTipo Nodo<miTipo>::getValor() const {
    return valor;
}

template<class miTipo>
void Nodo<miTipo>::setValor(miTipo valor) {
    Nodo::valor = valor;
}

/*
template<class miTipo>
Nodo<miTipo>::~Nodo() {

}*/

template<class miTipo>
void Nodo<miTipo>::setAnterior(Nodo<miTipo> *anterior) {
    this->anterior = anterior;
}

template<class miTipo>
void Nodo<miTipo>::setSiguiente(Nodo<miTipo> *siguiente) {
    this->siguiente = siguiente;
}


#endif //CODIGODE22AGOSTO_NODO_H
