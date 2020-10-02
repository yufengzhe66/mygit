#include<iostream>
using namespace std;
#include<stdlib.h>
#include<algorithm>

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


void PreOrder(struct BinaryNode* root)
{
	if (root)
	{
		cout << root->ch << "  ";
		PreOrder(root->lchild);
		PreOrder(root->rchild);
	}
}


void InOrder(struct BinaryNode* root)
{
	if (root)
	{
		InOrder(root->lchild);
		cout << root->ch << "  ";
		InOrder(root->rchild);
	}
}


void PostOrder(struct BinaryNode* root)
{
	if (root)
	{
		PostOrder(root->lchild);
		PostOrder(root->rchild);
		cout << root->ch << "  ";
	}
}


//计算叶子节点个数
void calculateLeafNum(BinaryNode* root, int& num)
{
	if (root)
	{
		if (root->lchild == NULL && root->rchild == NULL)
		{
			num++;
		}
		else
		{
			calculateLeafNum(root->lchild, num);
			calculateLeafNum(root->rchild, num);
		}
	}
}


int Height(BinaryNode* root)
{
	if (!root)
	{
		return 0;
	}
	else
	{
		return max(Height(root->lchild), Height(root->rchild))+1;
	}
}


void test02()
{
	BinaryNode* root=BuildTree();

	cout << "-----------先序遍历--------------" << endl;
	PreOrder(root);
	cout << endl;
	
	cout << "-----------中序遍历--------------" << endl;
	InOrder(root);
	cout << endl;

	cout << "-----------后序遍历--------------" << endl;;
	PostOrder(root);
	cout << endl;
}


void test03()
{
	BinaryNode* root = BuildTree();
	int num = 0;
	calculateLeafNum(root, num);
	cout << "叶子节点个数为：" << num << endl;
	cout << "树的高度为：" << Height(root) << endl;

}


int main()
{
	test02();
	test03();
	system("pause");
	return 0;
}