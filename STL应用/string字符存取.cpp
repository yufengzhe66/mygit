#include<iostream>
using namespace std;
#include<string>

/*
char& operator[](int n); //ͨ��[]��ʽȡ�ַ�
char& at(int n); //ͨ��at������ȡ�ַ�
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

	//�ַ��޸�
	str[0] = 'x';
	str.at(1) = 'x';
	cout << str << endl;

}

