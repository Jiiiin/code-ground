#include<iostream>
#include<string>
#include<vector>
 using namespace std; 
 int fact(int val)
{
	int ret = 1;
	while (val>1)
	{
		ret *= val--;
	}
	return ret;
} 
int count_call()
{
	static int ctr = -1;
	return ++ctr;
}
void reset(int *p)
{
	*p = 0;
	p = 0;
}
void exchange(int *p, int *q)
{
	int mid;
	mid = *p;
	*p = *q;
	*q = mid;
}
string isshorter(const string &s1, const string &s2)
{
	string shorter = (s1.size() < s2.size()) ? s1 : s2;
	return shorter;
}
string::size_type find_char(const string &s, char c, string::size_type &occurs)
{
	auto ret = s.size();
	occurs = 0;
	for (decltype(ret) i = 0; i != s.size(); ++i)
	{
		if (s[i]==c)
		{
			if (ret==s.size())
			{
				ret = i;
			}
			++occurs;
		}
	}
	return ret;
}
bool is_empty(const string &s)
{
	return s.empty();
}
bool upper(const string &s)
{
	bool flag = false;
	for(auto &c:s)
	{
		if(isupper(c))
		{
			flag = true;
			break;
		}	
	}
	return flag;
}
void tolower(string &s)
{
	for(auto &c:s)
	{
		c = tolower(c);
	}
}
int main()
{
	string s{"jinBenDan"};
	/* decltype(s.size()) occur;
	find_char("hello world", 'l', occur); */
	if(upper(s))
		cout << "upper exist!" << endl;
	else
	{
		cout << "upper do not exist!" << endl;
	}
	tolower(s);
	cout << s << endl;
	system("pause");
	return 0;
}
