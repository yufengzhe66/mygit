#include<iostream>
using namespace std;
#include<vector>
#include<algorithm>
#include<functional>

/*
template<class T> bool logical_and<T> //Âß¼­Óë
template<class T> bool logical_or<T> //Âß¼­»ò
template<class T> bool logical_not<T> //Âß¼­·Ç
*/

void test19()
{
	vector<bool> v1;
	v1.push_back(true);
	v1.push_back(false);
	v1.push_back(true);
	v1.push_back(false);

	for (vector<bool>::iterator it = v1.begin(); it != v1.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;

	vector<bool> v2;
	v2.resize(v1.size());
	transform(v1.begin(), v1.end(), v2.begin(), logical_not<bool>());

	for (vector<bool>::iterator it = v2.begin(); it != v2.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

int main()
{
	test19();
	system("pause");
	return 0;
}