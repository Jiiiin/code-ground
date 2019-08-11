#include<iostream>
#include<vector>
#include<string>
using namespace std;
//main处理命令行选项
/* int main(int argc,char *argv[])
{
    string str;
    for (int i = 0; i != argc;++i)
    {
        str += argv[i];
    }
    cout << str << endl;
    system("pause");
    return 0;
} */

//6.26 计算列表中所有元素的和
int add(initializer_list<int>il)
{
    auto sum = 0;
    for(const auto &c:il)
    {
        sum += c;
    }
    return sum;
}
//引用返回左值
char &get_val(string &s,size_t ix)
{
    return s[ix];
}
int &get(int *array,size_t sz)
{
    return array[sz];
}
//使用递归输出vector对象的内容
void print(vector<int>vInt,unsigned index)
{
    unsigned sz = vInt.size();
    if(!vInt.empty() && index<sz)
    {
        cout << vInt[index] << endl;
        print(vInt, index + 1);
    }
}

string s[] = {"jinbendan", "jinbendan", "jinbendan", "jinbendan",
              "jinbendan", "jinbendan", "jinbendan", "jinbendan", 
              "jinbendan", "jinbendan"};
//返回数组的引用
string (&refstr1(int i))[10]
{
    return s;
}
//使用类型别名
typedef string arrT[10];
arrT& refstr2(int i)
{
    return s;
}
//使用decltype关键字
decltype(s)& refstr3(int i)
{
    return s;
}
//使用尾置返回类型
auto refstr4(int i)->string(&)[10]
{
    return s;
}
int odd[] = {1, 3, 5, 7, 9};
int even[] = {0, 2, 4, 6, 8};
decltype(odd)& refint(int i)
{
    return (i % 2) ? odd : even;
}
int main()
{
    //cout << add({1, 2, 3, 4, 5, 6});
    /* string s("a value");
    get_val(s, 0) = 'A';
    cout << s << endl; 
    int ia[10];
    for (size_t i = 0; i != 10; ++i)
    {
        get(ia, i) = i;
        cout << get(ia, i) << endl;
    }
    */
    /* vector<int> v = {1, 2, 3, 4, 5, 6};
    print(v, 0); */
    /* cout << (refstr1(0))[0] << endl;
    cout << (refstr2(0))[0] << endl;
    cout << (refstr3(0))[0] << endl;
    cout << (refstr4(0))[0] << endl; */
    int (&result)[5] = refint(2);
    for(const auto &c:result)
    {
        cout << c << " ";
    }
    cout << endl;
    system("pause");
    return 0;
}