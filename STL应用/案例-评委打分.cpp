#include<iostream>
using namespace std;
#include<vector>
#include<deque>
#include<string>
#include<cmath>
#include<algorithm>
#include<ctime>



/*
有5名选手：选手ABCDE，10个评委分别对每一名选手打分，去除最高分，去除评委中最低分，取平均分。

1.创建五名选手，放到vector中
2.遍历vector容器，取出来每一个选手，执行for循环，可以把10个评分打分存到deque容器中
3.sort算法对deque容器中分数排序，去除最高和最低分
4.deque容器遍历一遍，累加总分
5.获取平均分

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
		string name = "选手";
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


		cout << "选手： " << vit->name << " 打分： " << endl;
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
		cout << "姓名： " << it->name << " 平均分： " << it->score << endl;
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