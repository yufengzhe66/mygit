#define _CRT_SECUER_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

//抽象水果
class AbstractFruit
{
public:
	virtual void ShowName() = 0;
};

//苹果
class Apple :public AbstractFruit
{
public:
	virtual void ShowName()
	{
		cout << "我是苹果" << endl;
	}
};

//香蕉
class Banana :public AbstractFruit
{
public:
	virtual void ShowName()
	{
		cout << "我是香蕉" << endl;
	}
};

//鸭梨
class Pear :public AbstractFruit
{
public:
	virtual void ShowName()
	{
		cout << "我是鸭梨" << endl;
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

