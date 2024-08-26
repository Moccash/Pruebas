//
// Created by Mariana on 15/1/2024.
//

#include "SubjectSubMenu.h"

SubjectSubMenu::SubjectSubMenu(){
    BaseMenu::insertOption("(4) Eliminar curso");
    BaseMenu::insertOption("(3) Mostrar cursos");
    BaseMenu::insertOption("(2) Buscar cursos");
    BaseMenu::insertOption("(1) Agregar curso");
}

void SubjectSubMenu::handleOption(const string& opt) const {
    if (opt == "1") {
        // Get information from the user to create a new subject
        string name;
        int code, credit;
        cout << "Ingrese el nombre de la materia: "; cin >> name;
        cout << "Ingrese el codigo: "; cin >> code;
        cout << "Ingrese la cantidad de creditos: "; cin >> credit;
        Subject subject(name, code, credit);
        // Add the new subject to the vectorSubjects and display appropriate messages
        bool verify = subjects.addSubject(subject);
        newSubjects.push_back(subject);
        clearScreen();
        if (verify == true){
        cout << "Materia agregada correctamente" << std::endl << std::endl;
        system("pause");
        }
        else {
            cout << "La coleccion esta llena" << std::endl << std::endl;
            system("pause");
        }
    } else if (opt == "2") {
    cout << "Cursos en el plan: " << std::endl;
    cout << subjects.showSubjects() << std::endl;
        system("pause");
        int select;
        cout << "Desea ver los estudiantes pertenecientes de algun curso? Si[1]-No[2] " << endl;
        cin >> select;
        system("pause");
        if (select == 1){
            int code;
            cout << "Escriba el codigo de la materia que desee ver: "; cin >> code;
           bool found = false;
            Subject *mySubject = subjects.findSubjectByCode(code, found);
            clearScreen();
            cout << mySubject->showEspecificInfo();
            system("pause");
        }
        else{
            cout << "Materia no encontrada." << endl;
            cout << "Favor verifique el codigo de la materia e intente de nuevo" << endl;
            system("pause");
            clearScreen();
        }
    }else if (opt == "3") {
        // Search for a subject by code and display the result
        int code;
        cout << "Digite el codigo de la materia: "; cin >> code;
        std::string foundSubject = subjects.findSubject(code);
        if (foundSubject != "Materia no encontrada") {
            cout << "Materia encontrada " << std::endl << foundSubject << std::endl;
            system("pause");
        } else {
            cout << "No se encontro el curso" << std::endl;
            system("pause");
        }
    }
        else if(opt=="4"){
        int code;
        // Delete a subject based on the provided code and display appropriate messages
        cout << "Digite el codigo de curso que desea eliminar: "; cin >> code;
        bool verify = subjects.deleteSubject(code);
        clearScreen();
        if (verify == true) {
            cout << "El curso a sido eliminado correctamente " << std::endl << std::endl;
            system("pause");
        }
        else {
            cout << "No se ha encontrado el codigo o el codigo digitado es incorrecto " << std::endl << std::endl;
            system("pause");
        }
    }
}

//Show the options inserted
void SubjectSubMenu::displayMenu() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->option << std::endl;
        current = current->next;
    }
}

