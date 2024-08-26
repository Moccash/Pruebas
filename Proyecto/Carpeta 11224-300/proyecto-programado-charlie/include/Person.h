//
// Created by Mariana on 23/1/2024.
//

#ifndef MAIN_PERSON_H
#define MAIN_PERSON_H
#include <iostream>
#include <sstream>
using namespace std;

class Person {
private:
    string name;
    string surname;
    string id;
    int age;
public:
    explicit Person(const string &name, const string &surname, const string &id, int age);

    const string &getName() const;

    void setName(const string &name);

    const string &getSurname() const;

    void setSurname(const string &surname);

    const string &getId() const;

    void setId(const string &id);

    int getAge() const;

    void setAge(int age);

    Person();
    virtual string toString();
    virtual string toStringCsv() const;
    virtual ~Person();
};


#endif //MAIN_PERSON_H
