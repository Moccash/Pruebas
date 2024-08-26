#include "ManagerGrade.h"
#include <iostream>
#include <sstream>
using namespace std;

ManagerGrade::ManagerGrade() {
//managerGrade is build
}

void ManagerGrade::setGrade(int index, float grade) {
    gradeList[1][index] = grade;
}

const float *ManagerGrade::getGradeList() const {
    return &gradeList[0][0];
}

int ManagerGrade::getCantGrade() const {
    return cantGrade;
}

void ManagerGrade::insertGrade(int subjectCode, float grade) {
    gradeList [0][cantGrade] = subjectCode;
    gradeList [1][cantGrade]= grade;
    cantGrade++;
}

/*void ManagerGrade::insertSubjet(Subject& subject) {
    subjectList [cantSubject]= subject;
    cantSubject++;
}
 */

void ManagerGrade::showGradeMatrix() {
    cout<< "Class Code  "<<"Grade"<<endl;
    for (int i = 0; i < cantGrade; i++){
        for (int j= 0; j < 2; j++){
            cout<<"  "<<gradeList[j][i]<<"      ";
        }
        cout<< endl;

    }
}

float ManagerGrade::getAverage() {

    for(int i=0; i<cantGrade;i++){
        average += gradeList[1][i];
    }
    return average;
}
/*
void ManagerGrade::subjectVector() {
    cout<<" List of subject"<<endl;
    for (int i; i <cantSubject; i++){
         cout<< subjectList[i].getName()<<endl;
    }
}
 */

//to support the method setGrade by looking for the subjectCode
int ManagerGrade::findSubjectIndex(int subjectCode) const {
    for (int i = 0; i < cantGrade; i++) {
        if (gradeList[0][i] == subjectCode) {
            return i;
        }
    }
    return -1;
}
