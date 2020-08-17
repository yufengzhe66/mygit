#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


void myPrint(int val)
{
	cout << val << "  ";
}


void test_vector1()
{
	//创建容器，并存放数据
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back((i+1)*10);
	}
	cout << "--------第一种遍历方式-------" << endl;
	vector<int>::iterator vBegin = v.begin();
	vector<int>::iterator vEnd = v.end();

	//第一种方式
	for (; vBegin != v.end(); vBegin++)
	{
		cout << *vBegin << "  ";
	}
	cout << endl;
	cout << "--------第二种遍历方式-------" << endl;

	//第二种方式
	for (vector<int>::iterator iter = v.begin(); iter != v.end(); iter++)
	{
		cout << *iter << "  ";
	}


	cout << endl;
	cout << "--------第三种遍历方式-------" << endl;
	//第三种方式，利用内置的算法
	for_each(v.begin(),v.end(),myPrint);
}


int main()
{
	test_vector1();
	return 0;
}