#include<iostream>
#include<stdexcept>
#include<string>
#include<sstream>
#include<fstream>
#include<vector>
using namespace std;
istream& process(istream &is)
{
    vector<int>vec;
    int a;
    while (is>>a,!is.eof ())
    {
        if (is.bad ())
            throw runtime_error("IO stream error");
        if (is.fail())
        {
            cerr<<"data error,try again"<<endl;
            is.clear ();
            is.ignore(100,'\n');
            continue;
        }
        vec.push_back(a);
    }
    for (size_t i = 0; i < vec.size(); i++)
    {
        cout<<vec[i]<<" ";
    }
    return is;
}
int main()
{
    /* process(cin); 
    cout<<endl;*/
    vector<string>vec;
    /* vec.push_back("E:/C++Learning/code-ground/C++ primer/inputfile.txt");
    vec[1]="outputfile.txt"; */
    ifstream input("E:/C++Learning/code-ground/C++ primer/chapter8/inputfile.txt");
    //ofstream output("E:/C++Learning/code-ground/C++ primer/chapter8/outputfile.txt",ofstream::app);
    string s1;
    if (input)
    {
        while (getline(input,s1))
        {
            vec.push_back(s1);
            //output<<s1;
        }
    }
    else
    {
        cout<<"can not open file!";
    }
    input.close();
    //decltype(vec.size()) it=0;
    vector<string>::iterator it=vec.begin();
    while ( it!=vec.end())
    {
        istringstream record(*it);
        string word;
        while(record>>word)
            cout<<word<<endl;
        cout<<endl;
        ++it;
    }
    cout<<endl;
    system("pause");
    return 0;
}
