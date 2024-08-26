//
// Created by Mariana on 23/1/2024.
//

#include "Person.h"

Person::Person (const string &name, const string &surname, const string &id, int age) : name(name), surname(surname), id(id), age(age) {}

Person::Person() {}

string Person::toString() {
    stringstream s;
    s<<"Nombre: "<<name<<endl;
    s<<"Apellido: "<<surname<<endl;
    s<<"Identificacion: "<<id<<endl;
    s<<"Edad: "<<age<<endl;
    return s.str();
}

string Person::toStringCsv() const {
    stringstream s;
    s<<name<<","<<surname<<","<<id<<","<<age;
    return s.str();
}

Person::~Person() {

}

const string &Person::getName() const {
    return name;
}

void Person::setName(const string &name) {
    Person::name = name;
}

const string &Person::getSurname() const {
    return surname;
}

void Person::setSurname(const string &surname) {
    Person::surname = surname;
}

const string &Person::getId() const {
    return id;
}

void Person::setId(const string &id) {
    Person::id = id;
}

int Person::getAge() const {
    return age;
}

void Person::setAge(int age) {
    Person::age = age;
}
