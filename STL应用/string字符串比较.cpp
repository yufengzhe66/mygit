#include<iostream>
using namespace std;
#include<string>

/*
int compare(const string &s) const; //���ַ���s�Ƚ�
int compare(const char *s) const; //���ַ���s�Ƚ�
*/

void test08()
{

	string s1 = "hello";
	string s2 = "aello";

	int ret = s1.compare(s2);

	if (ret == 0) {
		cout << "s1 ���� s2" << endl;
	}
	else if (ret > 0)
	{
		cout << "s1 ���� s2" << endl;
	}
	else
	{
		cout << "s1 С�� s2" << endl;
	}

}

int main() {

	test08();

	system("pause");

	return 0;
}