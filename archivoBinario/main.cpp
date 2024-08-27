#include <iostream>
#include <fstream>
#include "Cliente.h"

int main() {
    std::cout << "Hello, World!" << std::endl;

    Billetera *miB = new Billetera(34235);

    Cliente *cte1 = new Cliente(52352, "Celeby", miB);
    Cliente *cte2 = new Cliente(3252, "Concha", miB);
    Cliente *cte3 = new Cliente(454, "Jose", miB);
    Cliente *cte4 = new Cliente(9823, "Mar", miB);

    fstream archivo("cteComp.bin", ios::binary | ios::out);
    if(archivo.is_open()){
        archivo.write((char *) cte1, sizeof(Cliente));
        archivo.write((char *) cte2, sizeof(Cliente));
        archivo.write((char *) cte3, sizeof(Cliente));
        archivo.write((char *) cte4, sizeof(Cliente));
        archivo.close();
    }

    else{
        cout << "El archivo no se pudo abrir..." << endl;
    }

    Cliente *temp = new Cliente;

    archivo.open("cteComp.bin", ios::binary | ios::in);
    if(archivo.is_open()){
        archivo.read((char *)temp, sizeof(Cliente));
        while(!archivo.eof()) {
            cout << *temp;
            archivo.read((char *)temp, sizeof(Cliente));
        }
    archivo.close();

    }

    delete miB;
    delete cte1;
    delete cte2;
    delete cte3;
    delete cte4;

    return 0;
}
