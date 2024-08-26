//
// Created by Mariana on 26/12/2023.
//


#include "Student.h"
Student::Student(const string &name, const string &surname, const string &id, int age, const string &major) : Person(
        name, surname, id, age), major(major) {}

void Student::setMajor(const string &major) {
    this->major = major;
}

const string& Student::getMajor() const {
    return major;
}
Student::Student() {}

void Student::setSubjects(const std::vector<Subject *> &subjects) {
    Student::subjects = subjects;
}

const std::vector<Subject *> &Student::getSubjects() const {
    return subjects;
}

// Function to convert student information to a string
string Student :: toString () {
    stringstream s;
    s << Person::toString();
    s<<"Carrera: "<<major<<endl;
    return s.str();
}

string Student :: toStringCsv () const{
    stringstream s;
    s << Person::toStringCsv()<<","<<major<<endl;
    return s.str();
}


void Student::enrollSubject(Subject *subject) {
    subjects.push_back(subject);
    //subject->stackStudent(this);
}

/*
bool Student::enrollInSubjectIfNotEnrolled(Subject* subject) {
    // Verificar si el estudiante ya está inscrito en la materia
    auto it = std::find(subjects.begin(), subjects.end(), subject);

    if (it == subjects.end()) {
        return false;
    } else {
        return true;
    }
}
*/


string Student::showEnrolledSubjects() {
    stringstream s;
    s<<"Materias matriculadas del estudiante: "<<getName()<<endl;
    for (auto &subject:subjects){
        s<<subject->displayInfo()<<endl;
    }
    return s.str();
}

bool Student::isSubjectEnrolled(int subjectCode) const {
    for (const auto& subject : subjects) {
        if (subject->getCode() == subjectCode) {
            return true;
        }
    }
    return false;
}

void Student::modifyOrInsertGrade(ManagerGrade &managerGrade, int subjectCode, float grade) const{
    if (isSubjectEnrolled(subjectCode)) {
        int index = managerGrade.findSubjectIndex(subjectCode);
        if (index != -1) {
            // Modify the grade if the subject is already in the matrix
            managerGrade.setGrade(index, grade);
        } else {
            //If the subject is not present, add it along with the grade
            managerGrade.insertGrade(subjectCode, grade);
        }
    } else {
        cout << "Subject not enrolled. Cannot set grade." << endl;
    }
}

void Student::displayGradesMatrix(ManagerGrade &managerGrade) const {
    managerGrade.showGradeMatrix();
}

Student::~Student() {
}






















