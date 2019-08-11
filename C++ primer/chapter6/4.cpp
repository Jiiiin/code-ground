//#pragma once
#include<iostream>
#include<vector>
#include<string>
using namespace std;
const string & shorterstring(const string &s1, const string &s2)
{
    return s1.size() <= s2.size() ? s1 : s2;
}
string & shorterstring(string &s1, string &s2)
{
    auto &r = shorterstring(const_cast<const string &> (s1), const_cast<const string &> (s2));
    return const_cast<string&>(r);
}
char def = ' ';
int ht = 60, wd = 80;
void screen(int = ht,int = wd,char=def)
{
    cout << "ht: " << ht << "   wd: " << wd << "   char: " << def << endl;
}
//局部变量不能作为默认实参，
//除此之外，只要表达式的类型能转换成形参所需类型，该表达式就能作为默认实参
void f2()
{
    def = '*';
    int wd = 100; //隐藏了外层的wd,但是么有改变默认值
    screen();//调用scren(60,80,'*')
}
string make_plural(const size_t ctr, const string & word,const string & end="s")
{
    return ctr > 1 ? word + end : word;
}
//6.54 声明一个vector对象，令其元素是指向函数的指针
int func(int, int);
vector<decltype(func) *> p;
//6.55
int func1(int a, int b) { return a + b; }
int func2(int a, int b) { return a - b; }
int func3(int a, int b) { return a * b; }
int func4(int a, int b) { return a / b; }
decltype(func) *p1 = func1, *p2 = func2, *p3 = func3, *p4 = func4;
vector<decltype(func) *> VF = {p1, p2, p3, p4};
//6.56
void compute(int a,int b, int(*p)(int, int))
{
    cout<<p(a,b)<<endl;
}
int main()
{
    /* string s1 = "jinbanden";
    string s2 = "jinpig";
    cout << shorterstring(s1, s2); */
    /* int wd = 85, htt = 15;
    char def = ' ';
    screen(htt, wd, def); 
    f2();
    cout << "success 单数形式: " << make_plural(1, "success", "es") << endl;
    cout << "success 复数形式: " << make_plural(2, "success", "es") << endl;
    cout << "failure 单数形式: " << make_plural(1, "failure") << endl;
    cout << "failure 复数形式: " << make_plural(2, "failure") << endl;*/
    int i=5,j=10;
    for(auto c:VF)
    {
        compute(i,j,c);
    }
    system("pause");
    return 0;
}