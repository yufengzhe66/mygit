#include<iostream>
using namespace std;
#include<set>

/*
insert(elem); //�������в���Ԫ�ء�
clear(); //�������Ԫ��
erase(pos); //ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�������
erase(beg, end); //ɾ������[beg,end)������Ԫ�� ��������һ��Ԫ�صĵ�������
erase(elem); //ɾ��������ֵΪelem��Ԫ�ء�
*/

void printSet3(const set<int>& s)
{
	for (set<int>::const_iterator it = s.begin(); it != s.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

void test03()
{
	set<int> s1;

	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);
	printSet3(s1);

	//ָ��λ��ɾ��
	s1.erase(s1.begin());
	printSet3(s1);
	
	//ָ��Ԫ��ɾ��
	s1.erase(30);
	printSet3(s1);

	//���
	s1.clear();
	printSet3(s1);
}

