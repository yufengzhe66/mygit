#include<iostream>
using namespace std;
#include<string>

template<class T1,class T2>
class person
{
public:
	person(T1 name, T2 ag);
	void show();
private:
	T1 name;
	T2 age;
};


//��ģ���г�Ա��������ʵ��ʱ����Ҫ����ģ������б�
template<class T1, class T2>
person<T1,T2>::person(T1 name,T2 age)
{
	this->name = name;
	this->age = age;
}

template<class T1, class T2>
void person<T1, T2>::show()
{
	cout << "����: " << this->name << " ����:" << this->age << endl;
}


void test10()
{
	person<string, int>p("Tom",20);
	p.show();
}

