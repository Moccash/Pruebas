//
// Created by Mariana on 7/1/2024.
//

#ifndef MAIN_ADMINVIEWMENU_H
#define MAIN_ADMINVIEWMENU_H
#include "SubjectSubMenu.h"
#include "StudentSubMenu.h"
#include "GradesSubMenu.h"
#include "FileSubMenu.h"

// Declaration of the AdminViewMenu class, derived from BaseMenu
class AdminViewMenu : public BaseMenu {
private:
    StudentSubMenu studentMenu;
    SubjectSubMenu subjectMenu;
    GradesSubMenu gradesMenu;
    FileSubMenu fileMenu;
public:
// Constructor for AdminViewMenu
    AdminViewMenu();
// Function to handle the selected option, overridden from BaseMenu
    void handleOption (const string& opt) const override;
    void displayMenu () const override;
    ~AdminViewMenu() override;
};

#endif
