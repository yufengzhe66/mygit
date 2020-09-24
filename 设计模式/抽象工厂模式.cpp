#define _CRT_SECUER_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class AbstractApple
{
public:
	virtual void ShowName() = 0;
};

//中国苹果
class ChinaApple :public AbstractApple
{
public:
	virtual void ShowName()
	{
		cout << "中国苹果" << endl;
	}
};

//美国苹果
class USAApple :public AbstractApple
{
public:
	virtual void ShowName()
	{
		cout << "美国苹果" << endl;
	}
};

class JAPApple :public AbstractApple
{
public:
	virtual void ShowName()
	{
		cout << "日本苹果" << endl;
	}
};


class AbstractBanana
{
public:
	virtual void ShowName() = 0;
};

//中国香蕉
class ChinaBanana:public AbstractBanana
{
public:
	virtual void ShowName()
	{
		cout << "中国香蕉" << endl;
	}
};

//美国香蕉
class USABanana:public AbstractBanana
{
public:
	virtual void ShowName()
	{
		cout << "美国香蕉" << endl;
	}
};

class JAPBanana :public AbstractBanana
{
public:
	virtual void ShowName()
	{
		cout << "日本香蕉" << endl;
	}
};


class AbstractPear
{
public:
	virtual void ShowName() = 0;
};

//中国鸭梨
class ChinaPear:public AbstractPear
{
public:
	virtual void ShowName()
	{
		cout << "中国鸭梨" << endl;
	}
};

//美国鸭梨
class USAPear:public AbstractPear
{
public:
	virtual void ShowName()
	{
		cout << "美国鸭梨" << endl;
	}
};

class JAPPear:public AbstractPear
{
public:
	virtual void ShowName()
	{
		cout << "日本鸭梨" << endl;
	}
};


class AbstractFactory
{
public:
	virtual AbstractApple* CreateApple() = 0;
	virtual AbstractBanana* CreateBanana() = 0;
	virtual AbstractPear* CreatePear() = 0;
};

class ChinaFactory:public AbstractFactory
{
public:
	virtual AbstractApple* CreateApple()
	{
		return new ChinaApple;
	}
	virtual AbstractBanana* CreateBanana()
	{
		return new ChinaBanana;
	}
	virtual AbstractPear* CreatePear()
	{
		return new ChinaPear;
	}
};

class USAFactory:public AbstractFactory
{
public:
	virtual AbstractApple* CreateApple()
	{
		return new USAApple;
	}
	virtual AbstractBanana* CreateBanana()
	{
		return new USABanana;
	}
	virtual AbstractPear* CreatePear()
	{
		return new USAPear;
	}
};

class JAPFactory:public AbstractFactory
{
public:
	virtual AbstractApple* CreateApple()
	{
		return new JAPApple;
	}
	virtual AbstractBanana* CreateBanana()
	{
		return new JAPBanana;
	}
	virtual AbstractPear* CreatePear()
	{
		return new JAPPear;
	}
};

void test03()
{
	AbstractFactory* factory = NULL;
	AbstractApple* apple = NULL;
	AbstractBanana* banana = NULL;
	AbstractPear* pear = NULL;

	factory = new ChinaFactory;
	apple = factory->CreateApple();
	banana = factory->CreateBanana();
	pear = factory->CreatePear();
	apple->ShowName();
	banana->ShowName();
	pear->ShowName();

	delete apple;
	delete banana;
	delete pear;
	delete factory;


	factory = new USAFactory;
	apple = factory->CreateApple();
	banana = factory->CreateBanana();
	pear = factory->CreatePear();
	apple->ShowName();
	banana->ShowName();
	pear->ShowName();

	delete apple;
	delete banana;
	delete pear;
	delete factory;


	factory = new JAPFactory;
	apple = factory->CreateApple();
	banana = factory->CreateBanana();
	pear = factory->CreatePear();
	apple->ShowName();
	banana->ShowName();
	pear->ShowName();

	delete apple;
	delete banana;
	delete pear;
	delete factory;
}


