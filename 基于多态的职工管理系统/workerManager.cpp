#include "workerManager.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"



WorkerManager::WorkerManager()
{
	//��ʼ������Ӧ������
	/*
	this->m_EmpNum = 0;
	this->m_EmpArray = NULL;
	*/

	//�����ļ�
	ifstream ifs;
	ifs.open(FILENAME, ios::in);
	//�ļ�������
	if (!ifs.is_open())
	{
		cout << "�ļ������ڣ�" << endl;
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}
	//�ļ�������Ϊ��
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ�գ�" << endl;
		this->m_EmpArray = NULL;
		this->m_EmpNum = 0;
		this->m_FileIsEmpty = true;
		ifs.close();
		return;
	}

	//�ļ������Ҳ�Ϊ��
	int num = this->get_EmpNum();
	cout << "ְ������Ϊ��" << num << endl;
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
	cout << "*********  ��ӭʹ��ְ������ϵͳ�� **********" << endl;
	cout << "*************  0.�˳��������  *************" << endl;
	cout << "*************  1.����ְ����Ϣ  *************" << endl;
	cout << "*************  2.��ʾְ����Ϣ  *************" << endl;
	cout << "*************  3.ɾ����ְְ��  *************" << endl;
	cout << "*************  4.�޸�ְ����Ϣ  *************" << endl;
	cout << "*************  5.����ְ����Ϣ  *************" << endl;
	cout << "*************  6.���ձ������  *************" << endl;
	cout << "*************  7.��������ĵ�  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}



void WorkerManager::ExitSystem()
{
	cout << "��ӭ�´�ʹ�ã�" << endl;
	system("pause");
	exit(0);
}



void WorkerManager::Add_Emp()
{
	int id;
	string name;
	int dSelect;
	cout << "����������ְ������" << endl;
	int addNum;
	cin >> addNum;
	if (addNum > 0)
	{
		//�����µĿռ�
		Worker** newSpace = new Worker * [this->m_EmpNum + addNum];
		//ԭ����˳�������µĿռ�
		if (this->m_EmpArray != NULL)
		{
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				//�Ⱥ����������Ҫ�����𣿣�������Ŀǰ���������ԣ���ֵ����ʵ������ָ�븳ֵ��
				newSpace[i] = this->m_EmpArray[i];
			}
		}
		//��������Ա����Ϣ��������
		for (int i = 0; i < addNum; i++)
		{
			cout << "������� " << i + 1 << " ����ְ����ţ�" << endl;
			cin >> id;


			cout << "������� " << i + 1 << " ����ְ��������" << endl;
			cin >> name;


			cout << "��ѡ���ְ���ĸ�λ��" << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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
		//����ָ�������
		this->m_EmpNum = this->m_EmpNum + addNum;
		delete[] this->m_EmpArray;
		this->m_EmpArray = newSpace;
		this->m_FileIsEmpty = false;
		//��ʾ��Ϣ
		cout << "�ɹ����" << addNum << "����ְ����" << endl;
		this->save();
	}
	else 
	{
		cout << "��������" << endl;
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

		//m_m_EmpArray��һ��ָ�����飬��ָ��ָ���ָ�룩
		this->m_EmpArray[index] = worker;
		index++;
	}

}

void WorkerManager::show_Emp()
{
	if (this->m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else 
	{
		for (int i = 0; i < this->m_EmpNum; i++)
		{
			//���ö�̬���ýӿ�
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
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "������Ҫɾ����ְ����ţ�" << endl;
		int id;
		cin >> id;
		int index = this->IsExist(id);
		if (index == -1)
		{
			cout << "��ְ��������!!!" << endl;
		}
		else
		{
			for (int i = index+1; i < this->m_EmpNum; i++)
			{
				this->m_EmpArray[i - 1] = this->m_EmpArray[i];
			}
			this->m_EmpNum--;
			this->save();
			cout << "ɾ���ɹ�" << endl;
		}
	}
	system("pause");
	system("cls");
}





void WorkerManager::Mod_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "������Ҫ�޸ĵ�ְ����ţ�" << endl;
		int id;
		cin >> id;
		int index = this->IsExist(id);
		if (index != -1)
		{
			cout << "��ǰְ����ϢΪ��" << endl;
			this->m_EmpArray[index]->showInfo();
			delete this->m_EmpArray[index];

			int newId;
			string newName;
			int newdSelect;

			cout << "��������ְ���ţ� " << endl;
			cin >> newId;

			cout << "�������������� " << endl;
			cin >> newName;

			cout << "�������λ�� " << endl;
			cout << "1����ְͨ��" << endl;
			cout << "2������" << endl;
			cout << "3���ϰ�" << endl;
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
			cout << "��ְ��������!!!" << endl;
		}
	}
	system("pause");
	system("cls");

}



void WorkerManager::Find_emp()
{
	if (m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
	}
	else
	{
		cout << "��������ҵķ�ʽ��" << endl;
		cout << "1����ְ����Ų���" << endl;
		cout << "2������������" << endl;
		int select;
		cin >> select;
		if (select == 1) 
		{
			int id;
			cout << "��������ҵ�ְ����ţ�" << endl;
			cin >> id;
			int index = this->IsExist(id);
			if (index != -1)
			{
				cout << "���ҳɹ�����ְ����Ϣ���£�" << endl;
				this->m_EmpArray[index]->showInfo();
			}
			else{ cout << "��ְ��������!!!" << endl; }
		}
		else if(select == 2)
		{
			string name;
			cout << "��������ҵ�������" << endl;
			cin >> name;
			bool flag = false;
			for (int i = 0; i < this->m_EmpNum; i++)
			{
				if (this->m_EmpArray[i]->m_Name == name)
				{
					cout << "���ҳɹ�,ְ������Ϣ���£�" << endl;
					flag = true;
					this->m_EmpArray[i]->showInfo();
				}
			}
			if (!flag)
			{
				cout << "����ʧ�ܣ����޴���" << endl;
			}
		}
		else{ cout << "����ѡ������" << endl; }
	}

	system("pause");
	system("cls");
}



void WorkerManager::sort_Emp()
{
	if (m_FileIsEmpty)
	{
		cout << "�ļ������ڻ��¼Ϊ�գ�" << endl;
		system("pause");
		system("cls");
	}
	else
	{
		cout << "��ѡ������ʽ�� " << endl;
		cout << "1����ְ���Ž�������" << endl;
		cout << "2����ְ���Ž��н���" << endl;

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
			cout << "����ɹ�,�������Ϊ��" << endl;
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
			cout << "����ɹ�,�������Ϊ��" << endl;
			this->show_Emp();
		}
		else
		{
			cout << "����ѡ������" << endl;
		}
	}
}

void WorkerManager::clean_File()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	cout << "��ѡ��" << endl;
	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//��ģʽtruc����������ļ���ɾ�������´���
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
		cout << "��ճɹ���" << endl;
	}
	else if(select == 2)
	{
		
	}
	else
	{
		cout << "����ѡ������" << endl;
	}
	system("pause");
	system("cls");
}