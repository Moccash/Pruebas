//
// Created by Mariana on 15/1/2024.
//

#ifndef MAIN_STUDENTSUBMENU_H
#define MAIN_STUDENTSUBMENU_H
#include "BaseMenu.h"
#include "Student.h"
class StudentSubMenu : BaseMenu {
public:
    StudentSubMenu();
    void handleOption (const string& opt) const override;
    void displayMenu () const override;
    ~StudentSubMenu();
};


#endif //MAIN_STUDENTSUBMENU_H
