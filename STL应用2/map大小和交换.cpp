#include<iostream>
using namespace std;
#include<map>

/*
统计map容器大小以及交换map容器

函数原型：
size(); //返回容器中元素的数目
empty(); //判断容器是否为空
swap(st); //交换两个集合容器
*/

void printMap2(const map<int, int>& m)
{
	for (map<int, int>::const_iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << "   value = " << (*it).second << endl;
	}
	cout << endl;
}

void test10()
{
	map<int, int>m1;
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	m1.insert(pair<int, int>(4, 40));

	map<int, int>m2;
	m2.insert(pair<int, int>(4, 100));
	m2.insert(pair<int, int>(5, 200));
	m2.insert(pair<int, int>(6, 300));

	if (m1.empty())
	{
		cout << "m1为空" << endl;
	}
	else
	{
		cout << "m1不为空" << endl;
		cout << "m1的大小为： " << m1.size() << endl;
	}

	cout << "-----交换前----------" << endl;
	printMap2(m1);
	printMap2(m2);
	cout << "-----交换后----------" << endl;
	m1.swap(m2);
	printMap2(m1);
	printMap2(m2);
}

