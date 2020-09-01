#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


/*
for_each(iterator beg, iterator end, _func);
// �����㷨 ��������Ԫ��
// beg ��ʼ������
// end ����������
// _func (��ͨ)�������ߺ�������(�º���)
*/

//��ͨ����
void print01(int val)
{
	cout << val << "  ";
}


//�º���
class print02
{
public:
	void operator()(int val)
	{
		cout << val << "  ";
	}
};

void test01()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}
	for_each(v.begin(),v.end(),print01);
	cout << endl;
	for_each(v.begin(),v.end(),print02());
	cout << endl;
}

