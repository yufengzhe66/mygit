#include<iostream>
using namespace std;
#include<string>

//ȫ�ֺ�������ʵ�� - ֱ��������������Ԫ����
//ȫ�ֺ�������ʵ�� - ��Ҫ��ǰ�ñ�����֪��ȫ�ֺ����Ĵ���

//1.ȫ�ֺ��������Ԫ  ����ʵ�� - ������ģ���������·�������Ԫ����ģ�嶨�壬�������Ԫ
//2.������������Ԫ����ʱ������Ҫ�ӿ�ģ������б�

template<class T1, class T2>class person;

template<class T1, class T2>
void printPerson2(person<T1, T2>& p)
{
	cout << "����ʵ�� ---- ������ " << p.name << " ���䣺" << p.age << endl;
}

template<class T1, class T2>
class person
{
public:
	person(T1 name, T2 age);

	friend void printPerson1(person<T1, T2>&p)
	{
		cout << "����ʵ�� ---- ������ " << p.name << " ���䣺" << p.age << endl;
	}

	friend void printPerson2<>(person<T1, T2>&p);

private:
	T1 name;
	T2 age;
};

template<class T1, class T2>
person<T1, T2>::person(T1 name, T2 age)
{
	this->name = name;
	this->age = age;
}


void test12()
{
	person<string, int>p1("Tom", 18);

	person<string, int>p2("Jerry",20);
	printPerson1(p1);
	printPerson2(p2);
}


int main()
{
	test12();
	return 0;
}
