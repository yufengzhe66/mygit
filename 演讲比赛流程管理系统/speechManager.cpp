#include<algorithm>
#include "speechManager.h"
#include<string>
#include<deque>
#include<numeric>
#include<functional>
#include<cmath>
#include<fstream>


SpeechManager::SpeechManager()
{
	this->initSpeech();
	this->createSpeaker();
	this->loadRecord();
}


SpeechManager::~SpeechManager()
{

}


void SpeechManager::showMenu()
{
	cout << "********************************************" << endl;
	cout << "*************  ��ӭ�μ��ݽ����� ************" << endl;
	cout << "*************  1.��ʼ�ݽ�����  *************" << endl;
	cout << "*************  2.�鿴�����¼  *************" << endl;
	cout << "*************  3.��ձ�����¼  *************" << endl;
	cout << "*************  0.�˳���������  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}


void SpeechManager::exitSystem()
{
	cout << "��ӭ�´�ʹ�ã�����" << endl;
	system("pause");
	exit(0);
}


void SpeechManager::initSpeech()
{
	this->v1.clear();
	this->v2.clear();
	this->vVictor.clear();
	this->speaker.clear();
	this->index = 1;
	this->record.clear();
}

void SpeechManager::createSpeaker()
{
	string nameSeed = "ABCDEFGHIJKL";
	for (int i = 0; i < 12; i++)
	{
		string name = "ѡ��";
		name += nameSeed[i];
		
		Speaker sp;
		sp.name = name;
		for (int j = 0; j < 2; j++)
		{
			sp.score[j] = 0;
		}
		//12��ѡ�ֱ��
		v1.push_back(i + 10001);
		//ѡ�ֱ�� �Լ���Ӧ��ѡ�� ��ŵ�map������
		this->speaker.insert(make_pair(i+10001,sp));
	}
}


void SpeechManager::startSpeech()
{
	//��һ�ֱ���

	//1����ǩ
	this->speechDraw();

	//2������
	this->speechContest();

	//3����ʾ�������
	this->showScore();


	//�ڶ��ֱ���

	this->index++;

	//1����ǩ
	this->speechDraw();

	//2������
	this->speechContest();

	//3����ʾ���ս��
	this->showScore();

	//4���������
	this->saveRecord();
	this->initSpeech();
	this->createSpeaker();
	this->loadRecord();
	cout << "���������ϣ�" << endl;
	system("system");
	system("cls");
}

void SpeechManager::speechDraw()
{
	cout << "�� << " << this->index << " >> �ֱ���ѡ�����ڳ�ǩ" << endl;
	cout << "---------------------" << endl;
	cout << "��ǩ���ݽ�˳�����£�" << endl;

	if (this->index == 1)
	{
		random_shuffle(this->v1.begin(), this->v1.end());
		for (vector<int>::iterator it = this->v1.begin(); it != this->v1.end(); it++)
		{
			cout << *it << "  ";
		}
		cout << endl;
	}
	else
	{
		random_shuffle(this->v2.begin(), this->v2.end());
		for (vector<int>::iterator it = this->v2.begin(); it != this->v2.end(); it++)
		{
			cout << *it << "  ";
		}
		cout << endl;
	}
	cout << "---------------------" << endl;
	system("pause");
	cout << endl;
}


void SpeechManager::speechContest()
{
	multimap<double, int, greater<double>> groupScore;
	int num = 0;

	cout << "------------- ��" << this->index << "����ʽ������ʼ��------------- " << endl;

	vector<int> v_Src;
	if (this->index == 1)
	{
		v_Src = this->v1;
	}
	else
	{
		v_Src = this->v2;
	}

	for (vector<int>::iterator it = v_Src.begin(); it != v_Src.end(); it++)
	{
		num++;
		deque<double> d;
		//��ί���
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;
			d.push_back(score);
		}

		sort(d.begin(),d.end(),greater<double>());  //����
		d.pop_back();                               //ȥ����ͷ�
		d.pop_front();                              //ȥ����߷�

		double sum = accumulate(d.begin(),d.end(),0.f);
		double avg = sum / d.size();

		this->speaker[*it].score[this->index - 1] = avg;

		//С��������
		

		groupScore.insert(make_pair(avg,*it));
		if (num % 6 == 0)
		{
			cout << "��" << num / 6 << "��������Σ�" << endl;
			for (multimap<double, int, greater<double>>::iterator mit = groupScore.begin(); mit != groupScore.end(); mit++)
			{
				cout << "��ţ�" << mit->second << "    ������" << this->speaker[mit->second].name << "     �ɼ���" << mit->first << endl;
			}

			//ȡǰ����
			int count = 0;
			for (multimap<double, int, greater<double>>::iterator git = groupScore.begin(); git != groupScore.end()&& count < 3; git++,count++)
			{
				if (this->index == 1)
				{
					this->v2.push_back(git->second);
				}
				else
				{
					this->vVictor.push_back(git->second);
				}
			}
			groupScore.clear();

			cout << endl;
		}
	}

	cout << "------------- ��" << this->index << "�ֱ������  ------------- " << endl;
	system("pause");
}


void SpeechManager::showScore()
{
	cout << "---------��" << this->index << "�ֽ���ѡ����Ϣ���£�-----------" << endl;
	vector<int>v;
	if (this->index == 1)
	{
		v = this->v2;
	}
	else
	{
		v = this->vVictor;
	}

	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << "ѡ�ֱ�ţ�" << *it << "    ������" << this->speaker[*it].name << "     �÷֣�" << this->speaker[*it].score[this->index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");

}


void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv",ios::out|ios::app);         //׷�ӷ�ʽд�ļ�

	for (vector<int>::iterator it = this->vVictor.begin(); it != this->vVictor.end(); it++)
	{
		ofs << *it << "," << this->speaker[*it].name << "," << this->speaker[*it].score[1] << ",";
	}
	ofs << endl;

	ofs.close();
	
	cout << "��¼�Ѿ�����" << endl;
	this->fileIsEmpty = false;
}


void SpeechManager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in);

	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		cout << "�ļ������ڣ�" << endl;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "�ļ�Ϊ�գ�" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	this->fileIsEmpty = false;

	ifs.putback(ch);//��ȡ�ĵ����ַ��Ż�ȥ

	string data;
	int number = 1;
	while (ifs >> data)
	{
		vector<string> v;
		int pos = -1;
		int start = 0;
		while (true)
		{
			pos = data.find(",",start);
			if(pos==-1)
			{
				break;
			}
			else
			{
				string temp = data.substr(start,pos-start);
				v.push_back(temp);
			}
			start = pos + 1;
		}

		this->record.insert(make_pair(number,v));
		number++;
	}
	ifs.close();
}


void SpeechManager::showRecord()
{
	if (this->fileIsEmpty)
	{
		cout << "�ļ������ڣ����߼�¼Ϊ��" << endl;
	}
	for (map<int, vector<string>>::iterator it = this->record.begin(); it != this->record.end(); it++)
	{
		cout << "��"<<it->first <<"��"<< endl 
			<< "�ھ���ţ�" << it->second[0] << "�ھ�������" << it->second[1] << "������" << it->second[2] << endl
			 << "�Ǿ���ţ�" << it->second[3] << "�Ǿ�������" << it->second[4] << "������" << it->second[5] << endl
			 << "������ţ�" << it->second[6] << "����������" << it->second[7] << "������" << it->second[8] << endl;
	}
	system("pause");
	system("cls");
}


void SpeechManager::clearRecord()
{
	cout << "ȷ����գ�" << endl;
	cout << "1��ȷ��" << endl;
	cout << "2������" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//������ڣ�ɾ�������´���
		ofstream ofs("speech.csv",ios::trunc);
		ofs.close();
		//�ļ���¼�����κθı�󣬶���Ҫ���ã�ͬʱ����ʼ��ʱҲ�����
		this->initSpeech();
		this->createSpeaker();
//		this->loadRecord();

		cout << "��ճɹ���" << endl;
	}
	system("pause");
	system("cls");
}