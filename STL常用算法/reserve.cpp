#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>

/*
reverse(iterator beg, iterator end);

// ��תָ����Χ��Ԫ��

// beg ��ʼ������

// end ����������
*/

class MyPrint1
{
public:
	void operator()(int val)
	{
		cout << val << "  ";
	}
};

void test12()
{
	vector<int> v;
	v.push_back(10);
	v.push_back(30);
	v.push_back(50);
	v.push_back(20);
	v.push_back(40);

	cout << "��תǰ�� " << endl;
	for_each(v.begin(),v.end(),MyPrint1());
	cout << endl;

	cout << "��ת�� " << endl;
	reverse(v.begin(),v.end());
	for_each(v.begin(), v.end(), MyPrint1());
	cout << endl;
}

int main()
{
	test12();
	system("pause");
	return 0;
}