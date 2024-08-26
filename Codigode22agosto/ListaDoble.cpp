//
// Created by LenovoE450 on 24/8/2024.
//nio importante
/*


template<class T>
ListaDoble<T>::ListaDoble() {
    cabeza = nullptr;
    cola = nullptr;
}

template<class T>
ListaDoble<T>::~ListaDoble(){
    Nodo<T> *actual = cabeza;
    while (actual != nullptr){
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
void ListaDoble<T>::agregarAlfinal(const T &valor) {
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

/*
template<class T>
void ListaDoble<T>::agregarAlinicio(const T& valor) {
    Nodo<T>* nuevoNodo = new Nodo<T>(valor);
    if(cabeza== nullptr) {
        cabeza = cola -> nuevoNodo;
    }else{
        nuevoNodo->setSiguiente(cabeza);
        cabeza->setAnterior(nuevoNodo);
        cabeza = nuevoNodo;
    }
}

template<class T>
void ListaDoble<T>::agregarAlfinal(const T &valor) {
    Nodo<T>* nuevoNodo = new Nodo<T>(valor);
    if(cola == nullptr) {
        cola = cabeza -> nuevoNodo;
    }else{
        nuevoNodo->setSiguiente(cola);
        cola->setAnterior(nuevoNodo);
        cola = nuevoNodo;
    }

template<class T>
std::string ListaDoble<T>::imprimirLista() const{
    std::stringstream ss;
    ss << "Null <- ";
    Nodo<T> *actual = cabeza;
    while (actual != nullptr) {
        ss << actual->getValor() << " <->";
        actual = actual->getSiguiente();
    }

    ss << "-> Null";

    return ss.str();
}
*/
/*

template<class T>
class ListaDoble {
public:

    ListaDoble();
    ListaDobleoble();
    void agregarAlinicio(const T& valor);
    void agregarAlfinal(const T& valor);
    std::string imprimirLista() const;
private:
    Nodo<T>* cabeza;  // Points to the start of the list
    Nodo<T>* cola;    // Points to the end of the list
};

// Implementations

template<class T>
ListaDoble<T>::ListaDoble() {
    cabeza = nullptr;
    cola = nullptr;
}

template<class T>
ListaDoble<T>::ListaDobleoble() {
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
}*/