#include<iostream>
using namespace std;
#include<map>

/*
find(key); //����key�Ƿ����,�����ڣ����ظü���Ԫ�صĵ��������������ڣ�����set.end();
count(key); //ͳ��key��Ԫ�ظ���
*/
void test12()
{
	map<int, int>m;
	m.insert(pair<int, int>(1, 10));
	m.insert(pair<int, int>(2, 20));
	m.insert(pair<int, int>(3, 30));

	map<int, int>::iterator pos = m.find(3);

	if (pos != m.end())
	{
		cout << "�ҵ���Ԫ�� key = " << (*pos).first << " value = " << (*pos).second << endl;
	}
	else
	{
		cout << "δ�ҵ�Ԫ��" << endl;
	}

	int num = m.count(3);
	cout << "num = " << num << endl;
}

