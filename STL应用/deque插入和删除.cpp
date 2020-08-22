#include<iostream>
using namespace std;
#include<deque>

/*
���˲��������
push_back(elem); //������β�����һ������
push_front(elem); //������ͷ������һ������
pop_back(); //ɾ���������һ������
pop_front(); //ɾ��������һ������


ָ��λ�ò�����
insert(pos,elem); //��posλ�ò���һ��elemԪ�صĿ��������������ݵ�λ�á�
insert(pos,n,elem); //��posλ�ò���n��elem���ݣ��޷���ֵ��
insert(pos,beg,end); //��posλ�ò���[beg,end)��������ݣ��޷���ֵ��
clear(); //�����������������
erase(beg,end); //ɾ��[beg,end)��������ݣ�������һ�����ݵ�λ�á�
erase(pos); //ɾ��posλ�õ����ݣ�������һ�����ݵ�λ�á�
*/

void printDeque4(const deque<int>d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

void test22()
{
	//���˲���
	deque<int> d;
	d.push_back(10);
	d.push_back(20);

	d.push_front(100);
	d.push_front(200);

	printDeque4(d);

	d.pop_front();
	d.pop_back();
	printDeque4(d);


	//����
	deque<int> d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_front(100);
	d1.push_front(200);
	printDeque4(d1);

	d1.insert(d1.begin(),1000);
	printDeque4(d1);

	d1.insert(d1.begin(),2,10000);
	printDeque4(d1);

	deque<int>d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);

	d2.insert(d2.begin(),d1.begin(),d1.end());
	printDeque4(d2);

	//ɾ��
	deque<int> d3;
	d3.push_back(10);
	d3.push_back(20);
	d3.push_front(100);
	d3.push_front(200);
	printDeque4(d3);

	d3.erase(d3.begin());
	printDeque4(d3);

//	d3.erase(d3.begin(), d3.end());
	d3.clear();
	printDeque4(d3);
}

