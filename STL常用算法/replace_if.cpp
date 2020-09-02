#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

/*
replace_if(iterator beg, iterator end, _pred, newvalue);

// �������滻Ԫ�أ������������滻��ָ��Ԫ��

// beg ��ʼ������

// end ����������

// _pred ν��

// newvalue �滻����Ԫ��
*/

void myPrint4(int val)
{
	cout << val << "  ";
}

class ReplaceGreater30
{
public:
	bool operator()(int val)
	{
		return val > 30;
	}
};

void test15()
{
	vector<int> v;
	v.push_back(20);
	v.push_back(30);
	v.push_back(20);
	v.push_back(40);
	v.push_back(50);
	v.push_back(10);
	v.push_back(20);

	replace_if(v.begin(), v.end(), ReplaceGreater30(), 200);
	for_each(v.begin(), v.end(), myPrint4);
	cout << endl;
}

