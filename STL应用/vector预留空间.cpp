#include<iostream>
using namespace std;
#include<vector>

/*
reserve(int len);//����Ԥ��len��Ԫ�س��ȣ�Ԥ��λ�ò���ʼ����Ԫ�ز��ɷ��ʡ�
*/

void test18()
{
	vector<int>v;
	v.reserve(10000);

	int num = 0;
	int* p = NULL;
	for (int i = 0; i < 10000; i++)
	{
		v.push_back(i);
		//ͳ���ڴ�������ڴ���չ�Ĵ���
		if (p != &v[0])
		{
			p = &v[0];
			num++;
		}
	}
	cout << "num:" << num << endl;
}

int main()
{

	test18();

	system("pause");

	return 0;
}