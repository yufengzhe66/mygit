#include<iostream>
using namespace std;
#include<vector>

/*
swap(vec); // 将vec与本身的元素互换
*/

void printVector4(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test17()
{
	vector<int>v1;
	for (int i = 0; i < 10; i++)
	{
		v1.push_back(i);
	}
	printVector4(v1);

	vector<int>v2;
	for (int i = 10; i > 0; i--)
	{
		v2.push_back(i);
	}
	printVector4(v2);

	//互换容器
	cout << "--------------互换后-------------" << endl;
	v1.swap(v2);
	printVector4(v1);
	printVector4(v2);


	vector<int> v;
	for (int i = 0; i < 100000; i++) 
	{
		v.push_back(i);
	}

	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;

	v.resize(3);

	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;

	//收紧内存
	vector<int>(v).swap(v);
	cout << "v的容量为：" << v.capacity() << endl;
	cout << "v的大小为：" << v.size() << endl;
}

