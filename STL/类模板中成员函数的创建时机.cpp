#include<iostream>
using namespace std;
#include<string>


class Person1
{
public:
	void showPerson1()
	{
		cout << "Person1 show" << endl;
	}
};

class Person2
{
public:
	void showPerson2()
	{
		cout << "Person2 show" << endl;
	}
};

template<class T>
class MyClass
{
public:
	T obj;

	//��ģ���еĳ�Ա������������һ��ʼ�ʹ����ģ�������ģ�����ʱ������

	void fun1() { obj.showPerson1(); }
	void fun2() { obj.showPerson2(); }

};

void test07()
{
	MyClass<Person1> m;

	m.fun1();

	//m.fun2();//��������˵���������òŻ�ȥ������Ա����
}

