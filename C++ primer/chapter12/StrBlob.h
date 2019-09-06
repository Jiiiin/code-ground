#ifndef STRBLOB_H
#define STRBLOB_H
#include<iostream>
#include<string>
#include<sstream>
#include<vector>
#include<memory>
using namespace std;
class StrBlob
{
public:
    typedef std::vector<std::string>::size_type size_type;
    StrBlob();
    StrBlob(std::initializer_list<std::string> il);
    size_type size() const {return data->size();}
    bool empty() const { return data->empty();}
    //add and delete 
    void push_back(const std::string &s){ data->push_back(s);}
    void pop_back();
    //
    std::string& front();
    std::string& back();
private:
    std::shared_ptr<std::vector<std::string>> data;
    void check(size_type i, const std::string &msg) const;
};
StrBlob::StrBlob():data(make_shared<vector<string>>()) {}
StrBlob::StrBlob(initializer_list<string> il):data(make_shared<vector<string>>(il)){};
void StrBlob::check (size_type i, const std::string &msg)const
{
    if(i>data->size())
        throw out_of_range(msg);
}
void StrBlob::pop_back()
{
    check(0,"pop_back on empty StrBlob");
    data->pop_back();
}
std::string&  StrBlob::back()
{
    check(0,"back on empty StrBlob");
    return data->back();
}
std::string& StrBlob::front()
{
    check(0,"front on empty StrBlob");
    return data->front();
}
#endif
