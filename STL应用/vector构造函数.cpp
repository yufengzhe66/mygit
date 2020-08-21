#include<iostream>
using namespace std;
#include<vector>

/*
vector<T> v; //����ģ��ʵ����ʵ�֣�Ĭ�Ϲ��캯��
vector(v.begin(), v.end()); //��v[begin(), end())�����е�Ԫ�ؿ���������
vector(n, elem); //���캯����n��elem����������
vector(const vector &vec); //�������캯����
*/

void printVector(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}


void test12()
{
	vector<int>v1;//�޲ι���

	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	vector<int>v2(v1.begin(),v1.end());
	printVector(v2);

	vector<int>v3(10, 100);
	printVector(v3);

	vector<int>v4(v3);
	printVector(v4);
}

int main()
{
	test12();
	return 0;
}
