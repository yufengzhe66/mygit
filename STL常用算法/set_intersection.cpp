#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


/*
set_intersection(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);

// ���������ϵĽ���

// ע��:�������ϱ�������������

// beg1 ����1��ʼ������ // end1 ����1���������� // beg2 ����2��ʼ������ // end2 ����2���������� // dest Ŀ��������ʼ������
*/

void myPrint7(int val)
{
	cout << val << "  ";
}

void test19()
{
	vector<int> v1;
	vector<int> v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i + 5);
	}

	vector<int> vTarget;
	vTarget.resize(min(v1.size(),v2.size()));
	vector<int>::iterator itEnd = set_intersection(v1.begin(),v1.end(),v2.begin(),v2.end(),vTarget.begin());

	for_each(vTarget.begin(), itEnd, myPrint7);
	cout << endl;
}

