#include<iostream>
using namespace std;

class Base { virtual void func() {} };
class Son:public Base{ virtual void func() {} };
class Other{};


//静态类型转换
void test01()
{
	//内置类型转换
	char a = 'a';
	double d = static_cast<double>(a);

	cout << d << endl;

	Base* base = NULL;
	Son* son = NULL;
	//向下类型转换  不安全
	Son* son2 = static_cast<Son*>(base);
	//向上类型转换  安全
	Base* base2 = static_cast<Base*>(son);

	//base转为other型
	//转换无效
	//Other* other = static_cast<Other*>(base);
}


//动态类型转换
void test02()
{
	//不允许内置数据类型转换
	char c = 'c';
	//double d = dynamic_cast<double>(c);

	Base* base = new Son;
	Son* son = NULL;
	//向下类型转换  不安全 不允许动态转换
	//如果发生多态，转换总是安全的
	Son* son2 = dynamic_cast<Son*>(base);

	//向上类型转换  安全
	Base* base2 = static_cast<Base*>(son);

	//动态类型转换更加安全，会进行类型检查
}


//常量转换
void test03()
{
	//不可以将非指针或非引用做const_cast转换
	const int* p = NULL;
	int* pp = const_cast<int*>(p);
	const int* ppp = const_cast<const int*>(pp);

	const int a = 10;
	//int b = const_cast<int>(a);

	int num = 10;
	int& refNum = num;
	const int& refNum2 = const_cast<const int&>(refNum);
}

//重新解释转换，最不安全，不常用
//可以进行任何类型的转换
void test04()
{
	int a = 10;
	int* p = reinterpret_cast<int*>(a);

	Base* base = NULL;
	Other* other = reinterpret_cast<Other*>(base);
}


