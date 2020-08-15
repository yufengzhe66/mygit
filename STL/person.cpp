#include "person.h"


template<class T1, class T2>
person<T1, T2>::person(T1 name, T2 age)
{
	this->name = name;
	this->age = age;
}

template<class T1, class T2>
void person<T1, T2>::show()
{
	cout << "ÐÕÃû: " << this->name << " ÄêÁä:" << this->age << endl;
}
