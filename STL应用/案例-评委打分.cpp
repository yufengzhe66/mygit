#include<iostream>
using namespace std;
#include<vector>
#include<deque>
#include<string>
#include<cmath>
#include<algorithm>
#include<ctime>



/*
��5��ѡ�֣�ѡ��ABCDE��10����ί�ֱ��ÿһ��ѡ�ִ�֣�ȥ����߷֣�ȥ����ί����ͷ֣�ȡƽ���֡�

1.��������ѡ�֣��ŵ�vector��
2.����vector������ȡ����ÿһ��ѡ�֣�ִ��forѭ�������԰�10�����ִ�ִ浽deque������
3.sort�㷨��deque�����з�������ȥ����ߺ���ͷ�
4.deque��������һ�飬�ۼ��ܷ�
5.��ȡƽ����

*/

class Person
{
public:
	Person(string name, float score);

	string name;
	float score;
};

Person::Person(string name, float score)
{
	this->name = name;
	this->score = score;
}


void createPerson(vector<Person>&v)
{
	string nameSeed = "ABCDE";
	for (int i = 0; i < 5; i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];
		int score = 0;
		
		Person p(name,score);
		v.push_back(p);
	}
}

void setScore(vector<Person>& v)
{
	for (vector<Person>::iterator vit = v.begin(); vit != v.end(); vit++)
	{
		deque<int>d;
		int score;
		for (int i = 0; i < 10; i++)
		{
			score = rand() % 41 + 60;
			d.push_back(score);
		}


		cout << "ѡ�֣� " << vit->name << " ��֣� " << endl;
		for (deque<int>::iterator dit = d.begin(); dit != d.end(); dit++)
		{
			cout << *dit << " ";
		}
		cout << endl;


		sort(d.begin(), d.end());

		d.pop_back();
		d.pop_front();

		int sum = 0;
		for (deque<int>::iterator it = d.begin(); it != d.end(); it++)
		{
			sum += *it;
		}

		float avg = (float)sum / d.size();

		vit->score = avg;
	}

}

void showScore(vector<Person>& v)
{
	for (vector<Person>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "������ " << it->name << " ƽ���֣� " << it->score << endl;
	}
}

void test25()
{
	srand((unsigned int)time(NULL));

	vector<Person> v;
	createPerson(v);

	setScore(v);
	showScore(v);

}

int main()
{
	test25();

	system("pause");

	return 0;
}