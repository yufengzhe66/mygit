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
		cout << "��ɽȪˮ..." << endl;
	}
	virtual void Brew()
	{
		cout << "���ݿ���..." << endl;
	}
	virtual void PourInCup()
	{
		cout << "���ȵ��뱭��..." << endl;
	}
	virtual void AddSomething()
	{
		cout << "���ǣ���ţ�̣��ӵ��..." << endl;
	}
};

class Tea :public DrinkTemplate
{
public:
	virtual void BoilWater()
	{
		cout << "������ˮ..." << endl;
	}
	virtual void Brew()
	{
		cout << "����������..." << endl;
	}
	virtual void PourInCup()
	{
		cout << "��ˮ���뱭��..." << endl;
	}
	virtual void AddSomething()
	{
		cout << "���ǣ������ʣ�������..." << endl;
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

