#include<iostream>
#include<string>
using namespace std;
//关于运算符重载（包括输入输出运算符，自增（减）运算符）

class MyInteger {

	friend ostream& operator<<(ostream& out, const MyInteger& myint);

	friend istream& operator>>(istream& in, MyInteger& myint);

public:
	MyInteger(int num = 0) {
		this->m_Num = num;
	}
	//前置++
	MyInteger& operator++() {
		//先++
		m_Num++;
		//再返回
		return *this;
	}


	//前置--
	MyInteger& operator--()
	{
		m_Num--;
		return *this;
	}



	//后置++
	MyInteger operator++(int) {
		//先返回
		MyInteger temp = *this; //记录当前本身的值，然后让本身的值加1，但是返回的是以前的值，达到先返回后++；
		m_Num++;
		return temp;
	}


	//后置--
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


//前置++ 先++ 再返回
void test01() {
	MyInteger myInt;
	cout << --myInt << endl;
	cout << myInt << endl;
}

//后置++ 先返回 再++
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