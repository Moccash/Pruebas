//
// Created by Mariana on 26/12/2023.
//

#ifndef UNTITLED1_STUDENT_H
#define UNTITLED1_STUDENT_H
#include <iostream>
#include <vector>
#include <sstream>
#include "Subject.h"
#include "Person.h"
#include "ManagerGrade.h"

using namespace std;
class Subject;
class ManagerGrade;
class Student : public Person {
private:
    vector<Subject*>subjects;
    string major;
public:
    Student(const string &name, const string &surname, const string &id, int age, const string &major);
    Student();
    string toString ()override;
    string toStringCsv () const override;
    const string&getMajor() const;
    void setMajor(const string &major);
    void enrollSubject(Subject *subject);
    string showEnrolledSubjects();
    void setSubjects(const std::vector<Subject *> &subjects);
    const std::vector<Subject *> &getSubjects() const;
    bool isSubjectEnrolled(int subjectCode) const;
    void modifyOrInsertGrade(ManagerGrade &managerGrade, int subjectCode, float grade) const;
    void displayGradesMatrix(ManagerGrade &managerGrade) const;
    ~Student();

};


#endif //UNTITLED1_STUDENT_H

