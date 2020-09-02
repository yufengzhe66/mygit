#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<ctime>

/*
random_shuffle(iterator beg, iterator end);

// 指定范围内的元素随机调整次序

// beg 开始迭代器

// end 结束迭代器

*/

void myPrint1(int val)
{
	cout << val << "  ";
}

void test10()
{
	vector<int> v;
	
	srand((unsigned int)time(NULL));

	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	for_each(v.begin(),v.end(),myPrint1);
	cout << endl;

	random_shuffle(v.begin(),v.end());

	for_each(v.begin(), v.end(), myPrint1);
	cout << endl;
}

