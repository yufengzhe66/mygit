#include<iostream>
using namespace std;

class MyExpection
{
public:
	MyExpection()
	{
		cout << "MyExpection的构造函数被调用" << endl;
	}
	MyExpection(const MyExpection& e)
	{
		cout << "MyExpection的拷贝构造函数被调用" << endl;
	}
	~MyExpection()
	{
		cout << "MyExpection的析构函数被调用" << endl;
	}
};

void doWork()
{
	throw MyExpection();
}

void test07()
{
	try { doWork(); }
	/*
	throw MyExpection()  catch (MyExpection &e)    会调用拷贝构造函数，造成效率低下
	throw MyExpection()  catch (MyExpection &e)    只调用构造函数，效率高，推荐
	throw &MyExpection()  catch (MyExpection *e)   对象会提前释放掉
	throw new MyExpection()  catch (MyExpection *e)只调用默认构造函数，自己管理释放
	*/
	catch (MyExpection &e)
	{
		cout << "捕获异常" << endl;
	}
}

