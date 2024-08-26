//
// Created by LenovoE450 on 10/02/2024.
//

#include "BinaryFileManager.h"

std::ostream &BinaryFileManager::writeStudent(std::ostream &out, const Student &student) {

    int nameLength = student.getName().length();
    out.write(reinterpret_cast<const char*>(&nameLength), sizeof(int));
    out.write(student.getName().c_str(), nameLength);

    int surnameLength = student.getSurname().length();
    out.write(reinterpret_cast<const char*>(&surnameLength), sizeof(int));
    out.write(student.getSurname().c_str(), surnameLength);

    int idLength = student.getId().length();
    out.write(reinterpret_cast<const char*>(&idLength), sizeof(int));
    out.write(student.getId().c_str(), idLength);

    int age = student.getAge();
    out.write(reinterpret_cast<const char*>(&age), sizeof(int));

    int majorLength = student.getMajor().length();
    out.write(reinterpret_cast<const char*>(&majorLength), sizeof(int));
    out.write(student.getMajor().c_str(), majorLength);

    return out;
}

std::ostream &BinaryFileManager::writeSubject(std::ostream &out, const Subject &subject) {

    int nameLength = subject.getName().length();
    out.write(reinterpret_cast<const char*>(&nameLength), sizeof(int));
    out.write(subject.getName().c_str(), nameLength);

    int code = subject.getCode();
    out.write(reinterpret_cast<const char*>(&code), sizeof(int));

    int credits = subject.getCredit();
    out.write(reinterpret_cast<const char*>(&credits), sizeof(int));

    return out;
}

void BinaryFileManager::saveInformation(const std::vector<Student>& newStudents, const std::vector<Subject>& newSubjects, const std::string& filename) {
    // Load existing data from the file
    auto existingData = loadInformation(filename);
    std::vector<Student> existingStudents = existingData.first;
    std::vector<Subject> existingSubjects = existingData.second;

    // Merge existing data with new data
    existingStudents.insert(existingStudents.end(), newStudents.begin(), newStudents.end());
    existingSubjects.insert(existingSubjects.end(), newSubjects.begin(), newSubjects.end());

    // Save all data to the file
    std::ofstream outputFile(filename, std::ios::binary);
    if (!outputFile.is_open()) {
        std::cerr << "Error opening output file: " << filename << std::endl;
        return;
    }

    int numStudents = existingStudents.size();
    outputFile.write(reinterpret_cast<const char *>(&numStudents), sizeof(int));
    for (const Student &student : existingStudents) {
        writeStudent(outputFile, student);
    }

    int numSubjects = existingSubjects.size();
    outputFile.write(reinterpret_cast<const char*>(&numSubjects), sizeof(int));
    for (const Subject& subject : existingSubjects) {
        writeSubject(outputFile, subject);
    }

    outputFile.close();
}

std::istream &BinaryFileManager::readStudent(std::istream &in, Student &student) {
    int nameLength, surnameLength, idLength, majorLength, age;

    in.read(reinterpret_cast<char*>(&nameLength), sizeof(int));
    std::string name;
    name.resize(nameLength);
    in.read(&name[0], nameLength);
    student.setName(name);

    in.read(reinterpret_cast<char*>(&surnameLength), sizeof(int));
    std::string surname;
    surname.resize(surnameLength);
    in.read(&surname[0], surnameLength);
    student.setSurname(surname);

    in.read(reinterpret_cast<char*>(&idLength), sizeof(int));
    std::string id;
    id.resize(idLength);
    in.read(&id[0], idLength);
    student.setId(id);

    in.read(reinterpret_cast<char*>(&age), sizeof(int));
    student.setAge(age);

    in.read(reinterpret_cast<char*>(&majorLength), sizeof(int));
    std::string major;
    major.resize(majorLength);
    in.read(&major[0], majorLength);
    student.setMajor(major);

    return in;
}

std::istream &BinaryFileManager::readSubject(std::istream &in, Subject &subject) {
    int nameLength, code, credits;

    in.read(reinterpret_cast<char*>(&nameLength), sizeof(int));
    std::string name;
    name.resize(nameLength);
    in.read(&name[0], nameLength);
    subject.setName(name);

    in.read(reinterpret_cast<char*>(&code), sizeof(int));
    subject.setCode(code);

    in.read(reinterpret_cast<char*>(&credits), sizeof(int));
    subject.setCredit(credits);

    return in;
}

std::pair<std::vector<Student>, std::vector<Subject>> BinaryFileManager::loadInformation(const std::string& filename) {
    std::vector<Student> students;
    std::vector<Subject> subjects;
    Student student;
    Subject subject;

    std::ifstream inputFile(filename, std::ios::binary);
    if (!inputFile.is_open()) {
        std::cerr << "Error opening input file: " << filename << std::endl;
        return {students, subjects};
    }

    int numStudents;
    inputFile.read(reinterpret_cast<char*>(&numStudents), sizeof(int));

    if (numStudents > 0) {
        for (int i = 0; i < numStudents; ++i) {
            readStudent(inputFile, student);
            students.push_back(student);
        }
    }


    int numSubjects;
    inputFile.read(reinterpret_cast<char*>(&numSubjects), sizeof(int));

    if (numSubjects > 0) {
        for (int i = 0; i < numSubjects; ++i) {
            readSubject(inputFile, subject);
            subjects.push_back(subject);
        }
    }

    inputFile.close();

    return {students, subjects};
}


void BinaryFileManager::emptyInformation(const std::string& filename) {
    std::ofstream outputFile(filename, std::ios::binary | std::ios::trunc);
    if (!outputFile.is_open()) {
        std::cerr << "Error opening output file: " << filename << std::endl;
        return;
    }

    // Vaciar el archivo escribiendo un entero 0 para el número de estudiantes y materias
    int numStudents = 0;
    outputFile.write(reinterpret_cast<const char*>(&numStudents), sizeof(int));

    int numSubjects = 0;
    outputFile.write(reinterpret_cast<const char*>(&numSubjects), sizeof(int));

    outputFile.close(); // Asegúrate de cerrar el archivo después de vaciarlo
}
