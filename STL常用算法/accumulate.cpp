#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<numeric>

/*
accumulate(iterator beg, iterator end, value);

// ��������Ԫ���ۼ��ܺ�

// beg ��ʼ������

// end ����������

// value ��ʼֵ(��ֵ)
*/

void test17()
{
	vector<int> v;
	for (int i = 0; i <= 100; i++)
	{
		v.push_back(i);
	}

	int total = accumulate(v.begin(),v.end(),0);

	cout << "total = " << total << endl;
}

