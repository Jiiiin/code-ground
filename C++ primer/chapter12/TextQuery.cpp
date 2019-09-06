#include<iostream>
#include<string>
#include<vector>
#include<fstream>
#include<sstream>
#include<map>
#include<set>
#include<memory>
using namespace std;
using line_no=vector<string>::size_type;
class QueryResult;
class TextQuery
{
public:   
    TextQuery(ifstream &);
    QueryResult query(const string&)const;
private:
    shared_ptr<vector<string>>file;
    map<string,shared_ptr<set<line_no>>> wm;
};
TextQuery::TextQuery(ifstream &is):file(new vector<string>)
{
    string text;
    while (getline(is,text))
    {
        file->push_back(text);
        int n=file->size()-1;
        istringstream line(text);
        string word;
        while (line>>word)
        {
            auto &lines=wm[word];
            if(!lines)
                lines.reset(new set<line_no>);
            lines->insert (n);
        }        
    }    
}
class QueryResult
{
friend ostream& print(ostream&,const QueryResult&);
public:
    QueryResult(string s, shared_ptr<set<line_no>> p, shared_ptr<vector<string>> f):
        sought(s), lines(p), file(f) {};
private:
    string sought;
    shared_ptr<set<line_no>> lines;
    shared_ptr<vector<string>> file;
};
QueryResult TextQuery::query(const string &s)const
{
    static shared_ptr<set<line_no>> nodata(new set<line_no>);
    auto loc=wm.find(s);
    if(loc==wm.end ())
        return QueryResult(s,nodata,file);
    else
        return QueryResult(s,loc->second,file);   
}
ostream & print(ostream &os, const QueryResult &qr)
{
    os<<qr.sought<<"occurs "<<qr.lines->size ()<<"times"<<endl;
    for(auto num:*qr.lines)
        os<<"\t(line "<<num+1<<")"<<*(qr.file->begin()+num)<<endl;
    return os;
}
void runquery(ifstream &infile)
{
    TextQuery tq(infile);
    while (true)
    {
        string s;
        if(!(cin>>s)||s=="q")
            break;
        print(cout,tq.query(s))<<endl;
    }   
}
int main()
{
    ifstream infile("E:\\C++Learning\\code-ground\\C++ primer\\chapter12\\textquery.txt");
    runquery(infile);
    system("pause");
    return 0;
}