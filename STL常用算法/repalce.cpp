#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

/*
replace(iterator beg, iterator end, oldvalue, newvalue);

// �������ھ�Ԫ�� �滻�� ��Ԫ��

// beg ��ʼ������

// end ����������

// oldvalue ��Ԫ��

// newvalue ��Ԫ��
*/

void myPrint3(int val)
{
	cout << val << "  ";
}

void test14()
{
	vector<int> v;
	v.push_back(20);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);
	v.push_back(50);
	v.push_back(10);
	v.push_back(20);

	replace(v.begin(), v.end(), 20, 200);
	for_each(v.begin(), v.end(), myPrint3);
	cout << endl;
}

