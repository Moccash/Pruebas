//
// Created by Mariana on 15/1/2024.
//

#ifndef MAIN_GRADESSUBMENU_H
#define MAIN_GRADESSUBMENU_H


#include "BaseMenu.h"
#include "ManagerGrade.h"
class GradesSubMenu: BaseMenu {
public:
    GradesSubMenu();
    void handleOption (const string& opt) const override;
    void displayMenu () const override;

};


#endif //MAIN_GRADESSUBMENU_H
