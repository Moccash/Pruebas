//
// Created by LenovoE450 on 9/1/2024.
//
#include "ManagerSubject.h"

ManagerSubject::ManagerSubject(){
    size = CANTMAX;
    counter = 0;
}

ManagerSubject::ManagerSubject(int n){
    counter=0;
    size=n;
}

bool ManagerSubject::addSubject(const Subject& newSubject) {
    if (counter < size) {
        subjects[counter] = newSubject;
        ++counter;
        return true;
    }
    return false;
}

std::string ManagerSubject::showSubjects() const {
    std::stringstream s;
    for (int i = 0; i < counter; ++i){
        s << subjects[i].displayInfo() << std::endl;
    }
    return s.str();
}

std::string ManagerSubject::findSubject(int code) {
    for (int i = 0; i < counter; i++) {
        if (subjects[i].getCode() == code) {
            return subjects[i].displayInfo();
        }
    }
    return "Materia no encontrada";
}

Subject * ManagerSubject::findSubjectByCode(int code, bool& found) {
    for (int i = 0; i < counter; i++) {
        if (subjects[i].getCode() == code) {
            found = true;
            return &subjects[i];
        }
    }
    found = false;
    return nullptr;
}




bool ManagerSubject::deleteSubject(int code) {
    for (int i = 0; i < counter; ++i) {
        if (subjects[i].getCode() == code) {
            for (int j = i; j < counter - 1; ++j) {
                subjects[j] = subjects[j + 1];
            }
            --counter;
            return true;
        }
        }
     return false;
    }


ManagerSubject::~ManagerSubject() {
}