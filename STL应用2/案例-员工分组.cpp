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
��������
��˾������Ƹ��10��Ա����ABCDEFGHIJ����10��Ա�����빫˾֮����Ҫָ��Ա�����Ǹ����Ź���
Ա����Ϣ��: ���� ������ɣ����ŷ�Ϊ���߻����������з�
�����10��Ա�����䲿�ź͹���
ͨ��multimap������Ϣ�Ĳ��� key(���ű��) value(Ա��)
�ֲ�����ʾԱ����Ϣ

ʵ�ֲ���
����10��Ա�����ŵ�vector��
����vector������ȡ��ÿ��Ա���������������
����󣬽�Ա�����ű����Ϊkey������Ա����Ϊvalue�����뵽multimap������
�ֲ�����ʾԱ����Ϣ
*/

class Worker
{
public:
	string name;
	int salary;
};



void createWorker(vector<Worker>&v)
{
	string stringName = "Ա��";
	string nameSeed = "ABCDEFGHIJ";
	for (int i = 0; i < 10; i++)
	{
		Worker worker;
		worker.name = stringName + nameSeed[i];
		worker.salary = rand() % 10001 + 10000;
		v.push_back(worker);
	}
}

//Ա������
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
	cout << "�߻����ţ�" << endl;
	multimap<int, Worker>::const_iterator pos = m.find(CEHUA);
	int count = m.count(CEHUA);
	for (int i = 0; i < count; i++, pos++)
	{
		cout << "������ " << pos->second.name << " ���ʣ� " << pos->second.salary << endl;
	}

	cout << "�������ţ�" << endl;
	pos = m.find(MEISHU);
	count = m.count(MEISHU);
	for (int i = 0; i < count; i++, pos++)
	{
		cout << "������ " << pos->second.name << " ���ʣ� " << pos->second.salary << endl;
	}

	cout << "�з����ţ�" << endl;
	pos = m.find(YANFA);
	count = m.count(YANFA);
	for (int i = 0; i < count; i++, pos++)
	{
		cout << "������ " << pos->second.name << " ���ʣ� " << pos->second.salary << endl;
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
