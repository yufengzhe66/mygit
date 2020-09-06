#include "speechManager.h"
#include<ctime>

int main()
{
	SpeechManager sm;
	int choice;

	srand((unsigned int)time(NULL));

	while (true)
	{
		sm.showMenu();
		cout << "����������ѡ�� " << endl;
		cin >> choice; // �����û���ѡ��

		switch (choice)
		{
		case 1:  //��ʼ����
			sm.startSpeech();
			break;
		case 2:  //�鿴��¼
			sm.showRecord();
			break;
		case 3:  //��ռ�¼
			sm.clearRecord();
			break;
		case 0:  //�˳�ϵͳ
			sm.exitSystem();
			break;
		default:
			system("cls");//����
			break;
		}
	}
	system("pause");
	return 0;
}