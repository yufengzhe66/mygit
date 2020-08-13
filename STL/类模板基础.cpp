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
//类模板没有自动类型推导使用方式，必须显式指定类型（参数列表）

//类模板在参数列表中可以有默认参数（即在进行模板声明时，可以指定默认类型）
// template< class nameType = string, class ageTye = int >
void test06()
{
	Person<string, int>p1("孙悟空",999);
	p1.showPerson();
}

