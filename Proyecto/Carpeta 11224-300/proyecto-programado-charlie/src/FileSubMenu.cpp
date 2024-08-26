//
// Created by LenovoE450 on 07/02/2024.
//


#include "FileSubMenu.h"

FileSubMenu::FileSubMenu() {
    BaseMenu::insertOption("(4) Vaciar informacion del sistema");
    BaseMenu::insertOption("(3) Cargar Informacion Recopilada");
    BaseMenu::insertOption("(2) Importar");
    BaseMenu::insertOption("(1) Exportar");
}

string FileSubMenu::crearRuta(const string filename) const {
    string ruta = "C:/ArchivoCharlie/";
    string tipo = ".csv";
    return ruta + filename + tipo;
}

bool FileSubMenu::verificado(bool base) {
    if(base==true){
        BinaryFileManager::saveInformation(newStudents, newSubjects, "information.dat");
    }
    return 0;
}

void FileSubMenu::handleOption(const string &opt) const {
    string fname;
    if (opt == "1") {
        cout << "Creando archivo CSV" << endl << endl;
        cout << "El archivo se creara en: " << endl;
        cout << "\nArchivoCharlie" << endl << endl;
        cout << "Nombre de archivo: ";
        cin >> fname;
        system("pause");
        clearScreen();
        cout << "El archivo se ha exportado exitosamente" << endl;
        system("pause");
        string destino = FileSubMenu::crearRuta(fname.c_str());
        CsvFileManager::saveFile(newStudents, destino);

    } else if (opt == "2") {
        string filename;
        cout << "Digite el nombre del archivo: " << endl;
        cin >> filename;
        string destino = FileSubMenu::crearRuta(filename.c_str());
        auto readStudent = CsvFileManager::readFile(destino);
        for (auto &student: readStudent) {
            cout << student.toStringCsv();
        }
        system("pause");
    } else if (opt == "3") {
        cout << "Informacion del sistema: " << endl;

        auto informacionCargada = BinaryFileManager::loadInformation("information.dat");

        vector<Student> estudiantesCargadosI = informacionCargada.first;
        vector<Subject> materiasCargadasI = informacionCargada.second;

        for (const auto &estudiante: estudiantesCargadosI) {
            std::cout << " Nombre: " << estudiante.getName() << " Apellido: " << estudiante.getSurname() << " Edad: "
                      << estudiante.getAge() << " Carrera: " << estudiante.getMajor() << std::endl;
        }

        for (const auto &materia: materiasCargadasI) {
            std::cout << " Materia: " << materia.getName() << " Codigo: " << materia.getCode() << " Créditos: "
                      << materia.getCredit() << std::endl;
        }
        system("pause");

    } else if (opt == "4") {
        BinaryFileManager::emptyInformation("information.dat");
        cout << "Vaciando informacion..." << endl;
        system("pause");
    }
}



void FileSubMenu::displayMenu() const {
    Node *current = head;
    cout << "\nInforme de estudiantes matriculados" << endl << endl;
    while (current != nullptr) {
        std::cout << current->option << std::endl;
        current = current->next;
    }
}