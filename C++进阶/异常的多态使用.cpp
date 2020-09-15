#include<iostream>
using namespace std;

class BaseException
{
public:
	virtual void printError() = 0;
};

class NULLPointer:public BaseException
{
public:
	virtual void printError()
	{
		cout << "��ָ���쳣" << endl;
	}
};

class OutOfRange :public BaseException
{
public:
	virtual void printError()
	{
		cout << "Խ���쳣" << endl;
	}
};

void test08()
{
	try 
	{
		//throw NULLPointer();
		throw OutOfRange();
	}
	catch (BaseException& e)
	{
		e.printError();
	}
}
