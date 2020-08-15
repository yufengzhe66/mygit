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


//类模板中成员函数类外实现时，需要加上模板参数列表
template<class T1, class T2>
person<T1,T2>::person(T1 name,T2 age)
{
	this->name = name;
	this->age = age;
}

template<class T1, class T2>
void person<T1, T2>::show()
{
	cout << "姓名: " << this->name << " 年龄:" << this->age << endl;
}


void test10()
{
	person<string, int>p("Tom",20);
	p.show();
}

