#include <iostream>
#include "Persona.h"
#include <fstream>

int main() {
    fstream archivo;

    Persona *per1 = new Persona(79801, "Mel", "San Jose");
    Persona *per2 = new Persona(79801, "Melissa", "San Carlos");

    archivo.open("prueba.txt", ios::out);
        if(archivo.is_open()){
            archivo << per1->ToString() << endl;
            archivo << per2->ToString() << endl;
            archivo.close();
            //tostringespecial
        }

    std::cout << "Hello, World!" << std::endl;

        archivo.open("prueba.txt", ios::in);
       string linea;
        if(archivo.is_open()){
            while (archivo.good()){// el .good revisa que el archivo este bueno, que no este corrupto, o que no este finalizado
                getline(archivo,linea,',');
                cout << linea << endl;
            }
            archivo.close();
        }
    return 0;
}
