#include<iostream>
using namespace std;
#include<string>

/*
函数对象在使用时，可以像普通函数那样调用, 可以有参数，可以有返回值
函数对象超出普通函数的概念，函数对象可以有自己的状态
函数对象可以作为参数传递
*/
class MyAdd
{
public:
	int operator()(int v1, int v2)
	{
		return v1 + v2;
	}
};


class MyPrint
{
public:
	MyPrint()
	{
		count = 0;
	}
	void operator()(string test)
	{
		cout << test << endl;
		this->count++;
	}
	int count;
};


void doPrint(MyPrint& mp,string test)
{
	mp(test);
}


void test14()
{
	MyAdd myadd;
	cout << myadd(10, 10) << endl;

	MyPrint myprint;
	myprint("Hello World!!!");
	myprint("Hello World!!!");
	myprint("Hello World!!!");
	myprint("Hello World!!!");
	cout << "myPrint调用次数为： " << myprint.count << endl;

	doPrint(myprint,"Hello C++");
}
