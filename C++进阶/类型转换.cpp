#include<iostream>
using namespace std;

class Base { virtual void func() {} };
class Son:public Base{ virtual void func() {} };
class Other{};


//��̬����ת��
void test01()
{
	//��������ת��
	char a = 'a';
	double d = static_cast<double>(a);

	cout << d << endl;

	Base* base = NULL;
	Son* son = NULL;
	//��������ת��  ����ȫ
	Son* son2 = static_cast<Son*>(base);
	//��������ת��  ��ȫ
	Base* base2 = static_cast<Base*>(son);

	//baseתΪother��
	//ת����Ч
	//Other* other = static_cast<Other*>(base);
}


//��̬����ת��
void test02()
{
	//������������������ת��
	char c = 'c';
	//double d = dynamic_cast<double>(c);

	Base* base = new Son;
	Son* son = NULL;
	//��������ת��  ����ȫ ������̬ת��
	//���������̬��ת�����ǰ�ȫ��
	Son* son2 = dynamic_cast<Son*>(base);

	//��������ת��  ��ȫ
	Base* base2 = static_cast<Base*>(son);

	//��̬����ת�����Ӱ�ȫ����������ͼ��
}


//����ת��
void test03()
{
	//�����Խ���ָ����������const_castת��
	const int* p = NULL;
	int* pp = const_cast<int*>(p);
	const int* ppp = const_cast<const int*>(pp);

	const int a = 10;
	//int b = const_cast<int>(a);

	int num = 10;
	int& refNum = num;
	const int& refNum2 = const_cast<const int&>(refNum);
}

//���½���ת�������ȫ��������
//���Խ����κ����͵�ת��
void test04()
{
	int a = 10;
	int* p = reinterpret_cast<int*>(a);

	Base* base = NULL;
	Other* other = reinterpret_cast<Other*>(base);
}


