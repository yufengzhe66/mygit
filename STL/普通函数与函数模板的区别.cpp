#include<iostream>
using namespace std;

int myAddint(int a, int b)
{
	return a + b;
}

template<typename T>
T myAddT(T a, T b)
{
	return a + b;
}

void test03()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	/*
	��ͨ��������ʱ���Է����Զ�����ת������ʽ����ת����
	����ģ�����ʱ����������Զ������Ƶ������ᷢ����ʽ����ת��
	���������ʾָ�����͵ķ�ʽ�����Է�����ʽ����ת��
	*/
	cout << myAddint(a, c) << endl;
	cout << myAddT<int>(a, c) << endl;
}