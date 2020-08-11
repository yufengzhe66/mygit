#include<iostream>
#include<string>
using namespace std;
//������������أ������������������������������������

class MyInteger {

	friend ostream& operator<<(ostream& out, const MyInteger& myint);

	friend istream& operator>>(istream& in, MyInteger& myint);

public:
	MyInteger(int num = 0) {
		this->m_Num = num;
	}
	//ǰ��++
	MyInteger& operator++() {
		//��++
		m_Num++;
		//�ٷ���
		return *this;
	}


	//ǰ��--
	MyInteger& operator--()
	{
		m_Num--;
		return *this;
	}



	//����++
	MyInteger operator++(int) {
		//�ȷ���
		MyInteger temp = *this; //��¼��ǰ�����ֵ��Ȼ���ñ����ֵ��1�����Ƿ��ص�����ǰ��ֵ���ﵽ�ȷ��غ�++��
		m_Num++;
		return temp;
	}


	//����--
	MyInteger operator--(int)
	{
		MyInteger temp = *this;
		m_Num++;
		return temp;
	}

private:
	int m_Num;
};


ostream& operator<<(ostream& out, const MyInteger& myint) {
	out << myint.m_Num;
	return out;
}


istream& operator>>(istream& in, MyInteger& myint)
{
	in >> myint.m_Num;
	return in;
}


//ǰ��++ ��++ �ٷ���
void test01() {
	MyInteger myInt;
	cout << --myInt << endl;
	cout << myInt << endl;
}

//����++ �ȷ��� ��++
void test02() {

	MyInteger myInt;
	cout << myInt-- << endl;
	cout << myInt << endl;
}

/*
int main() {

	//test01();
	//test02();
	MyInteger mytest;
	cin >> mytest;
	cout << mytest << endl;
	system("pause");

	return 0;
}

*/