#include<iostream>
using namespace std;
#include<list>

/*
reverse(); //反转链表
sort(); //链表排序
*/

void printList5(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}


bool mycompare(int v1, int v2)
{
	return v1 > v2;    //设置降序排列
}

void test33()
{
	list<int>L;
	L.push_back(90);
	L.push_back(30);
	L.push_back(20);
	L.push_back(70);
	printList5(L);

	L.reverse();
	printList5(L);

	//不能随机访问的容器，不能使用STL算法，容器提供了内置算法
	L.sort();
	printList5(L);

	L.sort(mycompare);//自定义排序顺序，排序算法默认升序
	printList5(L);
}

