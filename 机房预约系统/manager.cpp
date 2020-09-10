#include<fstream>
using namespace std;
#include<algorithm>
#include "manager.h"
#include "globalFile.h"

//默认构造
Manager::Manager()
{
}

//有参构造
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
	cout << "当前机房数量为： " << this->vCom.size() << endl;

	ifs.close();
}

//选择菜单
void Manager::operMenu()
{
	cout << "欢迎管理员：" << this->name << "登录！" << endl;
	cout << "\t\t ---------------------------------\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          1.添加账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          2.查看账号            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          3.查看机房            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          4.清空预约            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t|          0.注销登录            |\n";
	cout << "\t\t|                                |\n";
	cout << "\t\t ---------------------------------\n";
	cout << "请选择您的操作： " << endl;
}

//添加账号  
void Manager::addPerson()
{
	cout << "请输入添加账号的类型" << endl;
	cout << "1、添加学生" << endl;
	cout << "2、添加老师" << endl;

	string fileName;
	string tip;
	ofstream ofs;

	int choice;
	cin >> choice;
	string errorTip;

	if (choice == 1)
	{
		fileName = STUDENT_FILE;
		tip = "请输入学号：";
		errorTip = "学号重复，请重新输入";
	}

	else if (choice == 2)
	{
		fileName = TEACHER_FILE;
		tip = "请输入工号：";
		errorTip = "职工号重复，请重新输入";
	}
	else
	{
		cout << "输入错误！！！" << endl;
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
	
	cout << "请输入姓名： " << endl;
	cin >> name;

	cout << "请输入密码： " << endl;
	cin >> pwd;

	ofs << id << " " << name << " " << pwd << " " << endl;
	cout <<"添加成功！"<< endl;

	system("pause");
	system("cls");

	ofs.close();

	//初始化容器
	this->initVector();
}


void printStudent(Student& s)
{
	cout << "学号： " << s.id << " 姓名： " << s.name << " 密码：" << s.password << endl;
}


void printTeacher(Teacher& t)
{
	cout << "职工号： " << t.id << " 姓名： " << t.name << " 密码：" << t.password << endl;
}


//查看账号
void Manager::showPerson()
{
	cout << "请选择查看内容：" << endl;
	cout << "1、查看所有学生" << endl;
	cout << "2、查看所有老师" << endl;

	int select;
	cin >> select;
	if (select == 1)
	{
		cout<< "所有学生信息如下： " << endl;
		for_each(this->vStu.begin(), this->vStu.end(), printStudent);
	}

	else if(select == 2)
	{
		cout << "所有老师信息如下： " << endl;
		for_each(this->vTea.begin(), this->vTea.end(), printTeacher);
	}


	system("pause");
	system("cls");
}

//查看机房信息
void Manager::showComputer()
{
	cout << "机房信息如下： " << endl;
	for (vector<ComputerRoom>::iterator it = this->vCom.begin(); it != this->vCom.end(); it++)
	{
		cout << "机房编号：" << it->id << "   机房最大容量：" << it->maxNum << endl;
	}
	system("pause");
	system("cls");
}

//清空预约记录
void Manager::cleanFile()
{
	ofstream ofs(ORDER_FILE, ios::trunc);
	ofs.close();

	cout<< "清空成功！" << endl;
	system("pause");
	system("cls");
}

void Manager::initVector()
{
	ifstream ifs;
	ifs.open(STUDENT_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "学生文件读取失败！" << endl;
		return;
	}
	vStu.clear();
	vTea.clear();

	Student s;
	while (ifs >> s.id && ifs >> s.name && ifs >> s.password)
	{
		vStu.push_back(s);
	}
	cout << "当前学生数量为： " << vStu.size() << endl;
	ifs.close(); //学生初始化

	ifs.open(TEACHER_FILE, ios::in);
	if (!ifs.is_open())
	{
		cout << "教师文件读取失败！" << endl;
		return;
	}

	Teacher t;
	while (ifs >> t.id && ifs >> t.name && ifs >> t.password)
	{
		vTea.push_back(t);
	}

	cout << "当前教师数量为： " << vTea.size() << endl;
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