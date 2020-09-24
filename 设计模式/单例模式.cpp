#define _CRT_SECUER_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

/*
ʵ�ֵ������裺
1.���캯��˽�л�
2.���Ӿ�̬˽�еĵ�ǰ���ָ�����
3.�ṩ��̬����ӿڣ��������û���õ�������
*/

//������Ϊ����ʽ ����ʽ
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

	//���ܶ������ֺ�������Ϊ�ͷŴ���ᵼ��ϵͳ�������⣻
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
	//һ�ֵ���ģʽ�ͷŲ��ԣ�û��Ҫ�ͷŵ���ģʽ�Ķ��󣬴����������ڽ����󣬻ᱻ�Զ�����
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
	Singleton_lazy(){ cout << "��������ʽ����" << endl; }
	
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
	Singleton_hungry() { cout << "���Ƕ���ʽ����" << endl; }
	
	static Singleton_hungry* pSingleton;
};

Singleton_hungry* Singleton_hungry::pSingleton = new Singleton_hungry;


void test04()
{
	cout << "main������ʼִ��" << endl;

	Singleton_lazy* p1 = Singleton_lazy::getInstance();
	Singleton_lazy* p2 = Singleton_lazy::getInstance();
	if (p1 == p2)
	{
		cout << "����ָ��ָ��ͬһ���ڴ�ռ䣬�ǵ���" << endl;
	}
	else
	{
		cout << "���ǵ���ģʽ��" << endl;
	}

	Singleton_hungry* p3 = Singleton_hungry::getInstance();
	Singleton_hungry* p4 = Singleton_hungry::getInstance();
	if (p3 == p4)
	{
		cout << "����ָ��ָ��ͬһ���ڴ�ռ䣬�ǵ���" << endl;
	}
	else
	{
		cout << "���ǵ���ģʽ��" << endl;
	}
}


