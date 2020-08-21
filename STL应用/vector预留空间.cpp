#include<iostream>
using namespace std;
#include<vector>

/*
reserve(int len);//容器预留len个元素长度，预留位置不初始化，元素不可访问。
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
		//统计内存进行了内存扩展的次数
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