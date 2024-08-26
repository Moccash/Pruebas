//
// Created by Mariana on 7/1/2024.
//

#ifndef MAIN_BASEMENU_H
#define MAIN_BASEMENU_H
#include "ManagerStudent.h"
#include "ManagerSubject.h"
#include "ManagerGrade.h"
#include "Student.h"
#include "Subject.h"
#include "CsvFileManager.h"
#include "BinaryFileManager.h"
#include <iostream>
#include <vector>
using namespace std;

class BaseMenu {
public:

    BaseMenu ();
    virtual void displayMenu() const;
    virtual ~BaseMenu();
    void clear();
    static void clearScreen();

protected:
    struct Node {
        string option;
        Node* next;
    };

    Node* head;
    static ManagerStudent students;
    static ManagerSubject subjects;
    static ManagerGrade managerGrade;
    static vector<Student>newStudents;
    static vector<Subject>newSubjects;

    static CsvFileManager files;

    void insertOption(const string& opt);
    virtual void handleOption(const string &opt) const = 0;
};

#endif //MAIN_BASEMENU_H

