#include<iostream>
#include<vector>
#include<string>
#include<list>
#include<algorithm>
#include<numeric>
#include<functional>
#include<iterator>
using namespace std;
using namespace std::placeholders;
bool isShorter(const string &s1, const string &s2)
{
    return s1.size()<s2.size();
}
bool SizeMore5(const string &s)
{
    return s.size()>=5;
}
void ElimDups(vector<string>&words)
{
    sort(words.begin(),words.end());
    //sort(words.begin(),words.end(),isShorter);
    auto end_unique=unique(words.begin(),words.end());
    words.erase(end_unique,words.end());
}
void biggies(vector<string> &words,vector<string>::size_type sz)
{
    ElimDups(words);
    stable_sort(words.begin(), words.end(), [](const string &a,const string &b){return a.size()<b.size();});
    auto wc=find_if(words.begin(), words.end(), [sz](const string &s){return s.size()>=sz;});
    auto count=words.end()-wc;
    for_each(wc,words.end(),[](const string &s){cout<<s<<" ";});
    cout<<endl;
}
void Mutable_lambda()
{
    int i=5;
    auto f=[i]()mutable->bool{if(i>0){--i;return false;}else return true;};
    for(int j=0;j<6;++j)
        cout<<f()<<" ";
    cout<<endl;
}
//10.22
bool check_size(const string &s, string::size_type sz)
{
    return s.size()<=sz;
}
void Biggies(vector<string> &words,vector<string>::size_type sz)
{
    auto bc=count_if(words.begin(),words.end(),bind(check_size,_1,sz));
    cout<<bc<<endl;
}
//10.24
void BIggies(vector<int> &vi,const string &s)
{
    auto p=find_if(vi.cbegin(),vi.cend(),bind(check_size,s,_1));
    cout<<"the No."<<p-vi.begin()+1<<"number: "<<*p<<" match the condition."<<endl;
}
int main()
{
    vector<int>vi{1,2,3,4,4,4,4,5};
    vector<string>vstr{"the","quick","red","fox","jumps","over","the","slow","red","turtle"};
    list<string>lst{"a","an","the","the","the","a"};
    int a=count(vi.cbegin(),vi.cend(),4);
    cout<<a<<endl;
    int b=count(lst.cbegin(),lst.cend(),"the");
    cout<<b<<endl;
    int sum=accumulate(vi.cbegin(),vi.cend(),0);
    cout<<sum<<endl;
    fill_n(back_inserter(vi),5,0);
    ElimDups(vstr);
    stable_sort(vstr.begin(),vstr.end(),isShorter); 
    auto end_parti=partition(vstr.begin(),vstr.end(),SizeMore5);
    for (auto beg = vstr.cbegin(); beg != end_parti; beg++)
    {
        cout<<*beg<<" ";
    }
    biggies(vstr,5);
    Mutable_lambda();
    system("pause");
    return 0;
}
