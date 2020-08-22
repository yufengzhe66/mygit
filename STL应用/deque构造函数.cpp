#include<iostream>
using namespace std;
#include<deque>

/*
deque<T> deqT; //Ĭ�Ϲ�����ʽ
deque(beg, end); //���캯����[beg, end)�����е�Ԫ�ؿ���������
deque(n, elem); //���캯����n��elem����������
deque(const deque &deq); //�������캯��
*/


void printDeque1(const deque<int>d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

void test19()
{
	deque<int> d1;
	for (int i = 0; i < 10; i++)
		d1.push_back(i);

	printDeque1(d1);

	deque<int>d2(d1.begin(), d1.end());
	printDeque1(d2);

	deque<int>d3(10,100);
	printDeque1(d3);

	deque<int>d4(d3);
	printDeque1(d4);
}

