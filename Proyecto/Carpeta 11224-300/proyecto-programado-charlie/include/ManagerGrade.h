#ifndef MANAGERGRADE_H
#define MANAGERGRADE_H
#include "Subject.h"
#include <iostream>
#include <sstream>

using namespace std;
class ManagerGrade{
private:
    float gradeList[2][10];
    //Subject subjectList [10];
    float average = 0;
    int cantGrade = 0;
    int cantSubject= 0 ;
public:

    ManagerGrade();
    //insert
    void insertGrade(int subjectCode, float grade);
    //void insertSubjet(Subject & subject);
    void showGradeMatrix();
    //void subjectVector();
    float getAverage();
    void setGrade(int index, float grade);
    const float* getGradeList() const;
    int getCantGrade() const;
    int findSubjectIndex(int subjectCode) const;

};
#endif
