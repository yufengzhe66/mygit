#define _CRT_SECUER_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

/*
实现单例步骤：
1.构造函数私有化
2.增加静态私有的当前类的指针变量
3.提供静态对外接口，可以让用户获得单例对象
*/

//单例分为懒汉式 饿汉式
class Singleton_lazy
{
public:
	static Singleton_lazy* getInstance()
	{
		if (pSingleton == NULL)
		{
			pSingleton = new Singleton_lazy;
		}
		return pSingleton;
	}

	//不能定义这种函数，因为释放错误会导致系统产生问题；
#if 0
	static void freeSpace()
	{
		if (pSingleton != NULL)
		{
			delete pSingleton;
			pSingleton = NULL;
		}
	}
#endif
	//一种单例模式释放策略，没必要释放单例模式的对象，待其生命周期结束后，会被自动回收
	class Garbo {
		~Garbo()
		{
			if (pSingleton != NULL)
			{
				delete pSingleton;
			}
		}
	};

private:
	Singleton_lazy(){ cout << "我是懒汉式构造" << endl; }
	
	static Singleton_lazy* pSingleton;
};

Singleton_lazy* Singleton_lazy::pSingleton = NULL;


class Singleton_hungry
{
public:
	static Singleton_hungry* getInstance()
	{
		return pSingleton;
	}
private:
	Singleton_hungry() { cout << "我是饿汉式构造" << endl; }
	
	static Singleton_hungry* pSingleton;
};

Singleton_hungry* Singleton_hungry::pSingleton = new Singleton_hungry;


void test04()
{
	cout << "main函数开始执行" << endl;

	Singleton_lazy* p1 = Singleton_lazy::getInstance();
	Singleton_lazy* p2 = Singleton_lazy::getInstance();
	if (p1 == p2)
	{
		cout << "两个指针指向同一块内存空间，是单例" << endl;
	}
	else
	{
		cout << "不是单例模式！" << endl;
	}

	Singleton_hungry* p3 = Singleton_hungry::getInstance();
	Singleton_hungry* p4 = Singleton_hungry::getInstance();
	if (p3 == p4)
	{
		cout << "两个指针指向同一块内存空间，是单例" << endl;
	}
	else
	{
		cout << "不是单例模式！" << endl;
	}
}


