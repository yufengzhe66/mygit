#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

/*
copy(iterator beg, iterator end, iterator dest);

// ��ֵ����Ԫ�أ��ҵ�����ָ��λ�õ��������Ҳ������ؽ���������λ��

// beg ��ʼ������

// end ����������

// dest Ŀ����ʼ������
*/

void myPrint2(int val)
{
	cout << val << "  ";
}

void test13()
{
	vector<int> v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}

	vector<int> v2;
	v2.resize(v1.size());
	copy(v1.begin(),v1.end(),v2.begin());

	for_each(v2.begin(), v2.end(), myPrint2);
	cout << endl;
}

