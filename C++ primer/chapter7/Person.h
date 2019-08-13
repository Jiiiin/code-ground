#ifndef PERSON_H
#define PERSON_H
#include<iostream>
#include<string>
struct Person
{
friend std::ostream &print(std::ostream&,const Person&);
friend std::istream &read(std::istream&,Person&);
public:
    //constructor
    Person()=default;
    Person(const std::string &nam): name(nam) {}
    Person(const std::string &nam, const std::string &add):name(nam),address(add){}
    Person(std::istream &);
    //old member
    std::string forname()const{return name;}
    std::string foraddress()const{return address;}
private:
    std::string name;
    std::string address;
};
std::ostream &print(std::ostream&,const Person&);
std::istream &read(std::istream&,Person&);
#endif