#include<iostream>
using namespace std;


template<typename T>
//���ڽ����ĺ�������Ҫ����Ϊswap,��Ϊ�����ö��壬��������ش���������
void myswap(T& a,T& b)
{
	T temp = a;
	a = b;
	b = temp;
}


void test01()
{
	int a = 10;
	int b = 20;
	myswap<int>(a,b);//��ʽָ������

	cout << "a=" << a << endl << "b=" << b << endl;


	double c = 1.1;
	double d = 2.2;
	myswap(c, d);//�Զ��Ƶ����ͣ�ģ������Ƶ���һ�µ����ͣ��ſ�ʹ�ã�ͬʱģ�����Ҫȷ����T���������ͣ��ſ�ʹ�ã���ʹ�����޲Σ�ҲҪ��ʽ��ָ������

	cout << "c=" << c << endl << "d=" << d << endl;


}


