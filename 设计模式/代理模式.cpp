#define _CRT_SECUER_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;


class AbstractCommonInterface
{
public:
	virtual void run() = 0;
};

class MySystem :public AbstractCommonInterface
{
public:
	virtual void run()
	{
		cout << "系统启动..." << endl;
	}
};

class MySystemProxy :public AbstractCommonInterface
{
public:
	MySystemProxy(string username, string password)
	{
		this->username = username;
		this->password = password;
		this->system = new MySystem;
	}
	bool check()
	{
		if(this->username=="admin"&&this->password=="admin")
		{
			return true;
		}
		else
		{
			return false;
		}	
	}
	virtual void run()
	{
		if (check())
		{
			cout << "用户名和密码正确" << endl;
			this->system->run();
		}
		else
		{
			cout << "用户名或密码错误，权限不足..." << endl;
		}
	}
	~MySystemProxy()
	{
		if (system != NULL)
		{
			delete this->system;
		}
	}
	MySystem* system;
	string username;
	string password;
};




void test05()
{
	MySystemProxy* proxy = new MySystemProxy("root","admin");
	proxy->run();
}

