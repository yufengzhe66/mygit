#include<iostream>
using namespace std;
#include<map>

/*
insert(elem); //�������в���Ԫ�ء�
clear(); //�������Ԫ��
erase(pos); //ɾ��pos��������ָ��Ԫ�أ�������һ��Ԫ�صĵ�������
erase(beg, end); //ɾ������[beg,end)������Ԫ�� ��������һ��Ԫ�صĵ�������
erase(key); //ɾ��������ֵΪkey��Ԫ�ء�
*/

void printMap3(const map<int, int>& m)
{
	for (map<int, int>::const_iterator it = m.begin(); it != m.end(); it++)
	{
		cout << "key = " << it->first << "   value = " << (*it).second << endl;
	}
	cout << endl;
}


void test11()
{
	map<int, int>m;
	//һ�����ֲ��뷽ʽ
	m.insert(pair<int,int>(1,10));
	m.insert(make_pair(2,20));
	m.insert(map<int, int>::value_type(3, 30));
	m[4] = 40;
	printMap3(m);

	m.erase(m.begin());
	printMap3(m);

	m.erase(3);
	printMap3(m);

//	m.erase(m.begin(),m.end());
	m.clear();
	printMap3(m);

}

