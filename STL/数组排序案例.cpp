#include<iostream>
using namespace std;



template<typename T>
void myswap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}

template<typename T>
void mySort(T arr[], int len)
{
	for (int i = 0; i < len; i++) 
	{
		int min = i;
		for (int j = i+1; j < len; j++)
		{
			if (arr[min] < arr[j])
			{
				min = j;
			}
		}
		if (min != i)
		{
			myswap(arr[i],arr[min]);
		}
	}
}

template<typename T>
void myPrint(T arr[],int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << arr[i] << "    ";
	}
	cout << endl;
}


void test02()
{
	//����char����
	/*
	char charArr[] = "bdcfeagh";
	int num = sizeof(charArr) / sizeof(char);
	mySort(charArr, num);
	myPrint(charArr, num);
	*/


	//����int����
	int intArr[] = { 7, 5, 8, 1, 3, 9, 2, 4, 6 };
	int num = sizeof(intArr) / sizeof(int);
	mySort(intArr, num);
	myPrint(intArr, num);
	
}