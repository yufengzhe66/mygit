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
	//׼������
	person p1("��ɮ", 30);
	person p2("�����", 1000);
	person p3("��˽�", 900);
	person p4("ɳɮ", 800);

	//����������Ԫ��  ��Ӳ���
	q.push(p1);
	q.push(p2);
	q.push(p3);
	q.push(p4);
	cout << "���д�СΪ��" << q.size() << endl;
	while (!q.empty())
	{
		cout << "��ͷԪ��-- ������ " << q.front().m_Name
			<< " ���䣺 " << q.front().m_Age << endl;

		cout << "��βԪ��-- ������ " << q.back().m_Name
			<< " ���䣺 " << q.back().m_Age << endl;

		cout << endl;
		//������ͷԪ��
		q.pop();
	}

	cout << "���д�СΪ��" << q.size() << endl;
}


