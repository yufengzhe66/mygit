#include<iostream>
using namespace std;
#include<stdlib.h>
#include<algorithm>


/*
�������Ŀ������������������ͷŵ��������⣺
  1.Copytree()������freeTree()����ע�⴫�η�ʽ��ֻ��ʹ��ָ������÷�ʽ��
  �����ָ��������ᵼ�´�����Ϊָ�������һ���ֲ���������û����ԭ���ϲ���

  2.malloc����֮����Ҫ��ָ������жϣ�������о���
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
		cout << "���" << root->ch << "���ͷ���" << endl;
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
	cout << "-----------�������--------------" << endl;
	PreOrder(newTree1);
	cout << endl;
	PreOrder(newTree2);
	cout << endl;
	PreOrder(newTree);
	cout << endl;


	cout << "-----------�������--------------" << endl;
	InOrder(newTree1);
	cout << endl;
	InOrder(newTree2);
	cout << endl;
	InOrder(newTree);
	cout << endl;


	cout << "-----------�������--------------" << endl;;
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