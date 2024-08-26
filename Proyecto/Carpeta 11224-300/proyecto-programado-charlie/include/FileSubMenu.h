//
// Created by LenovoE450 on 07/02/2024.
//
#ifndef MAIN_FILESUBMENU_H
#define MAIN_FILESUBMENU_H

#include "BaseMenu.h"
#include "CsvFileManager.h"

class UserInterface; // Declaración adelantada de la clase UserInterface

#include <iostream>

class FileSubMenu : BaseMenu {
public:
    FileSubMenu();
    void handleOption (const string& opt) const override;
    void displayMenu () const override;
    string crearRuta(string filename) const;

    bool verificado(bool base);
};

#endif //MAIN_FILESUBMENU_H