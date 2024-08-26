//
// Created by Mariana on 8/1/2024.
//

#ifndef MAIN_MAINMENU_H
#define MAIN_MAINMENU_H
#include "BaseMenu.h"
#include "AdminViewMenu.h"
#include "StudentViewMenu.h"
#include "FileSubMenu.h"


class MainMenu : public BaseMenu{
private:
    StudentViewMenu studentViewMenu;
    AdminViewMenu adminViewMenu;
public:
    MainMenu();
    void handleOption (const string& opt) const override;
    void displayMenu () const override;
};


#endif //MAIN_MAINMENU_H