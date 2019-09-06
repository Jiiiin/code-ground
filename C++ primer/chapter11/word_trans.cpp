#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<map>
using namespace std;
map<string,string> buildMap(ifstream &map_file)
{
    map<string,string> trans_map;
    string key;
    string value;
    while (map_file>>key&&getline(map_file,value))
    {
        if(value.size()>1)
            trans_map[key]=value.substr(1);
        else
            throw runtime_error("no rule for "+key);
    }
    return trans_map;
}
const string& transform(const string &word, const map<string,string> &trans_map)
{
    auto map_it=trans_map.find (word);
    if(map_it!=trans_map.cend ())
        return map_it->second;
    else
        return word;
}
void word_transform(ifstream &map_file, istream &input)
{
    auto trans_map=buildMap(map_file);
    string text;
    while (getline(input,text))
    {
        istringstream stream(text);
        string word;
        bool firstword=true;
        while (stream>>word)
        {
            if(firstword)
                firstword=false;
            else
                cout<<" ";
            cout<<transform(word,trans_map);
        }
        cout<<endl;
    }
}
int main()
{
    ifstream map_file("E:\\C++Learning\\code-ground\\C++ primer\\chapter11\\map_file.txt");
    ifstream input("E:\\C++Learning\\code-ground\\C++ primer\\chapter11\\input.txt");
    word_transform(map_file,input);
    system("pause");
    return 0;
}