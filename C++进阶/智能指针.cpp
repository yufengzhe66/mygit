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

//ֻ����һ��ָ��ӵ�ж��������Ȩ��������move�ķ�ʽת������Ȩ
void test10()
{
	unique_ptr<string> pointer1(new string("hello world!"));
	cout << *pointer1 << endl;

	unique_ptr<Person1> pointer2 = test();
	pointer2->str = "hello";
	cout << pointer2->str << endl;
	
	unique_ptr<Person1> pointer3 = move(pointer2);
	cout<< pointer3->str << endl;
	
	pointer3.reset(new Person1);  //����pointer3��ָ�룬person�������������

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
		node->next = move(head.next);           // �൱�� node.next = head.next;   �м�һ��Ҫ��move����Ȼ�����
		head.next = move(node);                 // �൱�� head.next = node;        unique_ptr����ֱ�Ӹ�ֵ
    }

	void print()
	{
		Node<T>* node = head.next.get();        //Ҫ��get������ȡ������ײ��ָ�룬����ȡ�����е�����
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
