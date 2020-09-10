#pragma once
#include <string>
using namespace std;
#include <fstream>
#include "Identity.h"
#include "Student.h"
#include "teacher.h"
#include "manager.h"


void managerMenu(Identity*& manager)
{
	while (true)
	{
		manager->operMenu();
		Manager* man = (Manager*)manager;

		int select;
		cin >> select;

		if (select == 1)
		{
			cout << "添加账号" << endl;
			man->addPerson();
		}

		else if (select == 2) //查看账号
		{
			cout << "查看账号" << endl;
			man->showPerson();
		}

		else if (select == 3)
		{
			cout << "查看机房" << endl;
			man->showComputer();
		}

		else if (select == 4)
		{
			cout << "清空预约" << endl;
			man->cleanFile();
		}

		else
		{
			delete manager;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


void studentMenu(Identity*& student)
{
	while (true)
	{
		student->operMenu();

		Student* stu = (Student*)student;
		int select;
		cin >> select;

		if (select == 1)
		{
			stu->applyOrder();
		}
		else if (select == 2)
		{
			stu->showMyOrder();
		}
		else if (select == 3)
		{
			stu->showAllOrder();
		}
		else if (select == 4)
		{
			stu->cancelOrder();
		}
		else
		{
			delete student;//student是传址调用，现在需要释放原来函数为student开辟的空间
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


void TeacherMenu(Identity*& teacher)
{
	while (true)
	{
		teacher->operMenu();
		Teacher* tea = (Teacher*)teacher;
		int select = 0;

		cin >> select;

		if (select == 1)
		{
			tea->showAllOrder();
		}
		else if (select == 2)
		{
			tea->validOrder();
		}
		else
		{
			delete teacher;
			cout << "注销成功" << endl;
			system("pause");
			system("cls");
			return;
		}
	}
}


void LoginIn(string fileName, int type)
{
		Identity* person = NULL;

		ifstream ifs;
		ifs.open(fileName, ios::in);

		if (!ifs.is_open())
		{
			cout << "文件不存在" << endl;
			ifs.close();
			return;
		}

		int id = 0;
		string name;
		string pwd;

		if (type == 1)	//学生登录
		{
			cout << "请输入你的学号" << endl;
			cin >> id;
		}
		else if (type == 2) //教师登录
		{
			cout << "请输入你的职工号" << endl;
			cin >> id;
		}

		cout << "请输入用户名：" << endl;
		cin >> name;

		cout << "请输入密码： " << endl;
		cin >> pwd;


		if (type == 1)
		{

			//学生登录验证
			int fId;
			string fName;
			string fPwd;

			while (ifs >> fId && ifs >> fName && ifs >> fPwd)
			{
				if (id == fId && name == fName && pwd == fPwd)
				{
					cout << "学生验证登录成功!" << endl;
					system("pause");
					system("cls");
					person = new Student(id, name, pwd);
					studentMenu(person);
					return;
				}
			}

		}
		else if (type == 2)
		{
			//教师登录验证
			int fId;
			string fName;
			string fPwd;

			while (ifs >> fId && ifs >> fName && ifs >> fPwd)
			{
				if (id == fId && name == fName && pwd == fPwd)
				{
					cout << "教师验证登录成功!" << endl;
					system("pause");
					system("cls");
					person = new Teacher(id, name, pwd);
					TeacherMenu(person);
					return;
				}
			}
		}
		else if (type == 3)
		{
		    //管理员登录验证
			string fName;
			string fPwd;
			while (ifs >> fName && ifs >> fPwd)
			{
				if (name == fName && pwd == fPwd)
				{
					cout << "验证登录成功!" << endl;
					//登录成功后，按任意键进入管理员界面
					system("pause");
					system("cls");
					//创建管理员对象
					person = new Manager(name, pwd);
					//进入管理员子菜单
					managerMenu(person);
					return;
				}
			}

		}

			cout << "验证登录失败!" << endl;

			system("pause");
			system("cls");
			return;		
}



