#include<iostream>
using namespace std;

int myAddint(int a, int b)
{
	return a + b;
}

template<typename T>
T myAddT(T a, T b)
{
	return a + b;
}

void test03()
{
	int a = 10;
	int b = 20;
	char c = 'c';
	/*
	普通函数调用时可以发生自动类型转换（隐式类型转换）
	函数模板调用时，如果利用自动类型推导，不会发生隐式类型转换
	如果利用显示指定类型的方式，可以发生隐式类型转换
	*/
	cout << myAddint(a, c) << endl;
	cout << myAddT<int>(a, c) << endl;
}