#include<iostream>
using namespace std;
#include<set>
#include<string>
/*
�ɶԳ��ֵ����ݣ����ö�����Է�����������

���ִ�����ʽ��
pair<type, type> p ( value1, value2 );
pair<type, type> p = make_pair( value1, value2 );
*/

void test06()
{
	pair<string, int>p(string("Tom"),20);
	cout << "������" << p.first << "  ���䣺" << p.second << endl;

	pair<string, int> p2 = make_pair("Jerry",10);
	cout << "������" << p2.first << "  ���䣺" << p2.second << endl;
}


