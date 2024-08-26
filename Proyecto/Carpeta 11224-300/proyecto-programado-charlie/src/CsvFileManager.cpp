//
// Created by Mariana on 3/2/2024.
//

#include "CsvFileManager.h"

// Escritura
void CsvFileManager::saveFile(const vector<Student> &students, std::string filename) {

    ofstream file;
    file.open(filename, ios::trunc);
    if (file.is_open()) {

        file << "Nombre,Apelllido,Identificacion,Edad,Carrera" << endl;

        for (const auto &student: students) {
            file << student.toStringCsv();
        }

    } else {
        cerr << "Error al abrir el archivo: " << filename << endl;
    }
    file.close();
}

vector<Student> CsvFileManager::readFile(std::string filename) {
    vector<Student> studentList;
    ifstream file(filename, ios::in);
    string name, surname, id, age, major, line;
    if (file.is_open()) {
        getline(file, line); // Omitir la primera línea (encabezados)
        while (getline(file, line)) {
            stringstream ss(line);
            getline(ss, name, ',');
            getline(ss, surname, ',');
            getline(ss, id, ',');
            getline(ss, age, ',');
            getline(ss, major, ',');
            Student s = Student(name, surname, id, stoi(age), major);
            studentList.push_back(s); // Cambio aquí: Acceder al vector directamente

        }
    } else {
        cerr << "Error al abrir el archivo: " << filename << endl;
    }

    file.close();
    return studentList;
}
