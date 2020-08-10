#include "workerManager.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"



WorkerManager::WorkerManager()
{
	//初始化完相应的属性
	/*
	this->m_EmpNum = 0;
	this->m_EmpArray = NULL;
	*/

	//载入文件
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//文件不存在
	if (!ifs.is_open())
	{
		cout << "文件不存在！" << endl;
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//文件存在且为空
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空！" << endl;
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//文件存在且不为空
	int num = this->get_EmpNum();
	cout << "职工人数为：" << num << endl;
	this->m_EmpNum = num;
	this->m_EmpArray = new Worker *[this->m_EmpNum];
	this->m_FileIsEmpty = false;
	this->init_Emp();
}

WorkerManager::~WorkerManager()
{
	if (this->m_EmpArray != NULL)
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			if (this->m_EmpArray[i])
			{
				delete this->m_EmpArray[i];
				this->m_EmpArray[i] = NULL;
			}
		}
		delete[] this->m_EmpArray;
		this->m_EmpArray = NULL;
	}
}


void WorkerManager::ShowMenu()
{
	cout << "********************************************" << endl;
	cout << "*********  欢迎使用职工管理系统！ **********" << endl;
	cout << "*************  0.退出管理程序  *************" << endl;
	cout << "*************  1.增加职工信息  *************" << endl;
	cout << "*************  2.显示职工信息  *************" << endl;
	cout << "*************  3.删除离职职工  *************" << endl;
	cout << "*************  4.修改职工信息  *************" << endl;
	cout << "*************  5.查找职工信息  *************" << endl;
	cout << "*************  6.按照编号排序  *************" << endl;
	cout << "*************  7.清空所有文档  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}



void WorkerManager::ExitSystem()
{
	cout << "欢迎下次使用！" << endl;
	system("pause");
	exit(0);
}



void WorkerManager::Add_Emp()
{
	int id;
	string name;
	int dSelect;
	cout << "请输入新增职工人数" << endl;
	int addNum;
	cin >> addNum;
	if (addNum > 0)
	{
		//开辟新的空间
		Worker** newSpace = new Worker * [this->m_EmpNum + addNum];
		//原来的顺序输入新的空间
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				//等号运算符不需要重载吗？？？？（目前均无无属性，赋值操作实质上是指针赋值）
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//将新增的员工信息进行输入
		for (int i = 0; i < addNum; i++)
		{
			cout << "请输入第 " << i + 1 << " 个新职工编号：" << endl;
			cin >> id;


			cout << "请输入第 " << i + 1 << " 个新职工姓名：" << endl;
			cin >> name;


			cout << "请选择该职工的岗位：" << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> dSelect;
			Worker* worker = NULL;
			switch (dSelect)
			{
			case 1:
				worker = new Employee(id,name,1);
				break;
			case 2:
				worker = new Manager(id, name, 2);
				break;
			case 3:
				worker = new Boss(id, name, 3);
				break;
			default:
				break;
			}
			newSpace[this->m_EmpNum + i] = worker;
		}
		//更新指针和数量
		this->m_EmpNum = this->m_EmpNum + addNum;
		delete[] this->m_EmpArray;
		this->m_EmpArray = newSpace;
		this->m_FileIsEmpty = false;
		//提示信息
		cout << "成功添加" << addNum << "名新职工！" << endl;
		this->save();
	}
	else 
	{
		cout << "输入有误" << endl;
	}
	system("pause");
	system("cls");

}



void WorkerManager::save()
{
	ofstream ofs;
	ofs.open(FILENAME,ios::out);

	for (int i = 0; i < this->m_EmpNum; i++)
	{
		ofs << this->m_EmpArray[i]->m_Id << " "
			<< this->m_EmpArray[i]->m_Name << " "
			<< this->m_EmpArray[i]->m_DeptId << endl;
	}
	ofs.close();
}


int WorkerManager::get_EmpNum()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	int id;
	string name;
	int dId;
	int num = 0;
	while (ifs>>id && ifs>>name && ifs>>dId)
	{
		num++;
	}
	return num;
}



void WorkerManager::init_Emp()
{
	ifstream ifs;
	ifs.open(FILENAME, ios::in);

	int id;
	string name;
	int dId;

	int index = 0;
	Worker* worker = NULL;
	while (ifs >> id && ifs >> name && ifs >> dId)
	{
		switch (dId)
		{
		case 1:
			worker = new Employee(id, name, 1);
			break;
		case 2:
			worker = new Manager(id, name, 2);
			break;
		case 3:
			worker = new Boss(id, name, 3);
			break;
		default:
			break;
		}

		//m_m_EmpArray是一个指针数组，（指向指针的指针）
		this->m_EmpArray[index] = worker;
		index++;
	}

}

void WorkerManager::show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else 
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//利用多态调用接口
			this->m_EmpArray[i]->showInfo();
		}

	}

	system("pause");
	system("cls");

}


int WorkerManager::IsExist(int id)
{
	int sign = -1;
	for (int i = 0; i < this->m_EmpNum; i++)
	{
		if (id == this->m_EmpArray[i]->m_Id)
		{
			sign = i;
			break;
		}
	}
	return sign;

}


void WorkerManager::Del_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入要删除的职工编号：" << endl;
		int id;
		cin >> id;
		int index = this->IsExist(id);
		if (index == -1)
		{
			cout << "该职工不存在!!!" << endl;
		}
		else
		{
			for (int i = index+1; i < this->m_EmpNum; i++)
			{
				this->m_EmpArray[i - 1] = this->m_EmpArray[i];
			}
			this->m_EmpNum--;
			this->save();
			cout << "删除成功" << endl;
		}
	}
	system("pause");
	system("cls");
}





void WorkerManager::Mod_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入要修改的职工编号：" << endl;
		int id;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1)
		{
			cout << "当前职工信息为：" << endl;
			this->m_EmpArray[index]->showInfo();
			delete this->m_EmpArray[index];

			int newId;
			string newName;
			int newdSelect;

			cout << "请输入新职工号： " << endl;
			cin >> newId;

			cout << "请输入新姓名： " << endl;
			cin >> newName;

			cout << "请输入岗位： " << endl;
			cout << "1、普通职工" << endl;
			cout << "2、经理" << endl;
			cout << "3、老板" << endl;
			cin >> newdSelect;

			Worker* worker = NULL;
			switch (newdSelect)
			{
			case 1:
				worker = new Employee(newId, newName, newdSelect);
				break;
			case 2:
				worker = new Manager(newId, newName, newdSelect);
				break;
			case 3:
				worker = new Boss(newId, newName, newdSelect);
				break;
			default:
				break;
			}

			this->m_EmpArray[index] = worker;
			this->save();
		}
		else
		{
			cout << "该职工不存在!!!" << endl;
		}
	}
	system("pause");
	system("cls");

}



void WorkerManager::Find_emp()
{
	if (m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
	}
	else
	{
		cout << "请输入查找的方式：" << endl;
		cout << "1、按职工编号查找" << endl;
		cout << "2、按姓名查找" << endl;
		int select;
		cin >> select;
		if (select == 1) 
		{
			int id;
			cout << "请输入查找的职工编号：" << endl;
			cin >> id;
			int index = this->IsExist(id);
			if (index != -1)
			{
				cout << "查找成功！该职工信息如下：" << endl;
				this->m_EmpArray[index]->showInfo();
			}
			else{ cout << "该职工不存在!!!" << endl; }
		}
		else if(select == 2)
		{
			string name;
			cout << "请输入查找的姓名：" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "查找成功,职工的信息如下：" << endl;
					flag = true;
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (!flag)
			{
				cout << "查找失败，查无此人" << endl;
			}
		}
		else{ cout << "输入选项有误" << endl; }
	}

	system("pause");
	system("cls");
}



void WorkerManager::sort_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "文件不存在或记录为空！" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "请选择排序方式： " << endl;
		cout << "1、按职工号进行升序" << endl;
		cout << "2、按职工号进行降序" << endl;

		int select = 0;
		cin >> select;

		Worker* temp;
		if (select == 1) 
		{
			int minIndex;
			for(int i=0; i<this->m_EmpNum; i++)
			{
				minIndex = i;
				for (int j = i; j < this->m_EmpNum; j++)
				{
					if (this->m_EmpArray[i]->m_Id > this->m_EmpArray[j]->m_Id)
					{
						minIndex = j;
					}
				}
				if (i != minIndex) 
				{
					temp = this->m_EmpArray[i];
					this->m_EmpArray[i] = this->m_EmpArray[minIndex];
					this->m_EmpArray[minIndex] = temp;
				}
			}

			this->save();
			cout << "排序成功,排序后结果为：" << endl;
			this->show_Emp();
		}
		else if(select == 2) 
		{
			int maxIndex;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				maxIndex = i;
				for (int j = i; j < this->m_EmpNum; j++)
				{
					if (this->m_EmpArray[i]->m_Id < this->m_EmpArray[j]->m_Id)
					{
						maxIndex = j;
					}
				}
				if (i != maxIndex)
				{
					temp = this->m_EmpArray[i];
					this->m_EmpArray[i] = this->m_EmpArray[maxIndex];
					this->m_EmpArray[maxIndex] = temp;
				}
			}

			this->save();
			cout << "排序成功,排序后结果为：" << endl;
			this->show_Emp();
		}
		else
		{
			cout << "输入选项有误" << endl;
		}
	}
}

void WorkerManager::clean_File()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	cout << "请选择：" << endl;
	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//打开模式truc，如果存在文件，删除并重新创建
		ofstream ofs(FILENAME,ios::trunc);
		ofs.close();

		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i])
				{
					delete this->m_EmpArray[i];
					this->m_EmpArray[i] = NULL;
				}
			}
			delete[] this->m_EmpArray;
			this->m_EmpArray = NULL;
			this->m_EmpNum = 0;
			this->m_FileIsEmpty = true;
		}
		cout << "清空成功！" << endl;
	}
	else if(select == 2)
	{
		
	}
	else
	{
		cout << "输入选项有误" << endl;
	}
	system("pause");
	system("cls");
}