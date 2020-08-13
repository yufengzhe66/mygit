#include<iostream>
using namespace std;
#include<string>

template<class NameType,class AgeType = int>
class Person 
{
public:
	Person(NameType name, AgeType age)
	{
		this->name = name;
		this->age = age;
	}

	void showPerson()
	{
		cout << "name: " << this->name << " age: " << this->age << endl;
	}

	NameType name;
	AgeType age;
};


//1.ָ�����������
void printPerson1(Person<string,int>&p)
{
	p.showPerson();
}


//2.����ģ�廯
template<typename T1,typename T2>
void printPerson2(Person<T1, T2>& p)
{
	p.showPerson();
	cout << "T1������Ϊ�� " << typeid(T1).name() << endl;
	cout << "T2������Ϊ�� " << typeid(T2).name() << endl;
}

//3.������ģ�廯
template<class T>
void printPerson3(T &p)
{
	p.showPerson();
	cout << "T������Ϊ�� " << typeid(T).name() << endl;
}

void test08()
{
	Person <string, int >p1("�����", 100);
	printPerson1(p1);

	Person <string, int >p2("��˽�", 90);
	printPerson2(p2);

	Person <string, int >p3("��ɮ", 30);
	printPerson3(p3);
}

int main()
{
	test08();
	return 0;
}