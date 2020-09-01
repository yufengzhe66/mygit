#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>


/*
find_if(iterator beg, iterator end, _Pred);
// 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
// beg 开始迭代器
// end 结束迭代器
// _Pred 函数或者谓词（返回bool类型的仿函数）
*/

class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};


class Person2
{
public:
	Person2(string name, int age)
	{
		this->name = name;
		this->age = age;
	}

	string name;
	int age;
};


class Greater20
{
public:
	bool operator()(Person2& p)
	{
		return p.age > 20;
	}
};


void test04()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}

	vector<int>::iterator it = find_if(v1.begin(), v1.end(), GreaterFive());

	if (it == v1.end())
	{
		cout << "没有找到!" << endl;
	}
	else
	{
		cout << "找到:" << *it << endl;
	}

	vector<Person2> v2;

	//创建数据
	Person2 p1("aaa", 10);
	Person2 p2("bbb", 20);
	Person2 p3("ccc", 30);
	Person2 p4("ddd", 40);

	v2.push_back(p1);
	v2.push_back(p2);
	v2.push_back(p3);
	v2.push_back(p4);

	vector<Person2>::iterator pit = find_if(v2.begin(), v2.end(), Greater20());
	if (pit == v2.end())
	{
		cout << "没有找到!" << endl;
	}
	else
	{
		cout << "找到姓名:" << pit->name << " 年龄: " << pit->age << endl;
	}

}
