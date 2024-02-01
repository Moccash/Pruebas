#include <iostream>
#include <vector>
#include <fstream>
#include <locale.h>

using namespace std;

int main() {

    // Datos de mascotas
    vector<string> mascota{"Gato", "Perro", "Perico", "Pez", "Hamster"};
    vector<string> nombre{"Ñampi", "Delgado", "Escobar", "Delta", "María"};
    vector<int> edad{5, 8, 2, 1, 1};

    // Abrir un archivo CSV para escribir con codificación UTF-8
    ofstream archivoCSV("output.csv");
    archivoCSV.imbue(locale(""));  // Configurar la codificación UTF-8

    // Comprobar si el archivo se abrió correctamente
    if (archivoCSV.is_open()) {
        // Escribir encabezados en el archivo
        archivoCSV << "Mascota,Nombre,Edad" << endl;

        // Escribir datos en el archivo
        for (int i = 0; i < mascota.size(); i++) {
            archivoCSV << mascota[i] << "," << nombre[i] << "," << edad[i] << endl;
        }

        // Cerrar el archivo
        archivoCSV.close();

        cout << "Datos escritos en output.csv" << endl;

        // Reabrir el archivo para lectura
        ifstream archivoLectura("output.csv");
        if (archivoLectura.is_open()) {
            setlocale(LC_ALL, "");
            cout << "Contenido del archivo:" << endl;
            string linea;
            while (getline(archivoLectura, linea)) {
                cout << linea << endl;
            }
            archivoLectura.close();
        } else {
            cout << "No se pudo abrir el archivo para lectura" << endl;
        }
    } else {
        cout << "No se pudo abrir el archivo output.csv" << endl;
    }
    //system("chcp 65001");
    system("pause");
    return 0;
}
