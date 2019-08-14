#include"Sales_data.cpp"
#include<fstream>
using namespace std;
int main()
{
    ifstream input("E:/C++Learning/code-ground/C++ primer/chapter7/sales_data.txt");
    if (!input)
    {
        cout<<"can not open file!"<<endl;
        system("pause");
        return -1;
    }
    else
    {
        Sales_data s1;
        read(input,s1);
        cout<<s1.isbn()<<endl;
        system("pause");
        return 0;
    }
}