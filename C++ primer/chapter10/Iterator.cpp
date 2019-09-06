#include<iostream>
#include<fstream>
#include<vector>
#include<list>
#include<string>
#include<algorithm>
#include<numeric>
#include<functional>
#include<iterator>
using namespace std;
using namespace std::placeholders;
#include"Sales_item.h"
//10.33
void rerangedata(string infil, string outfil_1, string outfil_2)
{
    ifstream in(infil);
    ofstream out1(outfil_1), out2(outfil_2);
    if (!in)
    {
        cout<<"failed to open infile."<<endl;
        exit(1);
    }
    if (!out1)
    {
        cout<<"failed to open outfil_1."<<endl;
        exit(1);
    }
    if (!out2)
    {
        cout<<"failed to open outfil_2."<<endl;
        exit(1);
    }
    istream_iterator<int> in_iter(in), eof;
    ostream_iterator<int> out_iter1(out1," "), out_iter2(out2,"\n");
    while (in_iter!=eof)
    {
        if(*in_iter&1)
            *out_iter1++=*in_iter;
        else
            *out_iter2++=*in_iter;
        in_iter++;
    }
}
int main()
{
   /*  vector<int>vi{1,2,3,4,4,6,5,5};
    list<int> lst;
    unique_copy(vi.cbegin(),vi.cend(),lst);
    vector<int>vec;
    istream_iterator<int> in_iter(cin);
    istream_iterator<int> eof;
    while (in_iter!=eof)
    {
        vec.push_back(*in_iter++);
    }
    //与上一段功能相同//10.30
    istream_iterator<int>in__iter(cin),e__of;
    vector<int>vec1(in__iter,e__of);
    sort(vec.begin(),vec.end());
    ostream_iterator<int>out_iter(cout," ");
    copy(vec.begin(),vec.end(),out_iter);
    cout<<endl;
    unique_copy(vec.begin(),vec.end(),out_iter);//打印不重复元素
    istream_iterator<Sales_item> sales_in(cin),e_of;
    vector<Sales_item> vec_sale(sales_in,e_of);
    if (vec_sale.empty())
    {
        cout<<"no data."<<endl;
        return -1;
    }
    sort(vec_sale.begin(),vec_sale.end(),compareIsbn);
    auto beg=vec_sale.begin();
    while (beg!=vec_sale.end())
    {
        auto item=*beg;
        auto r=find_if(beg+1,vec_sale.end(),[item](const Sales_item &a){return item.isbn()!=a.isbn();});
        cout<<accumulate(beg+1,r,item)<<endl;
        beg=r;
    }
    rerangedata("E:\\C++Learning\\code-ground\\C++ primer\\chapter10\\in.txt",
                "E:\\C++Learning\\code-ground\\C++ primer\\chapter10\\out1.txt",
                "E:\\C++Learning\\code-ground\\C++ primer\\chapter10\\out2.txt");
     */
    list<string>lst1{"a","an","the","the","an","an"};
    lst1.sort();
    lst1.unique();
    for(auto beg=lst1.begin();beg!=lst1.end();++beg)
    {
        cout<<*beg<<" ";
    }
    system("pause");
    return 0;
}