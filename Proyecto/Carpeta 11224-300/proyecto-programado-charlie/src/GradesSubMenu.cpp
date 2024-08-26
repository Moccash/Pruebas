//
// Created by Mariana on 15/1/2024.
//

#include "GradesSubMenu.h"

GradesSubMenu::GradesSubMenu() {
    BaseMenu::insertOption("(2) Ingresar calificaciones");
    BaseMenu::insertOption("(1) Mostrar calificaciones estudiantes");
}

void GradesSubMenu::handleOption(const string& opt) const {
    if (opt == "1") {
        string id, userChoice;
        cout << "Cedula del estudiante: ";
        cin >> id;
        Student* encontrado = students.findStudent(id);
        if (encontrado != nullptr) {
            cout << "Estudiante encontrado: " << encontrado->toString() << std::endl;
            encontrado->displayGradesMatrix(managerGrade);
        } else {
            cout << "No se encontro informacion que coincida con la cedula aportada" << endl;
            cout << "Favor verifique e intente de nuevo" << endl;
        }
    system ("pause");
    } else if (opt == "2") {
        std::string id;
        std::cout << "Ingrese la cedula: ";
        std::cin >> id;
        // Search for the student by ID
        Student* student = students.findStudent(id);
        if (student != nullptr) {
            int classCode;
            float grade;
            // If the student is found, enter grades
            cout<<"\nIngrese el codigo del curso  ";cin>>classCode;
            cout<<"Ingrese calificacion: ";cin>>grade;
            cout<<endl;
            cout<<"hola";
            student->modifyOrInsertGrade(managerGrade, classCode, grade);
            system ("pause");

        }
        system ("pause");
    }
}

//Show the options inserted
void GradesSubMenu::displayMenu() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->option << std::endl;
        current = current->next;
    }
}



