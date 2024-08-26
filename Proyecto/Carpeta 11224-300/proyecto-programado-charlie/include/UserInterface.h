//
// Created by Mariana on 7/1/2024.
//
#ifndef MAIN_USERINTERFACE_H
#define MAIN_USERINTERFACE_H

#include "StudentViewMenu.h"
#include "AdminViewMenu.h"
#include "MainMenu.h"
#include "BinaryFileManager.h"
#include <thread>
#include <chrono>
#include <iostream>
class FileSubMenu; // Declaración adelantada de la clase FileSubMenu
using namespace std;

class UserInterface{
private:
    StudentViewMenu studentView;
    AdminViewMenu adminView;
public:
    void handleUserInput();
    static void clearScreen();
};

#endif //MAIN_USERINTERFACE_H