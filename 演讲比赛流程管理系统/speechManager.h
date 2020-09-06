#pragma once
#include<iostream>
using namespace std;
#include<vector>
#include<map>
#include "speaker.h"

class SpeechManager
{
public:
	SpeechManager();

	void showMenu();

	void exitSystem();

	void initSpeech();

	void createSpeaker();

	void startSpeech();

	void speechDraw();

	void speechContest();

	void showScore();

	void saveRecord();

	void loadRecord();

	void showRecord();

	void clearRecord();

	~SpeechManager();



public:
	vector<int > v1;               //比赛选手 容器  12人

	vector<int > v2;               //第一轮晋级容器  6人
	
	vector<int > vVictor;          //胜利前三名容器  3人

	map<int, Speaker> speaker;     //存放编号 以及对应的 具体选手 容器

	int index;                     //记录比赛轮数

	bool fileIsEmpty;             //文件为空的标志

	map<int, vector<string>> record;    //往届记录
};
