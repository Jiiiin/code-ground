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
int main()
{
    cout << add({1, 2, 3, 4, 5, 6});
    system("pause");
    return 0;
}