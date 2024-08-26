//
// Created by Mariana on 4/1/2024.
//


#include "ManagerStudent.h"


// Constructor that initializes ManagerStudent with a specified number of students
ManagerStudent::ManagerStudent(int n) : students(n, nullptr) {}

// Default constructor for ManagerStudent
ManagerStudent::ManagerStudent() {}

// Function to add a Student object to the manager's list
void ManagerStudent::addStudent(Student *object) {
    students.push_back(object);
}

// Function to convert information of all students to a string
std::string ManagerStudent::showStudentInformation() const {
    std::string result;
    size_t amount = students.size();

    for (size_t i = 0; i < amount; ++i) {
        result += students[i]->toString() + "\n";
    }

    return result;
}

// Function to convert grades information of all students to a string
/*std::string ManagerStudent::gradestoString() const {
    std::string result;
    size_t amount = students.size();

    for (size_t i = 0; i < amount; ++i) {
        result += students[i]->gradestoString() + "\n";
    }

    return result;
}
 */

// Function to perform selection sort on the students based on their surnames
void ManagerStudent::selectionSort() {
    size_t n = students.size();

    for (size_t i = 0; i < n - 1; i++) {
        size_t posMenor = i;

        for (size_t j = i + 1; j < n; j++) {
            // Compare surnames
            if (students[j]->getSurname() < students[posMenor]->getSurname()) {
                posMenor = j;
            }
        }

        if (posMenor != i) {
            // Swap positions by moving the minor
            std::swap(students[i], students[posMenor]);
        }
    }
}

// Function to find a student based on their ID
Student* ManagerStudent::findStudent(const string &id_) {
    for (size_t i = 0; i < students.size(); i++) {
        if (students[i]->getId()==id_) {
            return students[i];
        }
    }
    return nullptr;
}


// Function to delete a student based on their ID
void ManagerStudent::deleteStudent(std::string id_) {
    for (int i = 0; i < students.size(); i++) {
        if (students[i]->getId() == id_) {
            // Elimina el estudiante encontrado
            delete students[i];
            students.erase(students.begin() + i);
            return;  // Termina la función después de encontrar y eliminar al estudiante
        }
    }
}

// Destructor
ManagerStudent::~ManagerStudent() {
    for (auto& student : students) {
        delete student;
    }
}