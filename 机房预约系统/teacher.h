#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include "Identity.h"

class Teacher :public Identity
{
public:
	//Ĭ�Ϲ���
	Teacher();

	//�вι��� (ְ����ţ�����������)
	Teacher(int empId, string name, string pwd);

	//�˵�����
	virtual void operMenu();

	//�鿴����ԤԼ
	void showAllOrder();

	//���ԤԼ
	void validOrder();

	int id; //��ʦ���
};