#include<iostream>
using namespace std;

class DrinkTemplate
{
public:
	virtual void BoilWater() = 0;
	virtual void Brew() = 0;
	virtual void PourInCup() = 0;
	virtual void AddSomething() = 0;

	void Make()
	{
		BoilWater();
		Brew();
		PourInCup();
		AddSomething();
	}
};


class Coffee :public DrinkTemplate
{
public:
	virtual void BoilWater()
	{
		cout << "煮山泉水..." << endl;
	}
	virtual void Brew()
	{
		cout << "冲泡咖啡..." << endl;
	}
	virtual void PourInCup()
	{
		cout << "咖啡倒入杯中..." << endl;
	}
	virtual void AddSomething()
	{
		cout << "加糖，加牛奶，加点醋..." << endl;
	}
};

class Tea :public DrinkTemplate
{
public:
	virtual void BoilWater()
	{
		cout << "煮自来水..." << endl;
	}
	virtual void Brew()
	{
		cout << "冲泡铁观音..." << endl;
	}
	virtual void PourInCup()
	{
		cout << "茶水倒入杯中..." << endl;
	}
	virtual void AddSomething()
	{
		cout << "加糖，加柠檬，加生姜..." << endl;
	}
};


void test07()
{
	Tea* tea = new Tea;
	tea->Make();
	cout << "-----------------------------" << endl;
	Coffee* coffee = new Coffee;
	coffee->Make();
}

