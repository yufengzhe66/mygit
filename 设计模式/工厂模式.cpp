#define _CRT_SECUER_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

//����ˮ��
class AbstractFruit
{
public:
	virtual void ShowName() = 0;
};

//ƻ��
class Apple :public AbstractFruit
{
public:
	virtual void ShowName()
	{
		cout << "����ƻ��" << endl;
	}
};

//�㽶
class Banana :public AbstractFruit
{
public:
	virtual void ShowName()
	{
		cout << "�����㽶" << endl;
	}
};

//Ѽ��
class Pear :public AbstractFruit
{
public:
	virtual void ShowName()
	{
		cout << "����Ѽ��" << endl;
	}
};


class AbstuactFactory
{
public:
	virtual AbstractFruit* CreateFruit() = 0;
};


class AppleFactory :public AbstuactFactory
{
public:
	virtual AbstractFruit* CreateFruit()
	{
		return new Apple;
	}
};


class BananaFactory :public AbstuactFactory
{
public:
	virtual AbstractFruit* CreateFruit()
	{
		return new Banana;
	}
};


class PearFactory :public AbstuactFactory
{
public:
	virtual AbstractFruit* CreateFruit()
	{
		return new Pear;
	}
};
void test02()
{
	AbstractFruit* fruit = NULL;
	AbstuactFactory* factory = NULL;

	factory = new AppleFactory();
	fruit = factory->CreateFruit();
	fruit->ShowName();
	delete fruit;
	delete factory;


	factory = new BananaFactory();
	fruit = factory->CreateFruit();
	fruit->ShowName();
	delete fruit;
	delete factory;

	
	factory = new PearFactory();
	fruit = factory->CreateFruit();
	fruit->ShowName();
	delete fruit;
	delete factory;

}

