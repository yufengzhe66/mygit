#pragma once
#include<iostream>
using namespace std;
#include<string>

template<class T1, class T2>
class person
{
public:
	person(T1 name, T2 ag);
	void show();
private:
	T1 name;
	T2 age;
};