#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>


/*
find_if(iterator beg, iterator end, _Pred);
// ��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��
// beg ��ʼ������
// end ����������
// _Pred ��������ν�ʣ�����bool���͵ķº�����
*/

class GreaterFive
{
public:
	bool operator()(int val)
	{
		return val > 5;
	}
};


class Person2
{
public:
	Person2(string name, int age)
	{
		this->name = name;
		this->age = age;
	}

	string name;
	int age;
};


class Greater20
{
public:
	bool operator()(Person2& p)
	{
		return p.age > 20;
	}
};


void test04()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i + 1);
	}

	vector<int>::iterator it = find_if(v1.begin(), v1.end(), GreaterFive());

	if (it == v1.end())
	{
		cout << "û���ҵ�!" << endl;
	}
	else
	{
		cout << "�ҵ�:" << *it << endl;
	}

	vector<Person2> v2;

	//��������
	Person2 p1("aaa", 10);
	Person2 p2("bbb", 20);
	Person2 p3("ccc", 30);
	Person2 p4("ddd", 40);

	v2.push_back(p1);
	v2.push_back(p2);
	v2.push_back(p3);
	v2.push_back(p4);

	vector<Person2>::iterator pit = find_if(v2.begin(), v2.end(), Greater20());
	if (pit == v2.end())
	{
		cout << "û���ҵ�!" << endl;
	}
	else
	{
		cout << "�ҵ�����:" << pit->name << " ����: " << pit->age << endl;
	}

}
