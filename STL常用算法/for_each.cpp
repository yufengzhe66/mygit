#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


/*
for_each(iterator beg, iterator end, _func);
// 遍历算法 遍历容器元素
// beg 开始迭代器
// end 结束迭代器
// _func (普通)函数或者函数对象(仿函数)
*/

//普通函数
void print01(int val)
{
	cout << val << "  ";
}


//仿函数
class print02
{
public:
	void operator()(int val)
	{
		cout << val << "  ";
	}
};

void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(),v.end(),print01);
	cout << endl;
	for_each(v.begin(),v.end(),print02());
	cout << endl;
}

