#pragma once
#ifndef PERSON_H
#define PERSON_H
#include <string>
#include <iostream>
class Person {
    friend std::ostream &print(std::ostream &, const Person &);
    friend std::istream &read(std::istream &, Person &);
public:
    Person() = default;
    std::string get_name() const { return name; }
    std::string get_addr() const { return addr; }
private:
    std::string name;
    std::string addr;
};
extern std::ostream &print(std::ostream &, const Person &);
extern std::istream &read(std::istream &, Person &);
#endif