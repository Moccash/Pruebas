//
// Created by Mariana on 4/1/2024.
//
#ifndef INCLUDE_CONTAINER_H
#define INCLUDE_CONTAINER_H

#include <iostream>
#include <vector>
#include "Student.h"

class ManagerStudent {
private:
    std::vector<Student*> students;

public:
    // ManagerStudent with a specific size
    explicit ManagerStudent(int n);

    // Default container
    ManagerStudent();

    // Add students
    void addStudent(Student *object);

    // To show students
    std::string showStudentInformation() const;

    std::string gradestoString() const;

    //To find a student by ID
    Student* findStudent(const std::string & id_);

    // Selection sort method
    void selectionSort();


    void deleteStudent (string id_);

    // Destructor
    virtual ~ManagerStudent();
};



#endif