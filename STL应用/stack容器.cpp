#include<iostream>
using namespace std;
#include<stack>

void test26()
{
	stack<int> s;
	s.push(10);
	s.push(20);
	s.push(30);

	while (!s.empty())
	{
		cout<<"ջ��Ԫ��Ϊ�� " << s.top() << endl;
		s.pop();
	}

	cout << "ջ�Ĵ�СΪ��" << s.size() << endl;
}


