#include<iostream>
using namespace std;

/*
c++�����쳣�ؼ���
try catch throw
�����쳣�Ĵ��룬����try��
����throw�׳��쳣
����catch�����쳣
catch���������쳣catch(...)
���������쳣���봦�����������׳�������throw
�쳣�����к������д�������������������Զ�����terminate�������жϵ�
�쳣�������Զ�������
*/

class Person
{
public:
	Person()
	{
		cout << "Person�Ĺ��캯��������" << endl;
	}
	~Person()
	{
		cout << "Person����������������" << endl;
	}
};


int myDivision(int a, int b)
{
	if (b == 0)
	{
		Person p1;
		Person p2;   
//ջ�������쳣���׳��󣬴ӽ��� try ���𣬵��쳣������ǰ�����ڼ���ջ�ϵĹ�������ж��� ���ᱻ�Զ�������
//������˳���빹���˳���෴����һ���̳�Ϊջ�Ľ���(unwinding)��
		throw - 1;  //�׳�int���͵��쳣
		 			//Ҳ���׳��������͵��쳣��char double float��

	}
	return a / b;
}


//C���Դ����쳣��ȱ�ݣ�����ֵ��ͳһ���޷����ֽ�������쳣
//�׳�����봦�����������ж�
void test05()
{
	int a = 10;
	int b = 0;

	try {
		myDivision(a,b);
	}
	catch (int)
	{
		cout << "int �����쳣" << endl;
	}
	catch (...)
	{
		cout << "���������쳣" << endl;
	}
}


//�ں����У�����޶��׳��쳣�����ͣ��������쳣�Ľӿ�
void func()throw(int, double)
{
	throw 3.14;
}

void test06()
{
	try {
		func();
	}
	catch (int)
	{
		cout << "int �����쳣����" << endl;
	}
	catch (...)
	{
		cout << "���� �����쳣����" << endl;
	}
}
