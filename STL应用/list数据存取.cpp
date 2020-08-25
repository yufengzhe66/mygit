#include<iostream>
using namespace std;
#include<string>
#include<list>

/*
front(); //返回第一个元素。
back(); //返回最后一个元素。
*/


void test32()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);

	cout << "第一个元素为： " << L1.front() << endl;
	cout << "最后一个元素为： " << L1.back() << endl;

	//list容器的迭代器是双向迭代器，不支持随机访问
	list<int>::iterator it = L1.begin();
	//it = it + 1;//错误，不可以跳跃访问，即使是+1,只能用自增运算符逐个访问

	//cout << *(it + 1) << endl;

}

int main()
{

	test32();

	system("pause");

	return 0;
}