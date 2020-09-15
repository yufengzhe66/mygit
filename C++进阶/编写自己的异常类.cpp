#include<iostream>
using namespace std;
#include<stdexcept>
#include<string>

class myOutOfRangeException :public exception
{
public:
	myOutOfRangeException(const char* str)
	{
		//const char*������ʽת����string �� ��֮������
		this->errorInfo = str;
	}

	virtual const char* what()const
	{
		return this->errorInfo.c_str();
	}
	string errorInfo;
};

class person
{
public:
	person(int age)
	{
		if (age < 0 || age>150)
		{
			throw myOutOfRangeException("����Ӧ�ô��ں���Χ");
		}
		else
		{
			this->age = age;
		}
	}
	int age;
};

void test09()
{
	try {
		person p(1000);
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}
}


int main()
{
	test09();
	return 0;
}