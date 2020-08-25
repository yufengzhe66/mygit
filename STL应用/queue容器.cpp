#include<iostream>
using namespace std;
#include<string>
#include<queue>


class person
{
public:
	person(string name, int age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	string m_Name;
	int m_Age;
};

void test27()
{
	queue<person> q;
	//准备数据
	person p1("唐僧", 30);
	person p2("孙悟空", 1000);
	person p3("猪八戒", 900);
	person p4("沙僧", 800);

	//向队列中添加元素  入队操作
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);
	cout << "队列大小为：" << q.size() << endl;
	while (!q.empty())
	{
		cout << "队头元素-- 姓名： " << q.front().m_Name
			<< " 年龄： " << q.front().m_Age << endl;

		cout << "队尾元素-- 姓名： " << q.back().m_Name
			<< " 年龄： " << q.back().m_Age << endl;

		cout << endl;
		//弹出队头元素
		q.pop();
	}

	cout << "队列大小为：" << q.size() << endl;
}


