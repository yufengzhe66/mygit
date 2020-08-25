#include<iostream>
using namespace std;
#include<string>
#include<list>

/*
*STL�е�������һ��˫��ѭ������
* ��������Ĵ洢��ʽ�������������ڴ�ռ䣬�������list�еĵ�����ֻ֧��ǰ�ƺͺ��ƣ�����˫�������
list<T> lst; //list���ò���ģ����ʵ��,�����Ĭ�Ϲ�����ʽ��
list(beg,end); //���캯����[beg, end)�����е�Ԫ�ؿ���������
list(n,elem); //���캯����n��elem����������
list(const list &lst); //�������캯����
*/

void printList1(const list<int>& L)
{
	for (list<int>::const_iterator it = L.begin(); it != L.end(); it++)
	{
		cout << *it << "  ";
	}
	cout << endl;
}


void test28()
{
	list<int>L1;
	L1.push_back(10);
	L1.push_back(20);
	L1.push_back(30);
	L1.push_back(40);
	printList1(L1);

	list<int>L2(L1.begin(), L1.end());
	printList1(L2);

	list<int>L3(L1);
	printList1(L3);

	list<int>L4(10,1000);
	printList1(L4);
}

