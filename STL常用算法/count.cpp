#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

/*
count(iterator beg, iterator end, value);

// ͳ��Ԫ�س��ִ���

// beg ��ʼ������

// end ����������

// value ͳ�Ƶ�Ԫ��
*/

class Person3
{
public:
	Person3(string name, int age)
	{
		this->name = name;
		this->age = age;
	}
	//����==
	bool operator==(const Person3& p)
	{
		if (this->age == p.age)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

	string name;
	int age;
};

void test07()
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(4);

	int num1 = count(v1.begin(), v1.end(), 4);
	cout << "4�ĸ���Ϊ�� " << num1 << endl;

	vector<Person3> v2;

	Person3 p1("����", 35);
	Person3 p2("����", 35);
	Person3 p3("�ŷ�", 35);
	Person3 p4("����", 30);
	Person3 p5("�ܲ�", 25);

	v2.push_back(p1);
	v2.push_back(p2);
	v2.push_back(p3);
	v2.push_back(p4);
	v2.push_back(p5);

	Person3 p("�����", 35);
	int num2 = count(v2.begin(),v2.end(),p);
	cout << "num2�ĸ���Ϊ�� " << num2 << endl;
}

