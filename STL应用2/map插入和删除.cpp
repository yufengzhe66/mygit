#include<iostream>
using namespace std;
#include<map>

/*
insert(elem); //在容器中插入元素。
clear(); //清除所有元素
erase(pos); //删除pos迭代器所指的元素，返回下一个元素的迭代器。
erase(beg, end); //删除区间[beg,end)的所有元素 ，返回下一个元素的迭代器。
erase(key); //删除容器中值为key的元素。
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
	//一共四种插入方式
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

