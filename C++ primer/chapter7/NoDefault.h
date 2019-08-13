#include<iostream>
#include<string>
#include<vector>
class NoDeFault
{
public:
    NoDeFault(int){};
};
class C
{
public:
    C(int i=0):member(i) {}
    NoDeFault member;
};
std::vector<NoDeFault>vec(10,NoDeFault(1));
std::vector<C>vec1(10);
