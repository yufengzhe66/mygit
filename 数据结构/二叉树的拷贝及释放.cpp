#include<iostream>
using namespace std;
#include<stdlib.h>
#include<algorithm>


/*
二叉树的拷贝（包括建立）和释放的若干问题：
  1.Copytree()方法和freeTree()方法注意传参方式，只能使用指针的引用方式，
  如果传指针变量，会导致错误，因为指针变量是一个局部变量，并没有在原树上操作

  2.malloc调用之后需要对指针进行判断，否则会有警告
  */



struct BinaryNode1
{
	char ch;
	struct BinaryNode1* lchild;
	struct BinaryNode1* rchild;
};

BinaryNode1* BuildTree1()
{
	static struct BinaryNode1 nodeA = { 'A', NULL, NULL };
	static struct BinaryNode1 nodeB = { 'B', NULL, NULL };
	static struct BinaryNode1 nodeC = { 'C', NULL, NULL };
	static struct BinaryNode1 nodeD = { 'D', NULL, NULL };
	static struct BinaryNode1 nodeE = { 'E', NULL, NULL };
	static struct BinaryNode1 nodeF = { 'F', NULL, NULL };
	static struct BinaryNode1 nodeG = { 'G', NULL, NULL };
	static struct BinaryNode1 nodeH = { 'H', NULL, NULL };

	nodeA.lchild = &nodeB;
	nodeA.rchild = &nodeF;

	nodeB.rchild = &nodeC;

	nodeC.lchild = &nodeD;
	nodeC.rchild = &nodeE;

	nodeF.rchild = &nodeG;

	nodeG.lchild = &nodeH;
	return &nodeA;
}


BinaryNode1* Copytree(BinaryNode1* root,BinaryNode1* newNode)
{
	if (root == NULL)
	{
		newNode = NULL;
	}
	else
	{
		newNode = (BinaryNode1*)malloc(sizeof(BinaryNode1));
		if (newNode) 
		{
			newNode->ch = root->ch;
			newNode->lchild = Copytree(root->lchild, newNode->lchild);
			newNode->rchild = Copytree(root->rchild, newNode->rchild);		
		}
	}
	return newNode;
}


void CopyTree(BinaryNode1* root, BinaryNode1* &newNode)
{
	if (root == NULL)
	{
		newNode = NULL;
	}
	else
	{
		newNode = (BinaryNode1*)malloc(sizeof(BinaryNode1));
		if (newNode)
		{
			newNode->ch = root->ch;
			CopyTree(root->lchild, newNode->lchild);
			CopyTree(root->rchild, newNode->rchild);
		}
	}
}


BinaryNode1* copyTree(BinaryNode1* root)
{
	if (root == NULL)
	{
		return NULL;
	}
	else
	{
		BinaryNode1* lchild = copyTree(root->lchild);
		BinaryNode1* rchild = copyTree(root->rchild);

		BinaryNode1* newNode = (BinaryNode1*)malloc(sizeof(BinaryNode1));
		if (newNode)
		{
			newNode->ch = root->ch;
			newNode->lchild = lchild;
			newNode->rchild = rchild;
		}

		return newNode;
	}
}


void freeTree(BinaryNode1* &root)
{
	if (root == NULL)
	{
		return;
	}
	else 
	{
		freeTree(root->lchild);
		freeTree(root->rchild);
		cout << "结点" << root->ch << "被释放了" << endl;
		free(root);
		root = NULL;
	}
}


void PreOrder(struct BinaryNode1* root)
{
	if (root!=NULL)
	{
		cout << root->ch << "  ";
		PreOrder(root->lchild);
		PreOrder(root->rchild);
	}
}


void InOrder(struct BinaryNode1* root)
{
	if (root)
	{
		InOrder(root->lchild);
		cout << root->ch << "  ";
		InOrder(root->rchild);
	}
}


void PostOrder(struct BinaryNode1* root)
{
	if (root)
	{
		PostOrder(root->lchild);
		PostOrder(root->rchild);
		cout << root->ch << "  ";
	}
}


void test04()
{
	BinaryNode1* root = BuildTree1();
	BinaryNode1* newTree1 = NULL;
	BinaryNode1* newTree2 = NULL;
	BinaryNode1* newTree = NULL;

	newTree = Copytree(root,newTree);
	CopyTree(root, newTree1);
	newTree2 = copyTree(newTree1);
	cout << "-----------先序遍历--------------" << endl;
	PreOrder(newTree1);
	cout << endl;
	PreOrder(newTree2);
	cout << endl;
	PreOrder(newTree);
	cout << endl;


	cout << "-----------中序遍历--------------" << endl;
	InOrder(newTree1);
	cout << endl;
	InOrder(newTree2);
	cout << endl;
	InOrder(newTree);
	cout << endl;


	cout << "-----------后序遍历--------------" << endl;;
	PostOrder(newTree1);
	cout << endl;
	PostOrder(newTree2);
	cout << endl;
	PostOrder(newTree2);
	cout << endl;


	freeTree(newTree2);
	
}


int main()
{
	test04();
	system("pause");
	return 0;
}