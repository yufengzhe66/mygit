#include<iostream>
using namespace std;
#include<map>

/*
ͳ��map������С�Լ�����map����

����ԭ�ͣ�
size(); //����������Ԫ�ص���Ŀ
empty(); //�ж������Ƿ�Ϊ��
swap(st); //����������������
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
		cout << "m1Ϊ��" << endl;
	}
	else
	{
		cout << "m1��Ϊ��" << endl;
		cout << "m1�Ĵ�СΪ�� " << m1.size() << endl;
	}

	cout << "-----����ǰ----------" << endl;
	printMap2(m1);
	printMap2(m2);
	cout << "-----������----------" << endl;
	m1.swap(m2);
	printMap2(m1);
	printMap2(m2);
}

