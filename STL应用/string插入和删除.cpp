#include<iostream>
using namespace std;
#include<string>

/*
string& insert(int pos, const char* s); //�����ַ���
string& insert(int pos, const string& str); //�����ַ���
string& insert(int pos, int n, char c); //��ָ��λ�ò���n���ַ�c
string& erase(int pos, int n = npos); //ɾ����Pos��ʼ��n���ַ�
*/

void test10()
{
	string str = "hello";
	str.insert(1, "111");
	cout << str << endl;

	str.erase(1, 3);
	cout << str << endl;
}


