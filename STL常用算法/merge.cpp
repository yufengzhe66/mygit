#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


/*
merge(iterator beg1, iterator end1, iterator beg2, iterator end2, iterator dest);

// ����Ԫ�غϲ������洢����һ������

// ע��: �������������������

// beg1 ����1��ʼ������ // end1 ����1���������� // beg2 ����2��ʼ������ // end2 ����2���������� // dest Ŀ��������ʼ������
*/


class MyPrint
{
public:
	void operator()(int val)
	{
		cout << val << "  ";
	}
};

void test11()
{
	vector<int>v1;
	vector<int>v2;

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
		v2.push_back(i+1);
	}

	vector<int>vTarget;
	vTarget.resize(v1.size()+v2.size());

	merge(v1.begin(),v1.end(),v2.begin(),v2.end(),vTarget.begin());

	for_each(vTarget.begin(), vTarget.end(), MyPrint());
	cout << endl;
}

