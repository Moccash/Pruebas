//
// Created by LenovoE450 on 10/02/2024.
//

#ifndef MAIN_BINARYFILEMANAGER_H
#define MAIN_BINARYFILEMANAGER_H
#include <vector>
#include <fstream>
#include "Student.h"

class BinaryFileManager {

public:

    static void saveInformation(const std::vector<Student>& newStudents, const std::vector<Subject>& newSubjects, const std::string& filename);
    static std::pair<std::vector<Student>, std::vector<Subject>> loadInformation(const std::string& filename);
    static void emptyInformation(const std::string& filename);
    static std::ostream &writeStudent(ostream &out, const Student &student);
    static istream& readStudent(istream& in, Student& student);
    static std::ostream &writeSubject(std::ostream &out, const Subject &subject);
    static istream& readSubject(istream& in, Subject& subject);
};


#endif //MAIN_BINARYFILEMANAGER_H
