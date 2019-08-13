#include<iostream>
#include "Person.h"
Person::Person(std::istream &is)
{
    is>>this->name>>this->address;
}
std::ostream &print(std::ostream &os,const Person &pers)
{
    os<<pers.forname()<<" "<<pers.foraddress();
    return os;
}
std ::istream &read(std::istream &is,Person &pers)
{
    is>>pers.name>>pers.address;
    return is;
}
