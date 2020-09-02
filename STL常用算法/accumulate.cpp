#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<numeric>

/*
accumulate(iterator beg, iterator end, value);

// 计算容器元素累计总和

// beg 开始迭代器

// end 结束迭代器

// value 起始值(基值)
*/

void test17()
{
	vector<int> v;
	for (int i = 0; i <= 100; i++)
	{
		v.push_back(i);
	}

	int total = accumulate(v.begin(),v.end(),0);

	cout << "total = " << total << endl;
}

