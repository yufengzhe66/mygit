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
		return p1.age > p2.age;//½µĞò
	}
};

void test08()
{
	set<Person,PersonCompare>s;
	Person p1("Áõ±¸", 24);
	Person p2("¹ØÓğ", 27);
	Person p3("ÕÅ·É", 25);
	Person p4("ÕÔÔÆ", 21);

	s.insert(p1);
	s.insert(p2);
	s.insert(p3);
	s.insert(p4);
	
	for (set<Person>::iterator it = s.begin(); it != s.end(); it++)
	{
		cout << "ĞÕÃû£º " << it->name << " ÄêÁä£º " << it->age << endl;
	}
}

int main()
{

	test08();

	system("pause");

	return 0;
}
