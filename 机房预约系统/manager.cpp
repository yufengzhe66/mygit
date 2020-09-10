#include<fstream>
using namespace std;
#include<algorithm>
#include "manager.h"
#include "globalFile.h"

//Ĭ�Ϲ���
Manager::Manager()
{
}

//�вι���
Manager::Manager(string name, string pwd)
{
	this->name = name;
	this->password = pwd;
	this->initVector();


	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom c;
	while (ifs >> c.id && ifs >> c.maxNum)
	{
		this->vCom.push_back(c);
	}
	cout << "��ǰ��������Ϊ�� " << this->vCom.size() << endl;

	ifs.close();
}

//ѡ��˵�
void Manager::operMenu()
{
	cout << "��ӭ����Ա��" << this->name << "��¼��" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.����˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.�鿴�˺�            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.�鿴����            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.���ԤԼ            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.ע����¼            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

//����˺�  
void Manager::addPerson()
{
	cout << "����������˺ŵ�����" << endl;
	cout << "1�����ѧ��" << endl;
	cout << "2�������ʦ" << endl;

	string fileName;
	string tip;
	ofstream ofs;

	int choice;
	cin >> choice;
	string errorTip;

	if (choice == 1)
	{
		fileName = STUDENT_FILE;
		tip = "������ѧ�ţ�";
		errorTip = "ѧ���ظ�������������";
	}

	else if (choice == 2)
	{
		fileName = TEACHER_FILE;
		tip = "�����빤�ţ�";
		errorTip = "ְ�����ظ�������������";
	}
	else
	{
		cout << "������󣡣���" << endl;
		return;
	}

	ofs.open(fileName, ios::out | ios::app);
	int id;
	string name;
	string pwd;

	cout << tip << endl;

	while (true)
	{
		cin >> id;

		bool ret = this->checkRepeat(id, choice);

		if (ret)
		{
			cout << errorTip << endl;
		}
		else
		{
			break;
		}
	}
	
	cout << "������������ " << endl;
	cin >> name;

	cout << "���������룺 " << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout <<"��ӳɹ���"<< endl;

	system("pause");
	system("cls");

	ofs.close();

	//��ʼ������
	this->initVector();
}


void printStudent(Student& s)
{
	cout << "ѧ�ţ� " << s.id << " ������ " << s.name << " ���룺" << s.password << endl;
}


void printTeacher(Teacher& t)
{
	cout << "ְ���ţ� " << t.id << " ������ " << t.name << " ���룺" << t.password << endl;
}


//�鿴�˺�
void Manager::showPerson()
{
	cout << "��ѡ��鿴���ݣ�" << endl;
	cout << "1���鿴����ѧ��" << endl;
	cout << "2���鿴������ʦ" << endl;

	int select;
	cin >> select;
	if (select == 1)
	{
		cout<< "����ѧ����Ϣ���£� " << endl;
		for_each(this->vStu.begin(), this->vStu.end(), printStudent);
	}

	else if(select == 2)
	{
		cout << "������ʦ��Ϣ���£� " << endl;
		for_each(this->vTea.begin(), this->vTea.end(), printTeacher);
	}


	system("pause");
	system("cls");
}

//�鿴������Ϣ
void Manager::showComputer()
{
	cout << "������Ϣ���£� " << endl;
	for (vector<ComputerRoom>::iterator it = this->vCom.begin(); it != this->vCom.end(); it++)
	{
		cout << "������ţ�" << it->id << "   �������������" << it->maxNum << endl;
	}
	system("pause");
	system("cls");
}

//���ԤԼ��¼
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout<< "��ճɹ���" << endl;
	system("pause");
	system("cls");
}

void Manager::initVector()
{
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "ѧ���ļ���ȡʧ�ܣ�" << endl;
		return;
	}
	vStu.clear();
	vTea.clear();

	Student s;
	while (ifs >> s.id && ifs >> s.name && ifs >> s.password)
	{
		vStu.push_back(s);
	}
	cout << "��ǰѧ������Ϊ�� " << vStu.size() << endl;
	ifs.close(); //ѧ����ʼ��

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "��ʦ�ļ���ȡʧ�ܣ�" << endl;
		return;
	}

	Teacher t;
	while (ifs >> t.id && ifs >> t.name && ifs >> t.password)
	{
		vTea.push_back(t);
	}

	cout << "��ǰ��ʦ����Ϊ�� " << vTea.size() << endl;
	ifs.close();	

}


bool Manager::checkRepeat(int id, int type)
{
	if (type == 1)
	{
		for (vector<Student>::iterator it = this->vStu.begin(); it != this->vStu.end(); it++)
		{
			if (it->id == id)
			{
				return true;
			}
		}
	}

	else if(type==2)
	{
		for (vector<Teacher>::iterator it = this->vTea.begin(); it != this->vTea.end(); it++)
		{
			if (it->id == id)
			{
				return true;
			}
		}
	}
	return false;
}