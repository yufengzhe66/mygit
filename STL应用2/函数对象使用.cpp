#include<iostream>
using namespace std;
#include<string>

/*
����������ʹ��ʱ����������ͨ������������, �����в����������з���ֵ
�������󳬳���ͨ�����ĸ����������������Լ���״̬
�������������Ϊ��������
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
	cout << "myPrint���ô���Ϊ�� " << myprint.count << endl;

	doPrint(myprint,"Hello C++");
}
