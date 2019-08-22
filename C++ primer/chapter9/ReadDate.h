#ifndef READDATE_H
#define READDATE_H
#include<iostream>
#include<string>
#include<stdexcept>
//#pragma once
using namespace std;
class ReadDate
{
public:
    friend ostream& operator<<(ostream&,const ReadDate&);
    ReadDate()=default;
    ReadDate(std::string &);
    unsigned getY()const{return year;}
    unsigned getM()const{return month;}
    unsigned getD()const{return day;}
private:
    unsigned year;
    unsigned month;
    unsigned day;
};
const string month[]={"January","February","March","April","May","June","July",
                        "August","September","October","November","December"};
const string month_abbr[]={"Jan","Feb","Mar","Apr","May","Jun","Jul",
                        "Aug","Sept","Oct","Nov","Dec"};
const int days[]={31,28,31,30,31,30,31,31,30,31,30,31};
inline int get_month(string &ds, int &end_of_month)
{
    int i,j;
    for(i=0;i<12;i++)
    {
        //检查每个字符是否与月份简称相等
        for(j=0;j<month_abbr[i].size();j++)
            if(ds[j]!=month[i][j]) //不是此月简写
                break;
            if(j==month_abbr[i].size())//与简称匹配
                break;
    }
    if (i==12)
        throw invalid_argument("不是合法月份");
    if(ds[j]==' ')
    {
        end_of_month=j+1;
        return i+1;
    }
        
    for(;j<month[i].size();j++)
        if (ds[j]!=month[i][j])
            break;
    if(j==month[i].size()&&ds[j]==' ')
    {
        end_of_month=j+1;
        return i+1;   
    }
     throw invalid_argument("不是合法月份");   
}

inline int get_day(string &ds, int month,int &p)
{
    size_t q;
    int day=stoi(ds.substr(p),&q);
    if (day<1||day>days[month])
        throw invalid_argument("不是合法日期值");
    p+=q;
    return day;
}
inline int get_year(string &ds,int &p)
{
    size_t q;
    int year=stoi(ds.substr(p),&q);
    if(p+q<ds.size())
        throw invalid_argument("非法结束内容");
    return year;
}
#endif