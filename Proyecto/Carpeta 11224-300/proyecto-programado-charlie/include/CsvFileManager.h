//
// Created by Mariana on 3/2/2024.
//

#ifndef MAIN_CSVFILEMANAGER_H
#define MAIN_CSVFILEMANAGER_H
#include <iostream>
#include <fstream>
#include <vector>
#include "Student.h"
using namespace std;


class CsvFileManager {
public:
    static void saveFile(const vector<Student> &students, string filename);
    static vector<Student> readFile(string filename);
};

#endif //MAIN_CSVFILEMANAGER_H
