//
// Created by Mariana on 7/1/2024.
//

#ifndef MAIN_STUDENTVIEWMENU_H
#define MAIN_STUDENTVIEWMENU_H
#include "BaseMenu.h"

class StudentViewMenu : public BaseMenu {
public:
    StudentViewMenu();
    void handleOption (const string& opt) const override;
    void displayMenu () const override;

};


#endif //MAIN_STUDENTVIEWMENU_H
