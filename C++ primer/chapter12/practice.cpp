#include<iostream>
#include<string>
#include<vector>
#include<memory>
using namespace std;
//12.6
vector<int>* func1()
{
    return new vector<int>();
}
void func2(vector<int> *pv)
{
    int i;
    while (cin>>i)
    {
        (*pv).push_back(i);
    }
}
void func3(vector<int> *pv)
{
    for(const auto &i:*pv)
        cout<<i<<" ";
    cout<<endl;
}
//12.7
shared_ptr<vector<int>> funs1()
{
    return make_shared<vector<int>>();
}
void funs2(shared_ptr<vector<int>> p)
{
    int i;
    while(cin>>i)
        p->push_back(i);
}
void funs3(shared_ptr<vector<int>> p)
{
    for(const auto &i:*p)
        cout<<i<<" ";
    cout<<endl;
}
int main()
{
    //12.6
    /* auto vi=func1();
    if(!vi)
    {
        cout<<"lack of memory"<<endl;
        return -1;
    }
    func2(vi);
    func3(vi);
    delete vi;
    vi=nullptr; */
    //12.7
    auto p=funs1();
    funs2(p);
    funs3(p);
    system("pause");
    return 0;
}