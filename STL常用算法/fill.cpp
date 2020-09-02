#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<numeric>

/*
fill(iterator beg, iterator end, value);

// 向容器中填充元素

// beg 开始迭代器

// end 结束迭代器

// value 填充的值
*/

void myPrint6(int val)
{
	cout << val << "  ";
}

void test18()
{
	vector<int > v;
	v.resize(10);
	fill(v.begin(),v.end(),100);
	for_each(v.begin(),v.end(),myPrint6);
}

