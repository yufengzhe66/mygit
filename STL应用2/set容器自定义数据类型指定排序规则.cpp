#include<iostream>
using namespace std;
#include<set>
#include<string>

class Person
{
public:
	Person(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	string name;
	int age;
};

class PersonCompare
{
public:
	bool operator()(const Person& p1, const Person& p2)const
	{
		return p1.age > p2.age;//����
	}
};

void test08()
{
	set<Person,PersonCompare>s;
	Person p1("����", 24);
	Person p2("����", 27);
	Person p3("�ŷ�", 25);
	Person p4("����", 21);

	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	
	for (set<Person>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "������ " << it->name << " ���䣺 " << it->age << endl;
	}
}

int main()
{

	test08();

	system("pause");

	return 0;
}
