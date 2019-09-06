#include<iostream>
#include<memory>
#include<cstring>
using namespace std;

int main()
{
    //12.23
    const char *c1="hello ";
    const char *c2="world";
    char *r=new char[strlen(c1)+strlen(c2)+1];
    strcpy(r,c1);
    strcat(r,c2);
    cout<<r<<endl;

    string s1="hello ";
    string s2="world";
    strcpy(r,(s1+s2).c_str());
    cout<<r<<endl;

    delete []r;

    //12.24
    char c;
    int l;
    char *rc=new char[20];
    while (cin.get(c))
    {
        if(isspace(c))
            break;
        rc[l++]=c;
        if(l==20)
            cout<<"up to the array size"<<endl;
        break;
    }
    rc[l]=0;
    cout<<rc<<endl;
    delete []rc;
    system("pause");
    return 0;

}