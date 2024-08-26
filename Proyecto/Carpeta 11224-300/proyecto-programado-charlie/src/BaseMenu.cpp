//
// Created by Mariana on 7/1/2024.
//

#include "BaseMenu.h"
// Static members for managing students and subjects across instances of BaseMenu
ManagerStudent BaseMenu::students;
ManagerSubject BaseMenu::subjects;
ManagerGrade BaseMenu::managerGrade;
vector<Student> BaseMenu::newStudents;
vector<Subject> BaseMenu::newSubjects;

// Constructor for the BaseMenu class
BaseMenu::BaseMenu () : head(nullptr) {
}
// Function to insert a new option into the menu
void BaseMenu::insertOption(const std::string& opt) {
    Node* newNode = new Node{opt, head};
    head = newNode;
}

// Function to display the menu options
void BaseMenu::displayMenu() const {
    Node* current = head;
    while (current != nullptr) {
        std::cout << current->option << std::endl;
        current = current->next;
    }
}

BaseMenu::~BaseMenu () {
    // Call the clear function to deallocate memory for all nodes
    clear();
}


void BaseMenu::clear() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next;
        delete current;
        current = next;
    }
    head = nullptr;
}
// Function to clear the console screen based on the operating system
void BaseMenu::clearScreen() {
#ifdef _WIN32
    system("cls");
#else
    system("clear");
#endif
}

