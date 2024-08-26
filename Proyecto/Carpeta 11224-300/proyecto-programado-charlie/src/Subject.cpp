//
// Created by LenovoE450 on 4/1/2024.
//
#include "Subject.h"

Subject::Subject() : name(""), code(0), credit(0) {}

Subject::Subject(std::string newName, int newCode, int newCredit)
        : name(newName), code(newCode), credit(newCredit) {}

void Subject::setName(std::string newName) {
    name = newName;
}

void Subject::setCode(int newCode) {
    code = newCode;
}

void Subject::setCredit(int newCredit) {
    credit = newCredit;
}

std::string Subject::getName() const {
    return name;
}

int Subject::getCode() const {
    return code;
}

int Subject::getCredit() const {
    return credit;
}

std::string Subject::displayInfo() const {
    std::stringstream s;
    s << "Informacion de la materia:" << std::endl;
    s << "Nombre: " << name << std::endl;
    s << "Codigo: " << code << std::endl;
    s << "Cantidad de creditos: " << credit << std::endl;
    return s.str();
}

void Subject::stackStudent(Student *student) {
    students.push_back(student);
    //student->enrollSubject(this);
}

const std::vector<Student *> &Subject::getStudents() const {
    return students;
}

void Subject::setStudents(const std::vector<Student *> &students) {
    Subject::students = students;
}


std::string Subject::showEspecificInfo() {
    stringstream s;
    s<<"Lista de estudiantes en la materia: "<<getName()<<endl;
    for (auto &student:students){
        s<<student->getName() <<  " " << student->getSurname() << ",Cedula: " << student->getId() << endl;
    }
    return s.str();
}

Subject::~Subject() {}
