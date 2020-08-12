#include<iostream>
using namespace std;
#include<string>

template<class nameType,class ageTye>
class Person
{
public:
	Person(nameType name, ageTye age)
	{
		this->m_Name = name;
		this->m_Age = age;
	}

	void showPerson()
	{
		cout << "name: " << this->m_Name << " age: " << this->m_Age << endl;
	}

	nameType m_Name;
	ageTye m_Age;
};

void test06()
{
	Person<string, int>p1("ËïÎò¿Õ",999);
	p1.showPerson();
}

