#define _CRT_SECUER_NO_WARNINGS
#include<iostream>
#include<string>
using namespace std;

class AbstractApple
{
public:
	virtual void ShowName() = 0;
};

//�й�ƻ��
class ChinaApple :public AbstractApple
{
public:
	virtual void ShowName()
	{
		cout << "�й�ƻ��" << endl;
	}
};

//����ƻ��
class USAApple :public AbstractApple
{
public:
	virtual void ShowName()
	{
		cout << "����ƻ��" << endl;
	}
};

class JAPApple :public AbstractApple
{
public:
	virtual void ShowName()
	{
		cout << "�ձ�ƻ��" << endl;
	}
};


class AbstractBanana
{
public:
	virtual void ShowName() = 0;
};

//�й��㽶
class ChinaBanana:public AbstractBanana
{
public:
	virtual void ShowName()
	{
		cout << "�й��㽶" << endl;
	}
};

//�����㽶
class USABanana:public AbstractBanana
{
public:
	virtual void ShowName()
	{
		cout << "�����㽶" << endl;
	}
};

class JAPBanana :public AbstractBanana
{
public:
	virtual void ShowName()
	{
		cout << "�ձ��㽶" << endl;
	}
};


class AbstractPear
{
public:
	virtual void ShowName() = 0;
};

//�й�Ѽ��
class ChinaPear:public AbstractPear
{
public:
	virtual void ShowName()
	{
		cout << "�й�Ѽ��" << endl;
	}
};

//����Ѽ��
class USAPear:public AbstractPear
{
public:
	virtual void ShowName()
	{
		cout << "����Ѽ��" << endl;
	}
};

class JAPPear:public AbstractPear
{
public:
	virtual void ShowName()
	{
		cout << "�ձ�Ѽ��" << endl;
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


