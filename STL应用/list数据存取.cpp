#include<iostream>
using namespace std;
#include<string>
#include<list>

/*
front(); //���ص�һ��Ԫ�ء�
back(); //�������һ��Ԫ�ء�
*/


void test32()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	cout << "��һ��Ԫ��Ϊ�� " << L1.front() << endl;
	cout << "���һ��Ԫ��Ϊ�� " << L1.back() << endl;

	//list�����ĵ�������˫�����������֧���������
	list<int>::iterator it = L1.begin();
	//it = it + 1;//���󣬲�������Ծ���ʣ���ʹ��+1,ֻ��������������������

	//cout << *(it + 1) << endl;

}

int main()
{

	test32();

	system("pause");

	return 0;
}