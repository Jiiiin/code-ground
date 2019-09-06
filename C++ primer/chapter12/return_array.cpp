#include<iostream>
#include<vector>
using namespace std;

void findneighborhood(vector<int>&a)
{
    while(a.size()>6)
    {
        a.erase(a.end()-1);
    }
    //return a;
}
int main()
{
    vector<int>a={1,2,3,4,5,6,7,8,9};
    findneighborhood(a);
    for(auto &b:a)
        cout<<b<<" ";
    cout<<endl;
    system("pause");
    return 0;
}