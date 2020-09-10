#pragma once
#include "Identity.h"
#include<vector>
#include "computerRoom.h"

class Student:public Identity
{
public:
	Student();

	Student(int id,string name,string pwd);

	virtual void operMenu();

	void applyOrder();

	void showMyOrder();

	void showAllOrder();

	void cancelOrder();

	int id;

	vector<ComputerRoom> vCom;
};