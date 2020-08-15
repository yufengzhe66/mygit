#pragma once
#include<iostream>
using namespace std;

template<class T>
class myArray
{
public:
	myArray(int Capacity);
	myArray(const myArray<T>& arr);
	myArray<T>& operator=(const myArray<T>& arr);
	T& operator[](int index);
	void push_back(const T& val);
	void pop_back();
	int getCapacity();
	int getSize();
	~myArray();

private:
	T* p_Address;
	int p_Capacity;//���������Ĵ�С
	int p_Size;    //��ʾ��ʹ�õĿռ��С��T�����Ƕ���Ҳ�������Ѷ������������
};


template<class T>
myArray<T>::myArray(int Capacity)
{
//	cout << "�вι��캯������" << endl;
	this->p_Capacity = Capacity;
	this->p_Size = 0;
	this->p_Address = new T[this->p_Capacity];
}


template<class T>
myArray<T>::myArray(const myArray<T>& arr)
{
//	cout << "�������캯������" << endl;
	this->p_Capacity = arr.p_Capacity;
	this->p_Size = arr.p_Size;
	this->p_Address = new T[arr.p_Capacity];
	for (int i = 0; i < arr.p_Size; i++)
	{
		this->p_Address[i] = arr.p_Address[i];
	}
}


template<class T>
myArray<T>& myArray<T>::operator=(const myArray<T>& arr)
{
//	cout << "operator=��������" << endl;
	if (this->p_Address != NULL)
	{
		delete[] this->p_Address;
		this->p_Size = 0;
		this->p_Capacity = 0;
	}
	this->p_Capacity = arr.p_Capacity;
	this->p_Size = arr.p_Size;
	this->p_Address = new T[arr.p_Capacity];
	for (int i = 0; i < arr.p_Size; i++)
	{
		this->p_Address[i] = arr.p_Address[i];
	}
	return *this;
}


template<class T>
//��ַ���ã���֤�˿���ͨ���±�ı�ֵ
T& myArray<T>::operator[](int index)
{
	return this->p_Address[index];
}


template<class T>
void myArray<T>::push_back(const T& val)
{
	if (this->p_Capacity == this->p_Size)
		return;
	this->p_Address[this->p_Size] = val;
	this->p_Size++;
}


template<class T>
void myArray<T>::pop_back() 
{
	if (this->p_Size == 0)
		return;
	this->p_Size--;
}


template<class T>
int myArray<T>::getCapacity()
{
	return this->p_Capacity;
}


template<class T>
int myArray<T>::getSize()
{
	return this->p_Size;
}


template<class T>
myArray<T>::~myArray()
{
//	cout << "������������" << endl;
	if (this->p_Address != NULL) 
	{
		delete[] this->p_Address;
		this->p_Address = NULL;
		this->p_Size = 0;
		this->p_Capacity = 0;
	}
}



