//
// Created by Mariana on 15/1/2024.
//

#ifndef MAIN_COURSESUBMENU_H
#define MAIN_COURSESUBMENU_H


#include "BaseMenu.h"
// Declaration of the SubjectSubMenu class, derived from BaseMenu
class SubjectSubMenu : BaseMenu {
public:
    SubjectSubMenu();
    // Function to handle the selected option, overridden from BaseMenu
    void handleOption (const string& opt) const override;
    // Function to display the menu options, overridden from BaseMenu
    void displayMenu () const override;
};

#endif //MAIN_COURSESUBMENU_H
