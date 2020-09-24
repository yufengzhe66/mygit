#include<iostream>
using namespace std;

class WeaponStrategy
{
public:
	virtual void UseWeapon() = 0;
};

class Knife :public WeaponStrategy
{
public:
	virtual void UseWeapon()
	{
		cout << "使用匕首！" << endl;
	}
};

class AK47 :public WeaponStrategy
{
public:
	virtual void UseWeapon()
	{
		cout << "使用AK47！" << endl;
	}
};


class Character
{
public:
	void setWeapon(WeaponStrategy* weapon)
	{
		this->pWeapon = weapon;
	}
	void ThrowWeapon()
	{
		this->pWeapon->UseWeapon();
	}

	WeaponStrategy* pWeapon;
};


void test08()
{
	Character* character = new Character;

	WeaponStrategy* knife = new Knife;
	WeaponStrategy* ak47 = new AK47;

	character->setWeapon(knife);
	character->ThrowWeapon();

	character->setWeapon(ak47);
	character->ThrowWeapon();

	delete ak47;
	delete knife;
	delete character;
}

