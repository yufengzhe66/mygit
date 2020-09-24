#define _CRT_SECUER_NO_WARNINGS
#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Myprint
{
public:
	void operator()(int v1, int v2)
	{
		cout << v1 + v2 << endl;
	}
};

class target
{
public:
	virtual void operator()(int v) = 0;
};

class Adapter :public target
{
public:
	Adapter(int param)
	{
		this->param = param;
	}
	virtual void operator()(int v)
	{
		print(v, param);
	}
	Myprint print;
	int param;
};


Adapter MyBind2nd(int v)
{
	return Adapter(v);
}


void test06()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	for_each(v.begin(), v.end(), MyBind2nd(10));
}

