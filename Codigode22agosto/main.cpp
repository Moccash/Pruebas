#include <iostream>
#include "ListaDoble.h"
#include "Persona.h"

int main() {
    ListaDoble<int> listaInt;

    // Agregar los valores a la lista
    listaInt.agregarAlinicio(1);
    listaInt.agregarAlinicio(2);
    listaInt.agregarAlinicio(3);
    listaInt.agregarAlfinal(5);
    listaInt.agregarAlinicio(4);

    // Imprimir la lista de valores
    std::cout << listaInt.imprimirLista() << std::endl;

    ListaDoble<Persona> listap;
    Persona per1 (90, "Marimar");
    Persona per2 (9, "Quimera");
    Persona per3 (213, "Zeyn");
    Persona per4 (56, "Syl");
    Persona per5 (33, "Palpuri");

    // Agregar personas a la lista
    listap.agregarAlinicio(per1);
    listap.agregarAlinicio(per2);
    listap.agregarAlfinal(per3);
    listap.agregarAlinicio(per4);
    listap.agregarAlfinal(per5);

    // Imprimir la lista de personas
    std::cout << listap.imprimirLista() << std::endl;
    return 0;
}
