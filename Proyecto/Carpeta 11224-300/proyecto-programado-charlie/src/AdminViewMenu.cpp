//
// Created by Mariana on 7/1/2024.
//

#include "AdminViewMenu.h"


AdminViewMenu::AdminViewMenu() { //insert the administrator options
    insertOption("(r) Regresar");
    insertOption("(4) Administrar registro");
    insertOption("(3) Administrar calificaciones");
    insertOption("(2) Administrar estudiantes");
    insertOption("(1) Administrar cursos");
}

//Once the user selects the option this method handle what will be showed

void AdminViewMenu::handleOption(const string& opt) const {
    if (opt == "1") {
        subjectMenu.displayMenu();
        string userchoice;
        cout << "Opcion: ";
        getline(cin, userchoice);
        clearScreen();
        subjectMenu.handleOption(userchoice);
    } else if (opt == "2") {
        studentMenu.displayMenu();
        string userchoice;
        cout << "Opcion: ";
        getline(cin, userchoice);
        clearScreen();
        studentMenu.handleOption(userchoice);
    } else if (opt=="3"){
        gradesMenu.displayMenu();
        string userchoice;
        cout << "Opcion: ";
        getline(cin, userchoice);
        clearScreen();
        gradesMenu.handleOption(userchoice);
    }
    else if (opt=="4"){
        fileMenu.displayMenu();
        string userchoice;
        cout << "Opcion: ";
        getline(cin, userchoice);
        clearScreen();
        fileMenu.handleOption(userchoice);
    }
}
//Show the options inserted
void AdminViewMenu::displayMenu() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->option << std::endl;
        current = current->next;
    }
}

AdminViewMenu::~AdminViewMenu() {}

