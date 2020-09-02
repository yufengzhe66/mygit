#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

/*
replace_if(iterator beg, iterator end, _pred, newvalue);

// 按条件替换元素，满足条件的替换成指定元素

// beg 开始迭代器

// end 结束迭代器

// _pred 谓词

// newvalue 替换的新元素
*/

void myPrint4(int val)
{
	cout << val << "  ";
}

class ReplaceGreater30
{
public:
	bool operator()(int val)
	{
		return val > 30;
	}
};

void test15()
{
	vector<int> v;
	v.push_back(20);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);
	v.push_back(50);
	v.push_back(10);
	v.push_back(20);

	replace_if(v.begin(), v.end(), ReplaceGreater30(), 200);
	for_each(v.begin(), v.end(), myPrint4);
	cout << endl;
}

