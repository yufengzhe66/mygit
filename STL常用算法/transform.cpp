#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>


/*����������
������������һ��������

����ԭ�ͣ�
transform(iterator beg1, iterator end1, iterator beg2, _func);
//beg1 Դ������ʼ������
//end1 Դ��������������
//beg2 Ŀ��������ʼ������
//_func �������ߺ�������
*/

class Transform
{
public:
	int operator()(int val)
	{
		return val;
	}
};

class MyPrint
{
public:
	void operator()(int val)
	{
		cout << val << "  ";
	}
};

void test02()
{
	vector<int> v;
	for (int i = 0; i < 10; i++)
	{
		v.push_back(i);
	}

	vector<int> vTarget;
	vTarget.resize(v.size());
	transform(v.begin(),v.end(),vTarget.begin(),Transform());
	for_each(vTarget.begin(), vTarget.end(), MyPrint());
	cout << endl;
}
