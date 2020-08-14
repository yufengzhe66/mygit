#include<iostream>
using namespace std;
#include<string>

template<typename T>
class base
{
protected:
	T m;
};

//当子类继承的父类是一个类模板时，子类在声明的时候，要指定出父类中T的类型
//如果不指定，编译器无法给子类分配内存

class son1 :public base<int>
{
public:
	void show()
	{
		m = 10;
		cout << m << endl;
	}
};

template<class T1,class T2>
class son2 :public base<T2>
{
	T1 son;
public:
	void show()
	{
		cout << typeid(T1).name() << endl;
		cout << typeid(T2).name() << endl;
	}
};

void test09()
{
	son2<int, char>s;
	s.show();
	son1 s1;
	s1.show();
}

int main()
{
	test09();
	return 0;
}