#include<iostream>
using namespace std;

class MyExpection
{
public:
	MyExpection()
	{
		cout << "MyExpection�Ĺ��캯��������" << endl;
	}
	MyExpection(const MyExpection& e)
	{
		cout << "MyExpection�Ŀ������캯��������" << endl;
	}
	~MyExpection()
	{
		cout << "MyExpection����������������" << endl;
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
	throw MyExpection()  catch (MyExpection &e)    ����ÿ������캯�������Ч�ʵ���
	throw MyExpection()  catch (MyExpection &e)    ֻ���ù��캯����Ч�ʸߣ��Ƽ�
	throw &MyExpection()  catch (MyExpection *e)   �������ǰ�ͷŵ�
	throw new MyExpection()  catch (MyExpection *e)ֻ����Ĭ�Ϲ��캯�����Լ������ͷ�
	*/
	catch (MyExpection &e)
	{
		cout << "�����쳣" << endl;
	}
}

