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
//��ģ��û���Զ������Ƶ�ʹ�÷�ʽ��������ʽָ�����ͣ������б�

//��ģ���ڲ����б��п�����Ĭ�ϲ��������ڽ���ģ������ʱ������ָ��Ĭ�����ͣ�
// template< class nameType = string, class ageTye = int >
void test06()
{
	Person<string, int>p1("�����",999);
	p1.showPerson();
}

