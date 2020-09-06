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
	cout << "*************  欢迎参加演讲比赛 ************" << endl;
	cout << "*************  1.开始演讲比赛  *************" << endl;
	cout << "*************  2.查看往届记录  *************" << endl;
	cout << "*************  3.清空比赛记录  *************" << endl;
	cout << "*************  0.退出比赛程序  *************" << endl;
	cout << "********************************************" << endl;
	cout << endl;
}


void SpeechManager::exitSystem()
{
	cout << "欢迎下次使用！！！" << endl;
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
		string name = "选手";
		name += nameSeed[i];
		
		Speaker sp;
		sp.name = name;
		for (int j = 0; j < 2; j++)
		{
			sp.score[j] = 0;
		}
		//12名选手编号
		v1.push_back(i + 10001);
		//选手编号 以及对应的选手 存放到map容器中
		this->speaker.insert(make_pair(i+10001,sp));
	}
}


void SpeechManager::startSpeech()
{
	//第一轮比赛

	//1、抽签
	this->speechDraw();

	//2、比赛
	this->speechContest();

	//3、显示晋级结果
	this->showScore();


	//第二轮比赛

	this->index++;

	//1、抽签
	this->speechDraw();

	//2、比赛
	this->speechContest();

	//3、显示最终结果
	this->showScore();

	//4、保存分数
	this->saveRecord();
	this->initSpeech();
	this->createSpeaker();
	this->loadRecord();
	cout << "本届比赛完毕！" << endl;
	system("system");
	system("cls");
}

void SpeechManager::speechDraw()
{
	cout << "第 << " << this->index << " >> 轮比赛选手正在抽签" << endl;
	cout << "---------------------" << endl;
	cout << "抽签后演讲顺序如下：" << endl;

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

	cout << "------------- 第" << this->index << "轮正式比赛开始：------------- " << endl;

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
		//评委打分
		for (int i = 0; i < 10; i++)
		{
			double score = (rand() % 401 + 600) / 10.f;
			d.push_back(score);
		}

		sort(d.begin(),d.end(),greater<double>());  //排序
		d.pop_back();                               //去掉最低分
		d.pop_front();                              //去掉最高分

		double sum = accumulate(d.begin(),d.end(),0.f);
		double avg = sum / d.size();

		this->speaker[*it].score[this->index - 1] = avg;

		//小组内排名
		

		groupScore.insert(make_pair(avg,*it));
		if (num % 6 == 0)
		{
			cout << "第" << num / 6 << "组比赛名次：" << endl;
			for (multimap<double, int, greater<double>>::iterator mit = groupScore.begin(); mit != groupScore.end(); mit++)
			{
				cout << "编号：" << mit->second << "    姓名：" << this->speaker[mit->second].name << "     成绩：" << mit->first << endl;
			}

			//取前三名
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

	cout << "------------- 第" << this->index << "轮比赛完毕  ------------- " << endl;
	system("pause");
}


void SpeechManager::showScore()
{
	cout << "---------第" << this->index << "轮晋级选手信息如下：-----------" << endl;
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
		cout << "选手编号：" << *it << "    姓名：" << this->speaker[*it].name << "     得分：" << this->speaker[*it].score[this->index - 1] << endl;
	}
	cout << endl;

	system("pause");
	system("cls");

}


void SpeechManager::saveRecord()
{
	ofstream ofs;
	ofs.open("speech.csv",ios::out|ios::app);         //追加方式写文件

	for (vector<int>::iterator it = this->vVictor.begin(); it != this->vVictor.end(); it++)
	{
		ofs << *it << "," << this->speaker[*it].name << "," << this->speaker[*it].score[1] << ",";
	}
	ofs << endl;

	ofs.close();
	
	cout << "记录已经保存" << endl;
	this->fileIsEmpty = false;
}


void SpeechManager::loadRecord()
{
	ifstream ifs("speech.csv", ios::in);

	if (!ifs.is_open())
	{
		this->fileIsEmpty = true;
		cout << "文件不存在！" << endl;
		ifs.close();
		return;
	}

	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		cout << "文件为空！" << endl;
		this->fileIsEmpty = true;
		ifs.close();
		return;
	}

	this->fileIsEmpty = false;

	ifs.putback(ch);//读取的单个字符放回去

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
		cout << "文件不存在，或者记录为空" << endl;
	}
	for (map<int, vector<string>>::iterator it = this->record.begin(); it != this->record.end(); it++)
	{
		cout << "第"<<it->first <<"届"<< endl 
			<< "冠军编号：" << it->second[0] << "冠军姓名：" << it->second[1] << "分数：" << it->second[2] << endl
			 << "亚军编号：" << it->second[3] << "亚军姓名：" << it->second[4] << "分数：" << it->second[5] << endl
			 << "季军编号：" << it->second[6] << "季军姓名：" << it->second[7] << "分数：" << it->second[8] << endl;
	}
	system("pause");
	system("cls");
}


void SpeechManager::clearRecord()
{
	cout << "确认清空？" << endl;
	cout << "1、确认" << endl;
	cout << "2、返回" << endl;

	int select = 0;
	cin >> select;

	if (select == 1)
	{
		//如果存在，删除并重新创建
		ofstream ofs("speech.csv",ios::trunc);
		ofs.close();
		//文件记录发生任何改变后，都需要调用，同时，初始化时也需调用
		this->initSpeech();
		this->createSpeaker();
//		this->loadRecord();

		cout << "清空成功！" << endl;
	}
	system("pause");
	system("cls");
}