#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


/*
adjacent_find(iterator beg, iterator end);
// ���������ظ�Ԫ��,��������Ԫ�صĵ�һ��λ�õĵ�����
// beg ��ʼ������
// end ����������
*/


void test05()
{
	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(5);
	v.push_back(2);
	v.push_back(4);
	v.push_back(4);
	v.push_back(3);

	vector<int>::iterator it = adjacent_find(v.begin(), v.end());

	if (it == v.end()) 
	{
		cout << "�Ҳ���!" << endl;
	}
	else 
	{
		cout << "�ҵ������ظ�Ԫ��Ϊ:" << *it << endl;
	}
}
