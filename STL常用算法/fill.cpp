#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<numeric>

/*
fill(iterator beg, iterator end, value);

// �����������Ԫ��

// beg ��ʼ������

// end ����������

// value ����ֵ
*/

void myPrint6(int val)
{
	cout << val << "  ";
}

void test18()
{
	vector<int > v;
	v.resize(10);
	fill(v.begin(),v.end(),100);
	for_each(v.begin(),v.end(),myPrint6);
}

