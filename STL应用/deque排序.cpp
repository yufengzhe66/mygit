#include<iostream>
using namespace std;
#include<deque>
#include<algorithm>

/*
sort(iterator beg, iterator end) //对beg和end区间内元素进行排序
*/


void printDeque6(const deque<int>d)
{
	for (deque<int>::const_iterator it = d.begin(); it != d.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}



void test24()
{
	deque<int> d;
	d.push_back(10);
	d.push_back(20);
	d.push_front(100);
	d.push_front(200);
	printDeque6(d);

	sort(d.begin(),d.end());
	printDeque6(d);
}

int main()
{

	test24();

	system("pause");

	return 0;
}
