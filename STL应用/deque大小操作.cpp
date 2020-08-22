﻿#include<iostream>
using namespace std;
#include<deque>


/*
deque.empty(); //判断容器是否为空

deque.size(); //返回容器中元素的个数

deque.resize(num); //重新指定容器的长度为num,若容器变长，则以默认值填充新位置。

​ //如果容器变短，则末尾超出容器长度的元素被删除。

deque.resize(num, elem); //重新指定容器的长度为num,若容器变长，则以elem值填充新位置。

​ //如果容器变短，则末尾超出容器长度的元素被删除。
*/


void printDeque3(const deque<int>d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}

void test21()
{
	deque<int> d1;
	for (int i = 0; i < 10; i++)
		d1.push_back(i);

	printDeque3(d1);

	if(d1.empty())
	{
		cout << "d1为空!" << endl;
	}
	else {
		cout << "d1不为空!" << endl;
		//统计大小
		cout << "d1的大小为：" << d1.size() << endl;
	}

	d1.resize(15, 1);
	printDeque3(d1);

	d1.resize(5);
	printDeque3(d1);
}

