#include<iostream>
using namespace std;
#include<string>

/*
string substr(int pos = 0, int n = npos) const; //������pos��ʼ��n���ַ���ɵ��ַ���
*/

void test11()
{
	string str = "abcdefg";
	string subStr = str.substr(1, 3);
	cout << "subStr = " << subStr << endl;

	string email = "hello@sina.com";
	int pos = email.find('@');
	string username = email.substr(0, pos);
	cout << "username: " << username << endl;
}

int main() {

	test11();

	system("pause");

	return 0;
}