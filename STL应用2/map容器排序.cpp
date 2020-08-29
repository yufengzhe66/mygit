#include<iostream>
using namespace std;
#include<map>

/*
利用仿函数，可以改变排序规则  只对key进行排序
*/
class MyCompare
{
public:
	bool operator()(const int& v1, const int& v2)const
	{
		return v1 > v2;
	}
};


void printMap4(const map<int, int, MyCompare>& m)
{
	for (map<int, int, MyCompare>::const_iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << "   value = " << (*it).second << endl;
	}
	cout << endl;
}

void test13()
{
	map<int, int, MyCompare>m;
	m.insert(make_pair(1, 10));
	m.insert(make_pair(2, 20));
	m.insert(make_pair(3, 30));
	m.insert(make_pair(4, 40));
	m.insert(make_pair(5, 50));

	printMap4(m);
}


int main()
{

	test13();

	system("pause");

	return 0;
}
