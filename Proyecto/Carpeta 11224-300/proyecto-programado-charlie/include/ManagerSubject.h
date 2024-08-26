//
// Created by LenovoE450 on 9/1/2024.
//
#ifndef MAIN_MANAGERSUBJECT_H
#define MAIN_MANAGERSUBJECT_H

#include <string>
#include "Subject.h"
#include <sstream>
#define CANTMAX 3

class ManagerSubject {
private:
    int size;
    Subject subjects [CANTMAX];
    int counter;
public:
    ManagerSubject();
    ManagerSubject(int n);
    ~ManagerSubject();
    bool addSubject(const Subject& newSubject);
    std::string showSubjects() const;
    std::string findSubject(int code);
    bool deleteSubject(int code);
    Subject * findSubjectByCode(int code, bool& found);
    Subject * findSubject(const std::string &matter);
};

#endif // MAIN_MANAGERSUBJECT_H
