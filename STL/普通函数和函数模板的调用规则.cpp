#include<iostream>
using namespace std;

void func(int a, int b)
{
	cout << "���õ���ͨ����" << endl;
}

template<typename T>
void func(T a, T b)
{
	cout << "���õ�ģ�庯��" << endl;
}

template<typename T>
void func(T a, T b, T c)
{
	cout << "���õ�����ģ�庯��" << endl;
}


//���ù������£�
//
//�������ģ�����ͨ����������ʵ�֣����ȵ�����ͨ����
//����ͨ����ģ������б���ǿ�Ƶ��ú���ģ��
//����ģ��Ҳ���Է�������
//�������ģ����Բ������õ�ƥ��, ���ȵ��ú���ģ��


void test04()
{
	int a = 10;
	int b = 20;
	char c1 = 'a';
	char c2 = 'b';
	func(a,b);
	func<>(a, b);
	func(c1,c2);
	func(a, b, 100);
	func<int>(a,b,c1);
}