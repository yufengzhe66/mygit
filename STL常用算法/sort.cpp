#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

/*
sort(iterator beg, iterator end, _Pred);

// ��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��

// beg ��ʼ������

// end ����������

// _Pred ν��
*/

void myPrint(int val)
{
	cout << val << "  ";
}

void test09()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);

	cout << "��������" << endl;
	sort(v.begin(),v.end());
	for_each(v.begin(),v.end(),myPrint);
	cout << endl;

	cout << "��������" << endl;
	sort(v.begin(),v.end(),greater<int>());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
}

