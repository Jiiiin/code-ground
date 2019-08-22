#include<iostream>
#include"ReadDate.h"
using namespace std;

ReadDate::ReadDate(string &str)
{
    int p;
    size_t q;
    p=str.find_first_of("0123456789");
    if(p==string::npos)
        throw invalid_argument("No digits，illegal date.");
    if (p>0)
    {
        month=get_month(str,p);
        day=get_day(str,month,p);
        if(str[p]!=' '&&str[p]!=',')
            throw invalid_argument("illegal separator.");
        p++;
        year=get_year(str,p);
    }
    else
    {
        month=stoi(str,&q);
        p=q;
        if(month<1||month>12)
            throw invalid_argument("illegal month.");
        if(str[p++]!='/')
            throw invalid_argument("illegal separator.");    
        day=get_day(str,month,p);
        if(str[p++]!='/')
            throw invalid_argument("illegal separator.");  
        year=get_year(str,p);        
    }
}
ostream &operator<<(ostream &os,const ReadDate &d)
{
    os<<d.getY()<<"year"<<d.getM()<<"month"<<d.getD()<<"day";
    return os;
}

int main()
{
    string dates[]={"Jan 1,2014","February 1 2014","3/1/2014","Jn 1,2014"};
    try
    {
        for(auto &ds:dates)
        {
            ReadDate d(ds);
            cout<<d<<endl;
        }
    }
    catch(invalid_argument e)
    {
        std::cerr << e.what() << '\n';
    }
    system("pause");
    return 0;
}