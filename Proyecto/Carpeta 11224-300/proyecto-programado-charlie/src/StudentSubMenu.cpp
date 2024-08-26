//
// Created by Mariana on 15/1/2024.
//

#include "StudentSubMenu.h"

StudentSubMenu::StudentSubMenu(){
    BaseMenu::insertOption("(4) Eliminar estudiante");
    BaseMenu::insertOption("(3) Mostrar estudiantes");
    BaseMenu::insertOption("(2) Buscar estudiante");
    BaseMenu::insertOption("(1) Agregar estudiante");
}

void StudentSubMenu::handleOption(const string& opt) const {
    if (opt == "1") {
        // Get information from the user to create a new student
        string name_, surname_, major_, id_;
        int age_;
        cout<<"Nombre: ";cin>>name_;
        cout<<"Apellido: "; cin>>surname_;
        cout<<"Identificacion: "; cin>>id_;
        cout<<"Edad: "; cin>>age_;
        cout<<"Carrera: "; cin>>major_;

        // Add the new student to the vectorStudents and display appropriate messages
        students.addStudent(new Student(name_, surname_, id_, age_, major_));
        auto s = Student(name_, surname_, id_, age_, major_);
        newStudents.push_back(s);
        BaseMenu::clearScreen();
        cout<<"Estudiante agregado correctamente..."<<endl<<endl;
        system ("pause");
    } else if (opt == "2") {
        // Search for a student by ID and display the result
        string id, userChoice;
            cout << "Cedula del estudiante: ";
            cin >> id;
            Student* encontrado = students.findStudent(id);
            if (encontrado != nullptr) {
                cout << "Estudiante encontrado: " << encontrado->toString() << std::endl;
            } else {
                cout << "No se encontro informacion que coincida con la cedula aportada" << endl;
                cout << "Favor verifique e intente de nuevo" << endl;
            }
        system ("pause");
    } else if (opt=="3"){
        // Display the list of students sorted by surname
        students.selectionSort();
        cout << students.showStudentInformation() << endl;
        system("pause");
    }  else if (opt=="4"){
        // Delete a student based on the provided ID and display appropriate messages
        string id_;
        cout<<"Todos los estudiantes matriculados: "<<endl;
        cout<<students.showStudentInformation()<<endl;
        cout<<"Digite la cedula del estudiante a eliminar: "<<endl;
        cin>>id_;
        students.deleteStudent(id_);
        clearScreen();
        cout<<"Estudiante eliminado correctamente "<<endl<<endl;
        system ("pause");
    }
}

//Show the options inserted
void StudentSubMenu::displayMenu() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->option << std::endl;
        current = current->next;
    }
}

StudentSubMenu::~StudentSubMenu(){
}