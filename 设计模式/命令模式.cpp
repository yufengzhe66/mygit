#include<iostream>
using namespace std;
#include<queue>
#include<Windows.h>

class HandleClientProtocol
{
public:
	void AddMoney()
	{
		cout << "给玩家增加金币！" << endl;
	}

	void AddDiamond()
	{
		cout << "给玩家增加钻石！" << endl;
	}

	void AddEquipment()
	{
		cout << "给玩家穿装备！" << endl;
	}

	void AddLevel()
	{
		cout << "给玩家升级！" << endl;
	}
};


class AbstractCommand
{
public:
	virtual void handle() = 0;
};


class AddMoneyCommand :public AbstractCommand
{
public:
	AddMoneyCommand(HandleClientProtocol* protocol)
	{
		this->protocol = protocol;
	}
	virtual void handle()
	{
		this->protocol->AddMoney();
	}
	HandleClientProtocol* protocol;
};


class AddEquipmentCommand :public AbstractCommand
{
public:
	AddEquipmentCommand(HandleClientProtocol* protocol)
	{
		this->protocol = protocol;
	}
	virtual void handle()
	{
		this->protocol->AddEquipment();
	}
	HandleClientProtocol* protocol;
};


class AddDiamondCommand :public AbstractCommand
{
public:
	AddDiamondCommand(HandleClientProtocol* protocol)
	{
		this->protocol = protocol;
	}
	virtual void handle()
	{
		this->protocol->AddDiamond();
	}
	HandleClientProtocol* protocol;
};


class AddLevelCommand :public AbstractCommand
{
public:
	AddLevelCommand(HandleClientProtocol* protocol)
	{
		this->protocol = protocol;
	}
	virtual void handle()
	{
		this->protocol->AddLevel();
	}
	HandleClientProtocol* protocol;
};



class Sever 
{
public:
	void addRequest(AbstractCommand* command)
	{
		this->mCommands.push(command);
	}
	void startHandle()
	{
		while (!mCommands.empty())
		{
			Sleep(2000);
			AbstractCommand* command = mCommands.front();
			command->handle();
			mCommands.pop();
		}
	}
	queue<AbstractCommand*>mCommands;
};

void test09()
{
	HandleClientProtocol* protocol = new HandleClientProtocol;

	AbstractCommand* addmoney = new AddMoneyCommand(protocol);
	AbstractCommand* addequipment = new AddEquipmentCommand(protocol);
	AbstractCommand* adddiamond = new AddDiamondCommand(protocol);
	AbstractCommand* addlevel = new AddLevelCommand(protocol);

	Sever* sever = new Sever;
	sever->addRequest(addmoney);
	sever->addRequest(adddiamond);
	sever->addRequest(addequipment);
	sever->addRequest(addlevel);
	
	sever->startHandle();
}


int main()
{
	test09();
	system("pause");
	return 0;
}