#include<iostream>
using namespace std;
#include<memory>
#include<string>

class Person1
{
public:
	~Person1()
	{
		cout << "~Person1" << endl;
	}
	string str;
};




unique_ptr<Person1> test()
{
	return unique_ptr<Person1> (new Person1);
}

//只能有一个指针拥有对象的所有权，可以用move的方式转移所有权
void test10()
{
	unique_ptr<string> pointer1(new string("hello world!"));
	cout << *pointer1 << endl;

	unique_ptr<Person1> pointer2 = test();
	pointer2->str = "hello";
	cout << pointer2->str << endl;
	
	unique_ptr<Person1> pointer3 = move(pointer2);
	cout<< pointer3->str << endl;
	
	pointer3.reset(new Person1);  //重置pointer3的指针，person会调用两次析构

	auto ptr = make_unique<Person1>();
	ptr->str = "hello c++";

	cout << ptr->str << endl;
}


template<typename T>
struct Node
{
	T data;
	unique_ptr<Node<T>> next;
	~Node()
	{
		cout << "~Node" << endl;
	}
};

template<typename T>
class Link 
{
public:
	void front(const T& data)
	{
		auto node = make_unique<Node<T>>();
		node->data = data;
		node->next = move(head.next);           // 相当于 node.next = head.next;   切记一定要用move，不然会出错
		head.next = move(node);                 // 相当于 head.next = node;        unique_ptr不能直接赋值
    }

	void print()
	{
		Node<T>* node = head.next.get();        //要用get方法获取到对象底层的指针，才能取出其中的数据
		while (node)
		{
			cout << node->data << "  ";
			node = node->next.get();
		}
		cout << endl;
	}
private:
	Node<T> head;
};


//
//int main()
//{
//	Link<int> lk;
//	for(int val:{1,2,3,4,5})
//	{
//		lk.front(val);
//	}
//	lk.print();
//	return 0;
//}
//  
