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
			cout << "����˺�" << endl;
			man->addPerson();
		}

		else if (select == 2) //�鿴�˺�
		{
			cout << "�鿴�˺�" << endl;
			man->showPerson();
		}

		else if (select == 3)
		{
			cout << "�鿴����" << endl;
			man->showComputer();
		}

		else if (select == 4)
		{
			cout << "���ԤԼ" << endl;
			man->cleanFile();
		}

		else
		{
			delete manager;
			cout << "ע���ɹ�" << endl;
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
			delete student;//student�Ǵ�ַ���ã�������Ҫ�ͷ�ԭ������Ϊstudent���ٵĿռ�
			cout << "ע���ɹ�" << endl;
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
			cout << "ע���ɹ�" << endl;
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
			cout << "�ļ�������" << endl;
			ifs.close();
			return;
		}

		int id = 0;
		string name;
		string pwd;

		if (type == 1)	//ѧ����¼
		{
			cout << "���������ѧ��" << endl;
			cin >> id;
		}
		else if (type == 2) //��ʦ��¼
		{
			cout << "���������ְ����" << endl;
			cin >> id;
		}

		cout << "�������û�����" << endl;
		cin >> name;

		cout << "���������룺 " << endl;
		cin >> pwd;


		if (type == 1)
		{

			//ѧ����¼��֤
			int fId;
			string fName;
			string fPwd;

			while (ifs >> fId && ifs >> fName && ifs >> fPwd)
			{
				if (id == fId && name == fName && pwd == fPwd)
				{
					cout << "ѧ����֤��¼�ɹ�!" << endl;
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
			//��ʦ��¼��֤
			int fId;
			string fName;
			string fPwd;

			while (ifs >> fId && ifs >> fName && ifs >> fPwd)
			{
				if (id == fId && name == fName && pwd == fPwd)
				{
					cout << "��ʦ��֤��¼�ɹ�!" << endl;
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
		    //����Ա��¼��֤
			string fName;
			string fPwd;
			while (ifs >> fName && ifs >> fPwd)
			{
				if (name == fName && pwd == fPwd)
				{
					cout << "��֤��¼�ɹ�!" << endl;
					//��¼�ɹ��󣬰�������������Ա����
					system("pause");
					system("cls");
					//��������Ա����
					person = new Manager(name, pwd);
					//�������Ա�Ӳ˵�
					managerMenu(person);
					return;
				}
			}

		}

			cout << "��֤��¼ʧ��!" << endl;

			system("pause");
			system("cls");
			return;		
}



