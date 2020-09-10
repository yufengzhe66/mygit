#include "teacher.h"
#include "orderFile.h"
#include<vector>

//Ĭ�Ϲ���
Teacher::Teacher()
{
}

//�вι��� (ְ����ţ�����������)
Teacher::Teacher(int empId, string name, string pwd)
{
	this->id = empId;
	this->name = name;
	this->password = pwd;
}

//�˵�����
void Teacher::operMenu()
{
	cout << "��ӭ��ʦ��" << this->name << "��¼��" << endl;
	cout << "\t\t ----------------------------------\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          1.�鿴����ԤԼ          |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          2.���ԤԼ              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t|          0.ע����¼              |\n";
	cout << "\t\t|                                  |\n";
	cout << "\t\t ----------------------------------\n";
	cout << "��ѡ�����Ĳ����� " << endl;
}

//�鿴����ԤԼ
void Teacher::showAllOrder()
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

//���ԤԼ
void Teacher::validOrder()
{
	OrderFile of;
	if (of.OrderSize == 0)
	{
		cout << "��ԤԼ��¼" << endl;
		system("pause");
		system("cls");
		return;
	}
	cout << "����˵�ԤԼ��¼���£�" << endl;

	vector<int>v;
	int index = 1;
	for (int i = 0; i < of.OrderSize; i++)
	{
		if (of.OrderData[i]["status"] == "1")
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
			cout << status << endl;
		}
	}
	cout << "��������˵�ԤԼ��¼,0������" << endl;

	int select = 0;
	int ret = 0;
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
				cout << "��������˽��" << endl;
				cout << "1��ͨ��" << endl;
				cout << "2����ͨ��" << endl;
				cin >> ret;

				if (ret == 1)
				{
					of.OrderData[v[select - 1]]["status"] = "2";
				}
				else
				{
					of.OrderData[v[select - 1]]["status"] = "-1";
				}
				of.updateOrder();
				cout << "�����ϣ�" << endl;
				break;
			}
		}
		cout << "������������������" << endl;
	}
	system("pause");
	system("cls");
}