#include<iostream>
using namespace std;
#include<list>

/*
reverse(); //��ת����
sort(); //��������
*/

void printList5(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}


bool mycompare(int v1, int v2)
{
	return v1 > v2;    //���ý�������
}

void test33()
{
	list<int>L;
	L.push_back(90);
	L.push_back(30);
	L.push_back(20);
	L.push_back(70);
	printList5(L);

	L.reverse();
	printList5(L);

	//����������ʵ�����������ʹ��STL�㷨�������ṩ�������㷨
	L.sort();
	printList5(L);

	L.sort(mycompare);//�Զ�������˳�������㷨Ĭ������
	printList5(L);
}

