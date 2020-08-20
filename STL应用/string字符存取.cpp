#include<iostream>
using namespace std;
#include<string>

/*
char& operator[](int n); //通过[]方式取字符
char& at(int n); //通过at方法获取字符
*/

void test09()
{
	string str = "hello world";
	for (unsigned i = 0; i < str.size(); i++)
	{
		cout << str[i] << " ";
	}
	cout << endl;

	for (unsigned i = 0; i < str.size(); i++)
	{
		cout << str.at(i) << " ";
	}
	cout << endl;

	//字符修改
	str[0] = 'x';
	str.at(1) = 'x';
	cout << str << endl;

}

