#include<iostream>
using namespace std;


template<typename T>
//对于交换的函数，不要命名为swap,因为有内置定义，会产生重载错误（重名）
void myswap(T& a,T& b)
{
	T temp = a;
	a = b;
	b = temp;
}


void test01()
{
	int a = 10;
	int b = 20;
	myswap<int>(a,b);//显式指定类型

	cout << "a=" << a << endl << "b=" << b << endl;


	double c = 1.1;
	double d = 2.2;
	myswap(c, d);//自动推导类型，模板必须推导出一致的类型，才可使用，同时模板必须要确定出T的数据类型，才可使用，即使函数无参，也要显式地指定类型

	cout << "c=" << c << endl << "d=" << d << endl;


}


