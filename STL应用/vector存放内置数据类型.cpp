#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


void myPrint(int val)
{
	cout << val << "  ";
}


void test_vector1()
{
	//�������������������
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back((i+1)*10);
	}
	cout << "--------��һ�ֱ�����ʽ-------" << endl;
	vector<int>::iterator vBegin = v.begin();
	vector<int>::iterator vEnd = v.end();

	//��һ�ַ�ʽ
	for (; vBegin != v.end(); vBegin++)
	{
		cout << *vBegin << "  ";
	}
	cout << endl;
	cout << "--------�ڶ��ֱ�����ʽ-------" << endl;

	//�ڶ��ַ�ʽ
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
	{
		cout << *iter << "  ";
	}


	cout << endl;
	cout << "--------�����ֱ�����ʽ-------" << endl;
	//�����ַ�ʽ���������õ��㷨
	for_each(v.begin(),v.end(),myPrint);
}


int main()
{
	test_vector1();
	return 0;
}