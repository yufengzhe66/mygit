#include<iostream>
using namespace std;
#include<functional>
/*
��Щ�º����������Ķ����÷���һ�㺯����ȫ��ͬ
ʹ���ڽ�����������Ҫ����ͷ�ļ� #include<functional>

�º���ԭ�ͣ�

template<class T> T plus<T> //�ӷ��º���
template<class T> T minus<T> //�����º���
template<class T> T multiplies<T> //�˷��º���
template<class T> T divides<T> //�����º���
template<class T> T modulus<T> //ȡģ�º���
template<class T> T negate<T> //ȡ���º���
*/

void test17()
{
	negate<int> abs;
	cout << abs(50) << endl;;
	plus<int> add;
	cout << add(10, 20) << endl;
}
int main()
{
	test17();
	system("pause");
	return 0;
}