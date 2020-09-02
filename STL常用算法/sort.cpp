#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

/*
sort(iterator beg, iterator end, _Pred);

// 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置

// beg 开始迭代器

// end 结束迭代器

// _Pred 谓词
*/

void myPrint(int val)
{
	cout << val << "  ";
}

void test09()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);

	cout << "升序排序：" << endl;
	sort(v.begin(),v.end());
	for_each(v.begin(),v.end(),myPrint);
	cout << endl;

	cout << "降序排序：" << endl;
	sort(v.begin(),v.end(),greater<int>());
	for_each(v.begin(), v.end(), myPrint);
	cout << endl;
}

