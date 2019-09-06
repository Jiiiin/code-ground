#include<iostream>
#include<memory>
using namespace std;
//12.14
struct destination{};
struct connection{};
connection connect(destination *pd)
{
    cout<<"open connection"<<endl;
    return connection();
}
void disconnect(connection c)
{
    cout<<"close connection"<<endl;
}
//未使用shared_ptr的版本
void f(destination &d)
{
    cout<<"直接管理connect"<<endl;
    connection c=connect(&d);
    //忘记调用disconnect关闭连接
    cout<<endl;
}
void end_connection(connection *p)
{
    disconnect(*p);
}
//使用shared_ptr的版本
void f1(destination &d)
{
    cout<<"用shared_ptr管理connect"<<endl;
    connection c=connect(&d);
    shared_ptr<connection>p(&c,end_connection);
    cout<<endl;
}
//12.15
void f2(destination &d)
{
    cout<<"用shared_ptr管理connect"<<endl;
    connection c=connect(&d);
    shared_ptr<connection>p(&c,[](connection *p){disconnect(*p);});
    cout<<endl;
}
int main()
{
    //12.14
    destination d;
    f(d);
    f1(d);
    system("pause");
    return 0;
}