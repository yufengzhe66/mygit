#include<iostream>
using namespace std;
#include<set>


/*
���죺
set<T> st; //Ĭ�Ϲ��캯����
set(const set &st); //�������캯��

��ֵ��
set& operator=(const set &st); //���صȺŲ�����
*/


void printSet1(const set<int>& s)
{
	for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

void test01()
{
	set<int>st1;
	st1.insert(10);
	st1.insert(30);
	st1.insert(20);
	st1.insert(40);
	printSet1(st1);

	//��������
	set<int> st2(st1);
	printSet1(st2);

	set<int>st3;
	st3 = st2;
	printSet1(st3);
}

