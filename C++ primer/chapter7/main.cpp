#include"Sales_data.cpp"
using namespace std;
int main()
{
    Sales_data s1;
    Sales_data s2("03596155");//
    Sales_data s3("03586200", 3, 50);
    Sales_data s4(cin);
    s1.combine(string("2345"));
    print(cout,s1)<<endl<<endl;
    print(cout,s2)<<endl<<endl;
    print(cout,s3)<<endl<<endl;
    print(cout,s4)<<endl<<endl;
    system("pause");
    return 0;
}