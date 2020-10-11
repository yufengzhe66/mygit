#include<iostream>
using namespace std;

typedef int KeyType;

typedef struct Node
{
	KeyType key;
	struct Node* left;
	struct Node* right;
}Node,*PNode;

//往二叉树中插入结点（递归方式）
void insertBST(PNode &root, KeyType key)
{
	PNode p = new Node;
	p->key = key;
	p->left = NULL;
	p->right = NULL;

	if (root == NULL)
	{
		root = p;
	}
	else if(key == root->key)
	{
		delete p;
		return;
	}
	else if (key < root->key)
	{
		insertBST(root->left, key);
	}
	else if (key > root->key)
	{
		insertBST(root->right, key);
	}
}


//往二叉树中插入结点（非递归方式）
//费尽心头三升血
void insertBST_NonRecur(PNode& root, KeyType key)
{
	PNode p = new Node;
	p->key = key;
	p->left = NULL;
	p->right = NULL;

	PNode pre= root;
	PNode T = root;
	if (root == NULL)
	{
		root = p;
		return;
	}
	else
	{
		while (T!=NULL)
		{
			if (T->key == key)
			{

				delete p;
				return;
			}
			else if(key<T->key)
			{
				pre = T;
				T = T->left;
			}
			else if (key>T->key)
			{
			    pre = T;
				T = T->right;
			}
			
		}
		if (key < pre->key)
		{
			pre->left = p;
		}
		else if(key > pre->key)
		{
			pre->right = p;
		}
	}

}



void InOrder(PNode T)
{
	if (T == NULL)
		return;
	InOrder(T->left);
	cout << T->key << "  ";
	InOrder(T->right);
}


void PreOrder(PNode T)
{
	if (T == NULL)
		return;
	cout << T->key << "  ";
	PreOrder(T->left);
	PreOrder(T->right);
}


void Create_BST(PNode& T, int arr[], int n)
{
	T = NULL;  // 初始时为空树
	for (int i = 0; i < n; ++i)
		insertBST_NonRecur(T, arr[i]);
}

int main()
{
	int arr[16] = { 3,2,1,4,5,6,7,16,15,14,13,12,11,10,8,9 };
	PNode T = NULL;
	Create_BST(T, arr, 16);
	PreOrder(T);
	cout << endl;
	InOrder(T);
	cout << endl;

	system("pause");
	return 0;
}