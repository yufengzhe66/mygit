#include<iostream>
using namespace std;
#include<string>
#include<list>

/*
*STL中的链表是一个双向循环链表
* 由于链表的存储方式并不是连续的内存空间，因此链表list中的迭代器只支持前移和后移，属于双向迭代器
list<T> lst; //list采用采用模板类实现,对象的默认构造形式：
list(beg,end); //构造函数将[beg, end)区间中的元素拷贝给本身。
list(n,elem); //构造函数将n个elem拷贝给本身。
list(const list &lst); //拷贝构造函数。
*/

void printList1(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}


void test28()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList1(L1);

	list<int>L2(L1.begin(), L1.end());
	printList1(L2);

	list<int>L3(L1);
	printList1(L3);

	list<int>L4(10,1000);
	printList1(L4);
}

