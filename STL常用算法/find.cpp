#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>


/*
find(iterator beg, iterator end, value);
// 按值查找元素，找到返回指定位置迭代器，找不到返回结束迭代器位置
// beg 开始迭代器
// end 结束迭代器
// value 查找的元素
*/

class Person1
{
public:
	Person1(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	//重载==
	bool operator==(const Person1& p)
	{
		if (this->age == p.age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	string name;
	int age;
};



void test03()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i+1);
	}

	vector<int>::iterator it = find(v1.begin(), v1.end(), 5);

	if (it == v1.end())
	{
		cout << "没有找到!" << endl;
	}
	else
	{
		cout << "找到:" << *it << endl;
	}

	vector<Person1> v2;

	//创建数据
	Person1 p1("aaa", 10);
	Person1 p2("bbb", 20);
	Person1 p3("ccc", 30);
	Person1 p4("ddd", 40);

	v2.push_back(p1);
	v2.push_back(p2);
	v2.push_back(p3);
	v2.push_back(p4);

	vector<Person1>::iterator pit = find(v2.begin(),v2.end(),p2);
	if (pit == v2.end())
	{
		cout << "没有找到!" << endl;
	}
	else
	{
		cout << "找到姓名:" << pit->name << " 年龄: " << pit->age << endl;
	}

}


