#include<iostream>
using namespace std;
#include<list>
#include<string>

class heros
{
public:
	heros(string name, int age, int height)
	{
		this->name = name;
		this->age = age;
		this->height = height;
	}
	string name;
	int age;
	int height;
};

//�������������򣩣�������ͬ����������򣨽���
bool compareHeros(heros& h1, heros& h2)
{
	if (h1.age == h2.age)
	{
		return h1.height > h2.height;
	}
	else
	{
		return h1.age < h2.age;
	}
}


void test34()
{
	list<heros> L;
	heros p1("����", 35, 175);
	heros p2("�ܲ�", 45, 180);
	heros p3("��Ȩ", 40, 170);
	heros p4("����", 25, 190);
	heros p5("�ŷ�", 35, 160);
	heros p6("����", 35, 200);

	L.push_back(p1);
	L.push_back(p2);
	L.push_back(p3);
	L.push_back(p4);
	L.push_back(p5);
	L.push_back(p6);

	for (list<heros>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout<<"������"<<(*it).name<< " ���䣺 " << it->age
			<< " ��ߣ� " << it->height << endl;
	}

	cout << "-----------�����--------------" << endl;
	L.sort(compareHeros);

	for (list<heros>::iterator it = L.begin(); it != L.end(); it++)
	{
		cout << "������" << (*it).name << " ���䣺 " << it->age
			<< " ��ߣ� " << it->height << endl;
	}
}


int main()
{

	test34();

	system("pause");

	return 0;
}