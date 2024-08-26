//
// Created by Mariana on 7/1/2024.
//

#include "UserInterface.h"
#include <iostream>
using namespace std;
//Its purpose is to interact with the user

void UserInterface::clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}


void UserInterface::handleUserInput() {
    string userChoice;
    cout << "\nUniversidad Nacional de Costa Rica" << endl;
    do {
        MainMenu menu;
        menu.displayMenu();
        cout << "Seleccione una opcion: ";
        getline(cin, userChoice);
        cout << "/n Guarde " <<endl;
        clearScreen();
        menu.handleOption(userChoice);

        if (userChoice == "1") {
            getline(cin, userChoice);
            clearScreen();
            if (userChoice != "r") {
                studentView.handleOption(userChoice);
                clearScreen();
            }
        } else if (userChoice == "2") {
            getline(cin, userChoice);
            clearScreen();
            if (userChoice != "r") {
                adminView.handleOption(userChoice);
                clearScreen();
            }

        }

    } while (userChoice != "0");
    cout << "CERRANDO SISTEMA, NO PRESIONE X ANTES";
    std::this_thread::sleep_for(std::chrono::seconds(2));
    bool base = true; // Aquí actualizamos la variable base a true al salir del bucle.
    FileSubMenu very;
    very.verificado(base); // Llamamos a la función para realizar acciones relacionadas con el cierre del sistema.

}

