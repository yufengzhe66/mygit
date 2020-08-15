#include "myArray.hpp"


void printIntArray(myArray<int>&arr)
{
	for (int i = 0; i < arr.getSize(); i++) 
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}

void test13()
{
	myArray<int> array1(10);
	for (int i = 0; i < 10; i++)
	{
		array1.push_back(i);
	}
	cout << "array1��ӡ�����" << endl;
	printIntArray(array1);
	cout << "array1�Ĵ�С��" << array1.getSize() << endl;
	cout << "array1��������" << array1.getCapacity() << endl;

	cout << "--------------------------" << endl;

	myArray<int> array2(array1);
	array2.pop_back();
	cout << "array2��ӡ�����" << endl;
	printIntArray(array2);
	cout << "array2�Ĵ�С��" << array2.getSize() << endl;
	cout << "array2��������" << array2.getCapacity() << endl;
	cout << "--------------------------" << endl;
}


//�����Զ�����������
class Person {
public:
	Person() {}
	Person(string name, int age) {
		this->m_Name = name;
		this->m_Age = age;
	}
public:
	string m_Name;
	int m_Age;
};

void printPersonArray(myArray<Person>& personArr)
{
	for (int i = 0; i < personArr.getSize(); i++) 
	{
		cout << "������" << personArr[i].m_Name << " ���䣺 " << personArr[i].m_Age << endl;
	}

}

void test14()
{
	//��������
	myArray<Person> pArray(10);
	Person p1("�����", 30);
	Person p2("����", 20);
	Person p3("槼�", 18);
	Person p4("���Ѿ�", 15);
	Person p5("����", 24);

	//��������
	pArray.push_back(p1);
	pArray.push_back(p2);
	pArray.push_back(p3);
	pArray.push_back(p4);
	pArray.push_back(p5);

	printPersonArray(pArray);

	cout << "pArray�Ĵ�С��" << pArray.getSize() << endl;
	cout << "pArray��������" << pArray.getCapacity() << endl;
}


int main()
{
	test13();
	test14();
	return 0;
}