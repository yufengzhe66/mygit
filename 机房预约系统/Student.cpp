#include "Student.h"
using namespace std;
#include "globalFile.h"
#include "orderFile.h"
#include<fstream>

//Ĭ�Ϲ���
Student::Student()
{
}

//�вι���(ѧ�š�����������)
Student::Student(int id, string name, string pwd)
{
	//��ʼ������
	this->id = id;
	this->name = name;
	this->password = pwd;

	ifstream ifs;
	ifs.open(COMPUTER_FILE, ios::in);

	ComputerRoom c;
	while (ifs >> c.id && ifs >> c.maxNum)
	{
		this->vCom.push_back(c);
	}

	ifs.close();
}

//�˵�����
void Student::operMenu()
{
	cout << "��ӭѧ������" << this->name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          1.����ԤԼ              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          2.�鿴�ҵ�ԤԼ          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          3.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          4.ȡ��ԤԼ              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                 |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

//����ԤԼ
void Student::applyOrder()
{
	cout << "��������ʱ��Ϊ��һ�����壡" << endl;
	cout << "����������ԤԼ��ʱ�䣺" << endl;
	cout << "1����һ" << endl;
	cout << "2���ܶ�" << endl;
	cout << "3������" << endl;
	cout << "4������" << endl;
	cout << "5������" << endl;

	int date = 0;
	int interval = 0;
	int room;

	while (true)
	{
		cin >> date;
		if (date >= 1 && date <= 5)
		{
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "����������ԤԼ��ʱ��Σ�" << endl;
	cout << "1������" << endl;
	cout << "2������" << endl;

	while (true)
	{
		cin >> interval;
		if (interval >= 1 && interval <= 2)
		{
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "��ѡ�������" << endl;
	cout << "1�Ż���������" << vCom[0].maxNum << endl;
	cout << "2�Ż���������" << vCom[1].maxNum << endl;
	cout << "3�Ż���������" << vCom[2].maxNum << endl;

	while (true)
	{
		cin >> room;
		if (room >= 1 && room <= 3)
		{
			break;
		}
		cout << "������������������" << endl;
	}

	cout << "ԤԼ�ɹ��������" << endl;

	ofstream ofs(ORDER_FILE, ios::app);
	ofs << "date:" << date << " ";
	ofs << "interval:" << interval << " ";
	ofs << "stuId:" << this->id << " ";
	ofs << "stuName:" << this->name << " ";
	ofs << "roomId:" << room << " ";
	ofs << "status:" << 1 << endl;

	ofs.close();

	system("pause");
	system("cls");
}

//�鿴�ҵ�ԤԼ
void Student::showMyOrder()
{
	OrderFile of;
	if (of.OrderSize == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}

	for (int i = 0; i < of.OrderSize; i++)
	{
		if (atoi(of.OrderData[i]["stuId"].c_str()) == this->id)
		{
			cout << "ԤԼ���ڣ� ��" << of.OrderData[i]["date"];
			cout << " ʱ�Σ�"<<(of.OrderData[i]["interval"]=="1"? "����":"����" );
			cout << " ������" << of.OrderData[i]["roomId"];
			string status = " ״̬�� ";  // 0 ȡ����ԤԼ   1 �����   2 ��ԤԼ -1 ԤԼʧ��

			if (of.OrderData[i]["status"] == "1")
			{
				status += "�����";
			}
			else if (of.OrderData[i]["status"] == "2")
			{
				status += "ԤԼ�ɹ�";
			}
			else if (of.OrderData[i]["status"] == "-1")
			{
				status += "���δͨ����ԤԼʧ��";
			}
			else
			{
				status += "ԤԼ��ȡ��";
			}
			cout << status << endl;
		}
	}
	system("pause");
	system("cls");
}

//�鿴����ԤԼ
void Student::showAllOrder()
{
	OrderFile of;
	if (of.OrderSize == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	for (int i = 0; i < of.OrderSize; i++)
	{
		cout << i + 1 << ": ";
		cout << "ԤԼ���ڣ� ��" << of.OrderData[i]["date"];
		cout << " ʱ�Σ�" << (of.OrderData[i]["interval"] == "1" ? "����" : "����");
		cout << " ѧ�ţ�" << of.OrderData[i]["stuId"];
		cout << " ������" << of.OrderData[i]["stuName"];
		cout << " ������" << of.OrderData[i]["roomId"];
		string status = " ״̬�� ";  // 0 ȡ����ԤԼ   1 �����   2 ��ԤԼ -1 ԤԼʧ��

		if (of.OrderData[i]["status"] == "1")
		{
			status += "�����";
		}
		else if (of.OrderData[i]["status"] == "2")
		{
			status += "ԤԼ�ɹ�";
		}
		else if (of.OrderData[i]["status"] == "-1")
		{
			status += "���δͨ����ԤԼʧ��";
		}
		else
		{
			status += "ԤԼ��ȡ��";
		}
		cout << status << endl;

	}
	system("pause");
	system("cls");
	
}

//ȡ��ԤԼ
void Student::cancelOrder()
{
	OrderFile of;
	if (of.OrderSize == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����л�ԤԼ�ɹ��ļ�¼����ȡ����������ȡ���ļ�¼" << endl;

	vector<int>v;
	int index = 1;
	for (int i = 0; i < of.OrderSize; i++)
	{
		if (atoi(of.OrderData[i]["stuId"].c_str()) == this->id)
		{
			if (of.OrderData[i]["status"] == "1" || of.OrderData[i]["status"] == "2")
			{
				v.push_back(i);
				cout << index++ << ":";
				cout << "ԤԼ���ڣ� ��" << of.OrderData[i]["date"];
				cout << " ʱ�Σ�" << (of.OrderData[i]["interval"] == "1" ? "����" : "����");
				cout << " ������" << of.OrderData[i]["roomId"];
				string status = " ״̬�� ";  // 0 ȡ����ԤԼ   1 �����   2 ��ԤԼ -1 ԤԼʧ��

				if (of.OrderData[i]["status"] == "1")
				{
					status += "�����";
				}
				else if (of.OrderData[i]["status"] == "2")
				{
					status += "ԤԼ�ɹ�";
				}
				cout << status << endl;
			}
		}
	}

	cout << "������ȡ���ļ�¼,0������" << endl;
	int select = 0;
	while (true)
	{
		cin >> select;
		if (select >= 0 && select <= v.size())
		{
			if(select==0)
			{
				break;
			}
			else
			{
				of.OrderData[v[select - 1]]["status"] = "0";
				of.updateOrder();
				cout << "��ȡ��ԤԼ" << endl;
				break;
			}
		}
		cout << "������������������" << endl;
	}
	system("pause");
	system("cls");
}