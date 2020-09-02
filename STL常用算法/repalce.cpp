#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

/*
replace(iterator beg, iterator end, oldvalue, newvalue);

// 将区间内旧元素 替换成 新元素

// beg 开始迭代器

// end 结束迭代器

// oldvalue 旧元素

// newvalue 新元素
*/

void myPrint3(int val)
{
	cout << val << "  ";
}

void test14()
{
	vector<int> v;
	v.push_back(20);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);
	v.push_back(50);
	v.push_back(10);
	v.push_back(20);

	replace(v.begin(), v.end(), 20, 200);
	for_each(v.begin(), v.end(), myPrint3);
	cout << endl;
}

