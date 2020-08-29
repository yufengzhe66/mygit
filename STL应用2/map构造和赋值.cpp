#include<iostream>
using namespace std;
#include<map>

/*
���죺
map<T1, T2> mp; //mapĬ�Ϲ��캯��:
map(const map &mp); //�������캯��

��ֵ��
map& operator=(const map &mp); //���صȺŲ�����
*/
void printMap1(const map<int, int>& m)
{
	for (map<int, int>::const_iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << "   value = " << (*it).second << endl;
	}
	cout << endl;
}

void test09()
{
	map<int, int>m1;  //Ĭ�Ϲ��캯��
	m1.insert(pair<int, int>(1, 10));
	m1.insert(pair<int, int>(2, 20));
	m1.insert(pair<int, int>(3, 30));
	m1.insert(pair<int, int>(4, 40));

	printMap1(m1);

	map<int, int>m2(m1);  //�������캯��
	printMap1(m2);

	map<int, int>m3 = m1;
	printMap1(m3);
}


