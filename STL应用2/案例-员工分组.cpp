#include<iostream>
using namespace std;
#include<vector>
#include<string>
#include<map>
#include<ctime>


#define CEHUA  0
#define MEISHU 1
#define YANFA  2


/*
案例描述
公司今天招聘了10个员工（ABCDEFGHIJ），10名员工进入公司之后，需要指派员工在那个部门工作
员工信息有: 姓名 工资组成；部门分为：策划、美术、研发
随机给10名员工分配部门和工资
通过multimap进行信息的插入 key(部门编号) value(员工)
分部门显示员工信息

实现步骤
创建10名员工，放到vector中
遍历vector容器，取出每个员工，进行随机分组
分组后，将员工部门编号作为key，具体员工作为value，放入到multimap容器中
分部门显示员工信息
*/

class Worker
{
public:
	string name;
	int salary;
};



void createWorker(vector<Worker>&v)
{
	string stringName = "员工";
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.name = stringName + nameSeed[i];
		worker.salary = rand() % 10001 + 10000;
		v.push_back(worker);
	}
}

//员工分组
void setGroup(vector<Worker>&v, multimap<int,Worker>&m)
{
	for (vector<Worker>::iterator it = v.begin(); it != v.end(); it++)
	{
		int deptId = rand() % 3;
		m.insert(make_pair(deptId,*it));
	}
}

void showWorkerByGroup(const multimap<int,Worker>&m)
{
	cout << "策划部门：" << endl;
	multimap<int, Worker>::const_iterator pos = m.find(CEHUA);
	int count = m.count(CEHUA);
	for (int i = 0; i < count; i++, pos++)
	{
		cout << "姓名： " << pos->second.name << " 工资： " << pos->second.salary << endl;
	}

	cout << "美术部门：" << endl;
	pos = m.find(MEISHU);
	count = m.count(MEISHU);
	for (int i = 0; i < count; i++, pos++)
	{
		cout << "姓名： " << pos->second.name << " 工资： " << pos->second.salary << endl;
	}

	cout << "研发部门：" << endl;
	pos = m.find(YANFA);
	count = m.count(YANFA);
	for (int i = 0; i < count; i++, pos++)
	{
		cout << "姓名： " << pos->second.name << " 工资： " << pos->second.salary << endl;
	}
}

int main()
{
	while (true)
	{
		srand((unsigned)time(NULL));
		vector<Worker> v;
		multimap<int, Worker> m;
		createWorker(v);
		setGroup(v, m);
		showWorkerByGroup(m);
		system("pause");
		cout << endl << endl << endl;
	}
	return 0;
}
