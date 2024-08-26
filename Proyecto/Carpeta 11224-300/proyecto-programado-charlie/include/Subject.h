//
// Created by LenovoE450 on 4/1/2024.
//
#ifndef MAIN_SUBJECT_H
#define MAIN_SUBJECT_H

#include <string>
#include <iostream>
#include <sstream>
#include "Student.h"
#include <vector>
class Student;
class Subject {
private:
    std::vector<Student*>students;
    std::string name;
    int code;
    int credit;
public:
    Subject();
    Subject(std::string name, int code, int credit);
    void setName(std::string newName);
    void setCode(int newCode);
    void setCredit(int newCredit);
    std::string getName() const;
    int getCode() const;
    int getCredit() const;
    std::string displayInfo() const;
    void stackStudent(Student *student);
    std::string showEspecificInfo();
    void setStudents(const std::vector<Student *> &students);
    const std::vector<Student *> &getStudents() const;
    ~Subject();
};

#endif // MAIN_SUBJECT_H
