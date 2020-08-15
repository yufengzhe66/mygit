#include "myArray.hpp"


void printIntArray(myArray<int>&arr)
{
	for (int i = 0; i < arr.getSize(); i++) 
	{
		cout << arr[i] << "  ";
	}
	cout << endl;
}

void test13()
{
	myArray<int> array1(10);
	for (int i = 0; i < 10; i++)
	{
		array1.push_back(i);
	}
	cout << "array1打印输出：" << endl;
	printIntArray(array1);
	cout << "array1的大小：" << array1.getSize() << endl;
	cout << "array1的容量：" << array1.getCapacity() << endl;

	cout << "--------------------------" << endl;

	myArray<int> array2(array1);
	array2.pop_back();
	cout << "array2打印输出：" << endl;
	printIntArray(array2);
	cout << "array2的大小：" << array2.getSize() << endl;
	cout << "array2的容量：" << array2.getCapacity() << endl;
	cout << "--------------------------" << endl;
}


//测试自定义数据类型
class Person {
public:
	Person() {}
	Person(string name, int age) {
		this->m_Name = name;
		this->m_Age = age;
	}
public:
	string m_Name;
	int m_Age;
};

void printPersonArray(myArray<Person>& personArr)
{
	for (int i = 0; i < personArr.getSize(); i++) 
	{
		cout << "姓名：" << personArr[i].m_Name << " 年龄： " << personArr[i].m_Age << endl;
	}

}

void test14()
{
	//创建数组
	myArray<Person> pArray(10);
	Person p1("孙悟空", 30);
	Person p2("韩信", 20);
	Person p3("妲己", 18);
	Person p4("王昭君", 15);
	Person p5("赵云", 24);

	//插入数据
	pArray.push_back(p1);
	pArray.push_back(p2);
	pArray.push_back(p3);
	pArray.push_back(p4);
	pArray.push_back(p5);

	printPersonArray(pArray);

	cout << "pArray的大小：" << pArray.getSize() << endl;
	cout << "pArray的容量：" << pArray.getCapacity() << endl;
}


int main()
{
	test13();
	test14();
	return 0;
}