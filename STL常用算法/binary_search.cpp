#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

/*
bool binary_search(iterator beg, iterator end, value);
// ����ָ����Ԫ�أ��鵽 ����true ����false
// ע��: �����������в�����
// beg ��ʼ������
// end ����������
// value ���ҵ�Ԫ��
*/


void test06()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	bool ret = binary_search(v.begin(),v.end(),2);

	if (ret)
	{
		cout << "�ҵ���" << endl;
	}
	else
	{
		cout << "δ�ҵ�" << endl;
	}
}

