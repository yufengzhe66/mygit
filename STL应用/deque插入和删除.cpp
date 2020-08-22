#include<iostream>
using namespace std;
#include<deque>

/*
两端插入操作：
push_back(elem); //在容器尾部添加一个数据
push_front(elem); //在容器头部插入一个数据
pop_back(); //删除容器最后一个数据
pop_front(); //删除容器第一个数据


指定位置操作：
insert(pos,elem); //在pos位置插入一个elem元素的拷贝，返回新数据的位置。
insert(pos,n,elem); //在pos位置插入n个elem数据，无返回值。
insert(pos,beg,end); //在pos位置插入[beg,end)区间的数据，无返回值。
clear(); //清空容器的所有数据
erase(beg,end); //删除[beg,end)区间的数据，返回下一个数据的位置。
erase(pos); //删除pos位置的数据，返回下一个数据的位置。
*/

void printDeque4(const deque<int>d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

void test22()
{
	//两端操作
	deque<int> d;
	d.push_back(10);
	d.push_back(20);

	d.push_front(100);
	d.push_front(200);

	printDeque4(d);

	d.pop_front();
	d.pop_back();
	printDeque4(d);


	//插入
	deque<int> d1;
	d1.push_back(10);
	d1.push_back(20);
	d1.push_front(100);
	d1.push_front(200);
	printDeque4(d1);

	d1.insert(d1.begin(),1000);
	printDeque4(d1);

	d1.insert(d1.begin(),2,10000);
	printDeque4(d1);

	deque<int>d2;
	d2.push_back(1);
	d2.push_back(2);
	d2.push_back(3);

	d2.insert(d2.begin(),d1.begin(),d1.end());
	printDeque4(d2);

	//删除
	deque<int> d3;
	d3.push_back(10);
	d3.push_back(20);
	d3.push_front(100);
	d3.push_front(200);
	printDeque4(d3);

	d3.erase(d3.begin());
	printDeque4(d3);

//	d3.erase(d3.begin(), d3.end());
	d3.clear();
	printDeque4(d3);
}

