#include<iostream>
using namespace std;
#include<string>

template<typename T>
class base
{
protected:
	T m;
};

//������̳еĸ�����һ����ģ��ʱ��������������ʱ��Ҫָ����������T������
//�����ָ�����������޷�����������ڴ�

class son1 :public base<int>
{
public:
	void show()
	{
		m = 10;
		cout << m << endl;
	}
};


//��ģ��̳���ģ�� ,������T2ָ�������е�T����
template<class T1,class T2>
class son2 :public base<T2>
{
	T1 son;
public:
	void show()
	{
		cout << typeid(T1).name() << endl;
		cout << typeid(T2).name() << endl;
	}
};

void test09()
{
	son2<int, char>s;
	s.show();
	son1 s1;
	s1.show();
}

