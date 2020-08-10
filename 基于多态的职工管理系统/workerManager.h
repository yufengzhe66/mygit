#pragma once   //避免头文件被重复包含
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

	//判断职工是否存在
	int IsExist(int id);

	void Del_Emp();

	void Mod_Emp();

	void Find_emp();

	void sort_Emp();


	void clean_File();


protected:
	int m_EmpNum;
	//记录职工人数


	//职工数组指针
	Worker** m_EmpArray;

	//标志文件是否为空
	bool m_FileIsEmpty;
};
