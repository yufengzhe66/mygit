#include<iostream>
using namespace std;
#include<set>

/*
set�����Բ����ظ����ݣ���multiset����
set�������ݵ�ͬʱ�᷵�ز���������ʾ�����Ƿ�ɹ�
multiset���������ݣ���˿��Բ����ظ�����
*/

void test05()
{
	set<int> s;
	pair<set<int>::iterator, bool> ret = s.insert(10);
	if (ret.second)
	{
		cout << "��һ�β���ɹ�!" << endl;
	}
	else
	{
		cout << "��һ�β���ʧ��!" << endl;
	}

	ret = s.insert(10);
	if (ret.second)
	{
		cout << "�ڶ��β���ɹ�!" << endl;
	}
	else
	{
		cout << "�ڶ��β���ʧ��!" << endl;
	}

	multiset<int> ms;
	ms.insert(10);
	ms.insert(10);

	for (multiset<int>::iterator it = ms.begin(); it != ms.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

