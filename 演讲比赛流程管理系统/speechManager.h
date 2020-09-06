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
	vector<int > v1;               //����ѡ�� ����  12��

	vector<int > v2;               //��һ�ֽ�������  6��
	
	vector<int > vVictor;          //ʤ��ǰ��������  3��

	map<int, Speaker> speaker;     //��ű�� �Լ���Ӧ�� ����ѡ�� ����

	int index;                     //��¼��������

	bool fileIsEmpty;             //�ļ�Ϊ�յı�־

	map<int, vector<string>> record;    //�����¼
};
