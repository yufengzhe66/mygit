#pragma once
#include "identity.h"
#include "Student.h"
#include "teacher.h"
#include "computerRoom.h"
#include<vector>

class Manager :public Identity
{
public:

	//Ĭ�Ϲ���
	Manager();

	//�вι���  ����Ա����������
	Manager(string name, string pwd);

	//ѡ��˵�
	virtual void operMenu();

	//����˺�  
	void addPerson();

	//�鿴�˺�
	void showPerson();

	//�鿴������Ϣ
	void showComputer();

	//���ԤԼ��¼
	void cleanFile();

	void initVector();

	//����ظ� 
	bool checkRepeat(int id, int type);

	vector<Student> vStu;

	vector<Teacher> vTea;

	vector<ComputerRoom> vCom;

};