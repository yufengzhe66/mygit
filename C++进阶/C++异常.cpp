#include<iostream>
using namespace std;

/*
c++处理异常关键字
try catch throw
出现异常的代码，放在try块
利用throw抛出异常
利用catch捕获异常
catch捕获其他异常catch(...)
如果捕获的异常不想处理，可以向上抛出，利用throw
异常必须有函数进行处理，如果都不处理，程序自动调用terminate函数，中断掉
异常可以是自定义类型
*/

class Person
{
public:
	Person()
	{
		cout << "Person的构造函数被调用" << endl;
	}
	~Person()
	{
		cout << "Person的析构函数被调用" << endl;
	}
};


int myDivision(int a, int b)
{
	if (b == 0)
	{
		Person p1;
		Person p2;   
//栈解旋：异常被抛出后，从进入 try 块起，到异常被抛掷前，这期间在栈上的构造的所有对象， 都会被自动析构。
//析构的顺序与构造的顺序相反。这一过程称为栈的解旋(unwinding)。
		throw - 1;  //抛出int类型的异常
		 			//也可抛出其他类型的异常（char double float）

	}
	return a / b;
}


//C语言处理异常有缺陷，返回值不统一，无法区分结果还是异常
//抛出后必须处理，否则程序会中断
void test05()
{
	int a = 10;
	int b = 0;

	try {
		myDivision(a,b);
	}
	catch (int)
	{
		cout << "int 类型异常" << endl;
	}
	catch (...)
	{
		cout << "其他类型异常" << endl;
	}
}


//在函数中，如果限定抛出异常的类型，可以用异常的接口
void func()throw(int, double)
{
	throw 3.14;
}

void test06()
{
	try {
		func();
	}
	catch (int)
	{
		cout << "int 类型异常捕获" << endl;
	}
	catch (...)
	{
		cout << "其他 类型异常捕获" << endl;
	}
}
