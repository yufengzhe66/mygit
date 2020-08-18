#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<string>

void test_vector2()
{
	//自定义数据类型
    class Person 
    {
	public:
		Person(string name, int age) {
			mName = name;
			mAge = age;
		}
	public:
		string mName;
		int mAge;
     };

    vector<Person>v1;
	Person p1("aaa", 10);
	Person p2("bbb", 20);
	Person p3("ccc", 30);
	Person p4("ddd", 40);
	Person p5("eee", 50);

	v1.push_back(p1);
	v1.push_back(p2);
	v1.push_back(p3);
	v1.push_back(p4);
	v1.push_back(p5);

	for (vector<Person>::iterator iter = v1.begin(); iter != v1.end(); iter++)
	{
		cout << "姓名：" << (*iter).mName << "  " << "年龄：" << iter->mAge << endl;
	}


	vector<Person*>v2;
	v2.push_back(&p1);
	v2.push_back(&p2);
	v2.push_back(&p3);
	v2.push_back(&p4);
	v2.push_back(&p5);
	for (vector<Person*>::iterator iter = v2.begin(); iter != v2.end(); iter++)
	{
		cout << "::姓名：" << (*iter)->mName << "  " << "年龄：" << (*iter)->mAge << endl;
	}

}

