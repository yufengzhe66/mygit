#include<iostream>
using namespace std;
#include<memory>
#include<string>


struct Person2:enable_shared_from_this<Person2>
{
	void show()
	{
		cout << "Person" << endl;
	}
	shared_ptr<Person2> getShared()
	{
		return shared_from_this();
	}
};



void test11()
{
	shared_ptr<string> pointer1(new string("hello world"));

	cout << pointer1.use_count() << endl;

	cout << *pointer1 << endl;

	shared_ptr<string> pointer2 = pointer1;

	cout << pointer2.use_count() << endl;

	shared_ptr<Person2> pointer3(new Person2);
	shared_ptr<Person2> pointer4 = pointer3->shared_from_this();

	cout << pointer3.use_count() << endl;
}


int main()
{
	test11();

	system("pause");
	return 0;
}