#include<iostream>
using namespace std;
#include<set>

/*
find(key); //����key�Ƿ����,�����ڣ����ظü���Ԫ�صĵ��������������ڣ�����set.end();
count(key); //ͳ��key��Ԫ�ظ���
*/

void test04()
{
	set<int> s1;

	s1.insert(10);
	s1.insert(30);
	s1.insert(20);
	s1.insert(40);

	set<int>::iterator pos = s1.find(60);

	if (pos != s1.end())
	{
		cout << "�ҵ���Ԫ�� �� " << *pos << endl;
	}
	else
	{
		cout << "δ�ҵ�Ԫ��" << endl;
	}

	//ͳ��
	int num = s1.count(60);
	cout << "num = " << num << endl;
}

int main()
{

	test04();

	system("pause");

	return 0;
}