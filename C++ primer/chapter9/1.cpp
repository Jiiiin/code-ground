#include<iostream>
#include<string>
#include<vector>
#include<list>
#include<forward_list>
#include<deque>
using namespace std;
//9.4
bool search(vector<int>&vect,int val)
{
    auto beg=vect.begin(),en=vect.end();
    while (beg!=en)
    {
        if(*beg==val)
            return true;
        else
            ++beg;
        }
    return false;
}
//9.5
using it=vector<int>::iterator;
it search1(vector<int>&vect, int val)
{
    auto beg=vect.begin(),en=vect.end();
    while (beg!=en)
    {
        if(*beg==val)
            return beg;
        else
            ++beg;
    }
    if(beg==en)
        cout<<"no data is available";
    return beg;
}
//9.28
void search_insert(forward_list<string> &flst, string str1, string str2)
{
    auto prev=flst.before_begin();
    auto curr=flst.begin();
    while (curr!=flst.end())
    {
        if(*curr==str1)
        {
            flst.insert_after(curr,str2);
            return;
        }
        else
        {
            prev=curr;
            ++curr;
        }
    }
    if (curr==flst.end())
    {
        //--curr;
        flst.insert_after(prev,str2);
        return;
    }  
}
//9.43
void ReplaceStr(string &s,const string &oldstr,const string &newstr)
{
    auto beg=s.begin();
    auto sizeold=oldstr.size();
    while (beg<=s.end()-sizeold)
    {
        string detect=s.substr(beg-s.begin(),sizeold);
        if(detect==oldstr)
        {
            s.insert(beg-s.begin(),newstr);
            beg=beg+newstr.size()+1;
        }
        else
        {
            ++beg;
        }
    }
}

int main()
{
    string sns="a an the am jin pig";
    ReplaceStr(sns,"jin","jin bendan");
    cout<<sns<<endl;
    cin.clear();cin.sync();
    cin.get();
    /* list<int> count{2,3,4,5,6,7,8};
    vector<int> vec{1,2,3,4,5,6};
    vector<double> vdl(count.begin(),count.end());
    vector<double> vdv(vec.begin(),vec.end());
    list<string> names;
    vector<const char*> oldstyle{"a","an","the"};
    names.assign(oldstyle.cbegin(),oldstyle.cend());
    auto maxsi=names.max_size();
    cout<<search(vec,8);
    search1(vec,4); 
    //9.18
    deque<string>des;
    string s;
    while (cin>>s)
    {
        des.push_back(s);
    }
    for(auto beg=des.cbegin();beg!=des.cend();++beg)
    {
        cout<<*beg<<" ";
    }
    //9.20
   list<int>ilist{0,1,2,3,4,5,6,7,8,9};
    deque<int>deq1;//jishu
    deque<int>deq2;//oushu
    for(auto beg=ilist.cbegin();beg!=ilist.cend();++beg)
    {
        if(*beg%2)
            deq1.push_back(*beg);
        else
            deq2.push_back(*beg); 
    } 
    //9.22
    vector<int>ivector{0,1,2,3,4,5,6,7,8,9};
    auto iter=ivector.begin();
    int new_ele=0,some_val=4;
    auto org_size=ivector.size();
    while (iter!=(ivector.begin()+org_size/2+new_ele))
    {
        if (*iter==some_val)
        {
            iter=ivector.insert(iter,2*some_val);
            new_ele++;
            iter++;iter++;
        }
        else
        {
            iter++;
        }
    }
    for(auto iter=ivector.cbegin();iter!=ivector.end();++iter)
    {
        cout<<*iter<<" ";
    }
    //9.27
    forward_list<int>flst{0,1,2,3,4,5,6,7,8,9};
    auto prev=flst.before_begin();
    auto curr=flst.begin();
    while (curr!=flst.end())
    {
        if(*curr&1)
            curr=flst.erase_after(prev);
        else
        {
            prev=curr;
            ++curr;
        }
    }
    forward_list<string>fstring{"a","an","the","am","jin","pig"};
    search_insert(fstring,"jin","big");
    auto beg=fstring.begin();
    while (beg!=fstring.end())
    {
        cout<<*beg++<<" ";
    } 
    //
    vector<char>vc={'h','e','l','l','o'};
    string sn(vc.data(), vc.size());
    cout<<endl; */
    //system("pause");
    system("pause");
    return 0;
}
