#include<iostream>
using namespace std;
#include<deque>

/*
at(int idx); //��������idx��ָ������
operator[]; //��������idx��ָ������
front(); //���������е�һ������Ԫ��
back(); //�������������һ������Ԫ��
*/

void printDeque5(const deque<int>d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

void test23()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);

	for (int i = 0; i < d.size(); i++)
	{
		cout << d[i] << "  ";
	}
	cout << endl;

	for (int i = 0; i < d.size(); i++)
	{
		cout << d.at(i) << "  ";
	}
	cout << endl;

	cout << "front: " << d.front() << endl;
	cout << "back:  " << d.back() << endl;
}


