#include<iostream>
using namespace std;
#include<vector>

/*
push_back(ele); //β������Ԫ��ele
pop_back(); //ɾ�����һ��Ԫ��
insert(const_iterator pos, ele); //������ָ��λ��pos����Ԫ��ele
insert(const_iterator pos, int count,ele);//������ָ��λ��pos����count��Ԫ��ele
erase(const_iterator pos); //ɾ��������ָ���Ԫ��
erase(const_iterator start, const_iterator end);//ɾ����������start��end֮���Ԫ��
clear(); //ɾ������������Ԫ��
*/

void printVector3(vector<int>& v)
{
	for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;
}

void test15()
{
	vector<int>v1;
	// β��
	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	printVector3(v1);
	//βɾ
	v1.pop_back();
	printVector3(v1);

	//����
	v1.insert(v1.begin(),100);
	printVector3(v1);

	v1.insert(v1.begin(),2,1000);
	printVector3(v1);

	//ɾ��
	v1.erase(v1.begin());
	printVector3(v1);

	//���
	v1.erase(v1.begin(),v1.end());
	printVector3(v1);

	v1.push_back(10);
	v1.push_back(20);
	v1.push_back(30);
	v1.push_back(40);
	v1.push_back(50);
	v1.clear();
	printVector3(v1);

}

int main()
{

	test15();

	system("pause");

	return 0;
}