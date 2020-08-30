#include<iostream>
using namespace std;
#include<functional>
/*
这些仿函数所产生的对象，用法和一般函数完全相同
使用内建函数对象，需要引入头文件 #include<functional>

仿函数原型：

template<class T> T plus<T> //加法仿函数
template<class T> T minus<T> //减法仿函数
template<class T> T multiplies<T> //乘法仿函数
template<class T> T divides<T> //除法仿函数
template<class T> T modulus<T> //取模仿函数
template<class T> T negate<T> //取反仿函数
*/

void test17()
{
	negate<int> abs;
	cout << abs(50) << endl;;
	plus<int> add;
	cout << add(10, 20) << endl;
}
int main()
{
	test17();
	system("pause");
	return 0;
}