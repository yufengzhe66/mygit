#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

/*
count_if(iterator beg, iterator end, _Pred);

// 按条件统计元素出现次数

// beg 开始迭代器

// end 结束迭代器

// _Pred 谓词
*/

class Greater4
{
public:
	bool operator()(int val)
	{
		return val >= 4;
	}
};


class Person4
{
public:
	Person4(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	//重载==
	bool operator==(const Person4& p)
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

class AgeLess35
{
public:
	bool operator()(const Person4& p)
	{
		return p.age < 35;
	}
};


void test08()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(4);

	int num1 = count_if(v1.begin(), v1.end(), Greater4());
	cout << "大于4的个数为： " << num1 << endl;

	vector<Person4> v2;

	Person4 p1("刘备", 35);
	Person4 p2("关羽", 35);
	Person4 p3("张飞", 35);
	Person4 p4("赵云", 30);
	Person4 p5("曹操", 25);

	v2.push_back(p1);
	v2.push_back(p2);
	v2.push_back(p3);
	v2.push_back(p4);
	v2.push_back(p5);

	Person4 p("诸葛亮", 35);
	int num2 = count_if(v2.begin(), v2.end(), AgeLess35());
	cout << "小于35岁的个数： " << num2 << endl;
}

int main()
{
	test08();
	system("pause");
	return 0;
}