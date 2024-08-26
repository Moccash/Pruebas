//
// Created by Mariana on 7/1/2024.
//
#include "StudentViewMenu.h"


StudentViewMenu::StudentViewMenu() { //insert the administrator options
    insertOption("(r) Regresar");
    insertOption("(3) Ver cursos inscritos");
    insertOption("(2) Matricular cursos");
    insertOption("(1) Historial calificaciones");

}

//Once the user selects the option this method handle what will be showed

void StudentViewMenu::handleOption(const string& opt) const {
    string id;
    cout << "Cedula usuario: ";
    cin >> id;
    Student* encontrado = students.findStudent(id);
    if (encontrado != nullptr) {
        if (opt == "1") {
            cout << "Estudiante encontrado: " << encontrado->toString() << std::endl;
            encontrado->displayGradesMatrix(managerGrade);

        } else if (opt == "2") {
            int subjectCode;
            cout << "Ingrese el codigo de la materia" << endl;
            cin >> subjectCode;
            bool found = false;
            Subject *foundSubject = subjects.findSubjectByCode(subjectCode, found);
            if (found) {
                encontrado->enrollSubject(foundSubject);
                foundSubject->stackStudent(encontrado);
                cout << "Materia inscrita correctamente" << endl;
            } else {
                cout << "Materia no encontrada." << endl;
                cout << "Favor verifique el codigo de la materia e intente de nuevo" << endl;
            }
        } else if (opt=="3") {
            cout << encontrado->showEnrolledSubjects();
        }
    }else {
        cout << "No se encontro informacion que coincida con la cedula aportada" << endl;
        cout << "Favor verifique e intente de nuevo" << endl;
    }
    system ("pause");
}
//Show the options inserted
void StudentViewMenu::displayMenu() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->option << std::endl;
        current = current->next;
    }
}