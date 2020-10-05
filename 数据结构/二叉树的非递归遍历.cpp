#include<iostream>
using namespace std;
#include<stdlib.h>
#include<algorithm>
#include<stack>

struct BinaryNode
{
	char ch;
	struct BinaryNode* lchild;
	struct BinaryNode* rchild;
};

BinaryNode* BuildTree()
{
	static struct BinaryNode nodeA = { 'A', NULL, NULL };
	static struct BinaryNode nodeB = { 'B', NULL, NULL };
	static struct BinaryNode nodeC = { 'C', NULL, NULL };
	static struct BinaryNode nodeD = { 'D', NULL, NULL };
	static struct BinaryNode nodeE = { 'E', NULL, NULL };
	static struct BinaryNode nodeF = { 'F', NULL, NULL };
	static struct BinaryNode nodeG = { 'G', NULL, NULL };
	static struct BinaryNode nodeH = { 'H', NULL, NULL };

	nodeA.lchild = &nodeB;
	nodeA.rchild = &nodeF;

	nodeB.rchild = &nodeC;

	nodeC.lchild = &nodeD;
	nodeC.rchild = &nodeE;

	nodeF.rchild = &nodeG;

	nodeG.lchild = &nodeH;
	return &nodeA;
}

void PreOrder(BinaryNode* root)
{
	stack<BinaryNode*> s;
	BinaryNode* p = root;

	while (p||!s.empty())
	{
		if (p)
		{
			s.push(p);
			cout << p->ch << "  ";
			p = p->lchild;
		}
		else
		{
			p = s.top();
			s.pop();
			p = p->rchild;
		}
	}
	cout << endl;
}


void InOrder(BinaryNode* root)
{
	stack<BinaryNode*> s;
	BinaryNode* p = root;

	while (p || !s.empty())
	{
		if (p)
		{
			s.push(p);
			p = p->lchild;
		}
		else
		{
			p = s.top();
			s.pop();
			cout << p->ch << "  ";
			p = p->rchild;
		}
	}
	cout << endl;
}


void PostOrder(BinaryNode* root)
{
	stack<BinaryNode*> s;
	BinaryNode* p = root;
	BinaryNode* pre = NULL;
	while (p || !s.empty())
	{
		if (p)
		{
			s.push(p);
			p = p->lchild;
		}
		else
		{
			p = s.top();
			if (pre == p->rchild || p->rchild == NULL)
			{
				s.pop();
				cout << p->ch << "  ";
				pre = p;
				p = NULL;
			}
			else
			{
				p = p->rchild;
			}
		}
	}
	cout << endl;
}



void test01()
{
	BinaryNode* root = BuildTree();
	cout << "---------先序遍历------------" << endl;
	PreOrder(root);
	cout << "---------中序遍历------------" << endl;
	InOrder(root);
	cout << "---------后序遍历------------" << endl;
	PostOrder(root);
}

int main()
{
	test01();
	return 0;
}