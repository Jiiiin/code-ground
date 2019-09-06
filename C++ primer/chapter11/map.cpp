#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<list>
#include<map>
#include<set>
#include<algorithm>
using namespace std;
string& trans(string &s)
{
    for (auto p = 0; p < s.size(); p++)
    {
        if(s[p]>='A'&&s[p]<='Z')
            s[p]+=('a'-'A');
        else if(s[p]==','||s[p]=='.')
            s.erase(p,1);
    }
    return s;
}
//11.7
void Add_family(map<string, vector<string> >&families,const string &family)
{
    if(families.find (family)==families.end())
        families[family]=vector<string>();
}
void Add_child(map<string, vector<string> >&families, const string &family,const string &child)
{
    families[family].push_back(child);
}
pair<string, int> process(vector<string>&v)
{
        if(!v.empty())
            return {v.back(),v.back().size()};
        else
            return pair<string, int>();
}
//11.14
void add_family(map<string,vector<pair<string,string>>> &families,const string &family)
{
    if(families.find (family)==families.end ())
        families[family];
}
void add_child(map<string,vector<pair<string,string>>> &families,  const string &family, const string &child,const string &birthday)
{
    families[family].push_back({child,birthday});
}
int main()
{
    //11.4
    map<string, size_t> word_count;
    string word;
    while (cin>>word)
        ++word_count[trans(word)];
    for(const auto &w : word_count)
    cout<<w.first<<" occurs "<<w.second<<((w.second>1)?"times":"time")<<endl; 
    //11.7
    map<string, vector<string>>fam;
    Add_family(fam,"wang");
    Add_child(fam,"wang","xifeng");
    Add_family(fam,"li");
    Add_child(fam,"wang","xiaocao");
    Add_child(fam,"li","dazui");
    Add_family(fam,"wang");
    for (auto f : fam)
    {
        cout<<f.first<<" ";
        for (auto &c : f.second)
        {
            cout<<c<<" ";
        }
        cout<<endl;
    }
    //11.9
    ifstream in("E:\\C++Learning\\code-ground\\C++ primer\\chapter11\\in.txt");
    if(!in)
    {
        cout<<"failed to open infile!"<<endl;
        exit(1);
    }
    map<string,list<int>>strlin;
    string line;
    string str;
    int lineNo=0;
    while (getline(in,line))
    {
        ++lineNo;
        istringstream l_in(line);
        while (l_in>>str)
        {
            trans(str);
            strlin[str].push_back(lineNo);
        } 
    }
    for (auto &stri : strlin)
    {
        cout<<stri.first<<" ";
        for (auto &li:stri.second)
        {
            cout<<li<<" ";
        }
        cout<<endl;
    }
    //11.12
    ifstream in11("\\C++Learning\\code-ground\\C++ primer\\chapter11\\11.12.txt");
    if(!in11)
    {
        cout<<"failed to open infile."<<endl;
        exit(1);
    }
    vector<pair<string,int>> data;
    string s;
    int i;
    while (in>>s&&in>>i)
    {
        data.push_back(pair<string,int>(s,i));
        //等价形式
        //data.push_back({s,i});
        //data.push_back(make_pair(s,i));
    }
    for(const auto &d:data)
        cout<<d.first<<" "<<d.second<<endl;
    system("pause");
    return 0;
}