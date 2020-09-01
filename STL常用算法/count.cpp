#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

/*
count(iterator beg, iterator end, value);

// 统计元素出现次数

// beg 开始迭代器

// end 结束迭代器

// value 统计的元素
*/

class Person3
{
public:
	Person3(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	//重载==
	bool operator==(const Person3& p)
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

void test07()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(4);

	int num1 = count(v1.begin(), v1.end(), 4);
	cout << "4的个数为： " << num1 << endl;

	vector<Person3> v2;

	Person3 p1("刘备", 35);
	Person3 p2("关羽", 35);
	Person3 p3("张飞", 35);
	Person3 p4("赵云", 30);
	Person3 p5("曹操", 25);

	v2.push_back(p1);
	v2.push_back(p2);
	v2.push_back(p3);
	v2.push_back(p4);
	v2.push_back(p5);

	Person3 p("诸葛亮", 35);
	int num2 = count(v2.begin(),v2.end(),p);
	cout << "num2的个数为： " << num2 << endl;
}

