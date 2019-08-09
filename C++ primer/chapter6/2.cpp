#include<iostream>
#include<vector>
#include<string>
using namespace std;
//使用标记指定数组长度
void printcstr(const char *cp)
    {
        if(cp)
        {
            while(*cp)
            {
                ++cp;
            }
            cout << *(--cp);
        }
    }
 //使用标准库规范
 void printstr1(const char *beg,const char *end)
 {
     while(beg!=end)
     {
         cout << *beg++ << endl;
     }
 }
 //显式传递一个表示数组大小的形参
 void printstr2(const char *a,const size_t sz)
 {
     const char *p = a;//把a的初始值预存起来
     //while和for两种方法
     while (a != (p + sz))
     {
         cout << *a++ << endl;
     } 
     /* for (size_t i = 0; i != sz;++i)
     {
         cout << a[i] << endl;
     } */
 }
 //数组引用形参
 void printstr3(char (&arr)[10])
 {
     for(auto &a:arr)
     {
         cout << a << endl;
     }
 }
 int compare(int q, int *p)
 {
     return (q > *p) ? q : *p;
 }
 void exchange(int *(&p),int *(&q))
 {
     int *mid = p;
     p = q;
     q = mid;
 }
int main()
{
    //char cstr[] = "jinbendan";
    //int iarr[] = {1, 2, 3, 4};
    //printcstr(cstr);
    //printstr1(cstr, end(cstr));
    //printstr2(cstr, end(cstr) - begin(cstr));
    //printstr3(cstr);
    int i = 1, j = 9;
    int *m = &i, *n = &j;
    cout << compare(i, &j) << endl;
    exchange(m, n);
    cout << i << " " << j << endl;
    cout << *m << " " << *n << endl;
    system("pause");
    return 0;
}