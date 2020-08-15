#include<iostream>
using namespace std;
#include<string>

//全局函数类内实现 - 直接在类内声明友元即可
//全局函数类外实现 - 需要提前让编译器知道全局函数的存在

//1.全局函数配合友元  类外实现 - 先做类模板声明，下方在做友元函数模板定义，最后做友元
//2.在类内声明友元函数时，还需要加空模板参数列表

template<class T1, class T2>class person;

template<class T1, class T2>
void printPerson2(person<T1, T2>& p)
{
	cout << "类外实现 ---- 姓名： " << p.name << " 年龄：" << p.age << endl;
}

template<class T1, class T2>
class person
{
public:
	person(T1 name, T2 age);

	friend void printPerson1(person<T1, T2>&p)
	{
		cout << "类内实现 ---- 姓名： " << p.name << " 年龄：" << p.age << endl;
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
