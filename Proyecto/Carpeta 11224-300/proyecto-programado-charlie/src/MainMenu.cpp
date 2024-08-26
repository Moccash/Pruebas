//
// Created by Mariana on 8/1/2024.
//

#include "MainMenu.h"


MainMenu::MainMenu() {
    insertOption("(0) Salir");
    insertOption("(2) Administrador");
    insertOption("(1) Estudiante");
}

void MainMenu::handleOption(const string& opt) const{
    if (opt == "1") {
        studentViewMenu.displayMenu();
    } else if (opt == "2") {
        adminViewMenu.displayMenu();
    }
}

void MainMenu::displayMenu() const {
    cout<<" \nMenu      "<<endl;
    cout<<"................................."<<endl;
    cout<<"\nIniciar sesion: "<<endl<<endl;
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->option << std::endl;
        current = current->next;
    }
    cout<<"\n................................"<<endl;
}