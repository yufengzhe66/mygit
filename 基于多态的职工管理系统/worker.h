#pragma once
#include<iostream>
using namespace std;
#include<string>

//创建一个抽象职工类
class Worker
{
public:
	virtual void showInfo() = 0;
	virtual string getDeptName() = 0;

	int m_Id;
	string m_Name;
	int m_DeptId;
};