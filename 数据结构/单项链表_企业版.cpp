#include<iostream>
using namespace std;
#include<stdlib.h>

struct LinkNode
{
	struct LinkNode* next;
};

struct LList
{
	struct LinkNode pHeader;
	int size;
};

typedef void* LinkList;

//初始化链表

LList* init_LinkList()
{
	struct LList* myList = (LList*)malloc(sizeof(struct LList));

	if (myList == NULL)
	{
		return NULL;
	}
	myList->pHeader.next = NULL;
	myList->size = 0;
	return myList;
} 

void intsert_LinkList(LinkList list, int pos, void* data)
{
	if (list == NULL)
	{
		return;
	}
	if(data==NULL)
	{
		return;
	}
	struct LList* mylist = (LList*)list;
	if (pos<0 || pos>mylist->size - 1)
	{
		//无效位置尾插
		pos = mylist->size;
	}

	struct LinkNode* myNode = (LinkNode*)data;
	
	struct LinkNode* pCurrent = &mylist->pHeader;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	myNode->next = pCurrent->next;
	pCurrent->next = myNode;

	mylist->size++;
}

void foreach_LinkList(LinkList list,void(*myForeach)(void*))
{
	if (list == NULL)
	{
		return;
	}
	struct LList* mylist = (LList*)list;
	struct LinkNode* myNode = mylist->pHeader.next;
	for (int i = 0; i < mylist->size; i++)
	{
		myForeach(myNode);
		myNode = myNode->next;
	}
	cout << endl;
}


void removeByPos_ListList(LinkList list, int pos)
{
	if (list == NULL)
	{
		return;
	}
	struct LList* mylist = (LList*)list;

	if (pos < 0 || pos > mylist->size - 1)
	{
		return;
	}

	struct LinkNode* pCurrent = &mylist->pHeader;
	for (int i = 0; i < pos; i++)
	{
		pCurrent = pCurrent->next;
	}

	struct LinkNode* pDel = pCurrent->next;

	pCurrent->next = pDel->next;
	//free(pDel);
	mylist->size--;
}


void destroy_LinkList(LinkList list)
{
	if(list==NULL)
	{
		return;
	}
	free(list);
	list = NULL;
}



struct Person
{
	void* node;
	char name[64];
	int age;
};


void myPrintPerson(void* data)
{
	struct Person* p = (Person*)data;
	cout << "姓名：" << p->name << "年龄：" << p->age << endl;
}


void test01()
{
	LinkList mylist = init_LinkList();

	struct Person p1 = { NULL,"aaa",10 };
	struct Person p2 = { NULL,"bbb",20 };
	struct Person p3 = { NULL,"ccc",30 };
	struct Person p4 = { NULL,"ddd",40 };
	struct Person p5 = { NULL,"eee",50 };

	intsert_LinkList(mylist, 0, &p1);
	intsert_LinkList(mylist, 0, &p2);
	intsert_LinkList(mylist, 1, &p3);
	intsert_LinkList(mylist, -1, &p4);
	intsert_LinkList(mylist, 0, &p5);

	foreach_LinkList(mylist, myPrintPerson);

	removeByPos_ListList(mylist, 3);

	foreach_LinkList(mylist, myPrintPerson);

	destroy_LinkList(mylist);

	foreach_LinkList(mylist, myPrintPerson);
}

int main()
{
	test01();
	system("pause");
	return 0;
}