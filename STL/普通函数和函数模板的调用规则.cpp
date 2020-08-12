#include<iostream>
using namespace std;

void func(int a, int b)
{
	cout << "调用的普通函数" << endl;
}

template<typename T>
void func(T a, T b)
{
	cout << "调用的模板函数" << endl;
}

template<typename T>
void func(T a, T b, T c)
{
	cout << "调用的重载模板函数" << endl;
}


//调用规则如下：
//
//如果函数模板和普通函数都可以实现，优先调用普通函数
//可以通过空模板参数列表来强制调用函数模板
//函数模板也可以发生重载
//如果函数模板可以产生更好的匹配, 优先调用函数模板


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