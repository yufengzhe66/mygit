#pragma once   //����ͷ�ļ����ظ�����
#include<iostream>
using namespace std;
#include "worker.h"
#include<fstream>
#define FILENAME "empFile.txt"


class WorkerManager
{
public:
	WorkerManager();

	void ShowMenu();

	void ExitSystem();

	~WorkerManager();

	void Add_Emp();

	void save();

	int get_EmpNum();

	void init_Emp();

	void show_Emp();

	//�ж�ְ���Ƿ����
	int IsExist(int id);

	void Del_Emp();

	void Mod_Emp();

	void Find_emp();

	void sort_Emp();


	void clean_File();


protected:
	int m_EmpNum;
	//��¼ְ������


	//ְ������ָ��
	Worker** m_EmpArray;

	//��־�ļ��Ƿ�Ϊ��
	bool m_FileIsEmpty;
};
