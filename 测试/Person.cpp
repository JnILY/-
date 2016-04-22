#include "Person.h"
std::ostream &print(std::ostream &os, const Person &p)
{
    os << "Name: " << p.name << "\nAddr: " << p.addr << std::endl;
    return os;
}


std::istream &read(std::istream &is, Person &p)
{
    is >> p.name >> p.addr;
    return is;
}