#include "workerManager.h"
#include "employee.h"
#include "manager.h"
#include "boss.h"
int main()
{
	/*
	Worker* worker = NULL;
	worker=new Employee(1,"����",1);
	worker->showInfo();
	delete worker;



	worker = new Manager(2, "����", 2);
	worker->showInfo();
	delete worker;

	worker = new Boss(3, "����", 3);
	worker->showInfo();
	delete worker;
	*/

	WorkerManager wm;
	int choice = 0;
	while (true)
	{
		wm.ShowMenu();
		cout << "����������ѡ��" << endl;
		cin >> choice;

		switch (choice)
		{
		case 0: wm.ExitSystem();//�˳�ϵͳ
			break;
		case 1: //���ְ��
			wm.Add_Emp();
			break;
		case 2: //��ʾְ��
			wm.show_Emp();
			break;
		case 3: //ɾ��ְ��
			wm.Del_Emp();
			break;
		case 4: //�޸�ְ��
			wm.Mod_Emp();
			break;
		case 5: //����ְ��
			wm.Find_emp();
			break;
		case 6: //����ְ��
			wm.sort_Emp();
			break;
		case 7: //����ļ�
			wm.clean_File();
			break;
		default:
			system("cls");
			break;
		}
	}
	system("pause");
	return 0;
}