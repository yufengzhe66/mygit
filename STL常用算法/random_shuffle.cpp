#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<ctime>

/*
random_shuffle(iterator beg, iterator end);

// ָ����Χ�ڵ�Ԫ�������������

// beg ��ʼ������

// end ����������

*/

void myPrint1(int val)
{
	cout << val << "  ";
}

void test10()
{
	vector<int> v;
	
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	for_each(v.begin(),v.end(),myPrint1);
	cout << endl;

	random_shuffle(v.begin(),v.end());

	for_each(v.begin(), v.end(), myPrint1);
	cout << endl;
}

