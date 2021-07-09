#include"BinaryTree.h"
#include<stdio.h>
#include<malloc.h>
#include<assert.h>
#include<queue>
BTNode* BuyBinTreeNode(BTDataType data)
{
	BTNode* newNode = (BTNode*)malloc(sizeof(BTNode));
	if (newNode == NULL)
	{
		assert(0);
		return NULL;
	}
	newNode->data = data;
	newNode->left = NULL;
	newNode->right = NULL;
	return newNode;
}

BTNode* CreateBinaryTree()
{
	BTNode* root = NULL;
	BTNode* n1 = BuyBinTreeNode(1);
	BTNode* n2 = BuyBinTreeNode(2);
	BTNode* n3 = BuyBinTreeNode(3);
	BTNode* n4 = BuyBinTreeNode(4);
	BTNode* n5 = BuyBinTreeNode(5);
	BTNode* n6 = BuyBinTreeNode(6);
	BTNode* n7 = BuyBinTreeNode(7);

	root = n1;
	root->left = n2;
	n2->left = n3;
	n2->right = n7;

	root->right = n4;
	n4->left = n5;
	n4->right = n6;
	return root;
}
BTNode* CreateBinaryTree(int array[], int size,int* index,int invalid)
{
	BTNode* root = NULL;
	if ((*index < size)&&array[*index]!=invalid)
	{
		root = BuyBinTreeNode(array[*index]);
		++(*index);
		root->left = CreateBinaryTree(array, size, index, invalid);
		++(*index);
		root->right = CreateBinaryTree(array, size, index, invalid);
	}
	return root;
}
BTNode* CopyBinTree(BTNode* root)
{
	BTNode* newroot = NULL;
	if (root)
	{
		newroot = BuyBinTreeNode(root->data);
		newroot->left = CopyBinTree(root->left);
		newroot->right = CopyBinTree(root->right);
	}
	return newroot;
}
// 遍历
void PrevOrder(BTNode* root)
{
	if (NULL == root)
		return;
	printf("%d ", root->data);
	PrevOrder(root->left);
	PrevOrder(root->right);

}
void InOrder(BTNode* root)
{
	if (NULL == root)
		return;
	InOrder(root->left);
	printf("%d ", root->data);
	InOrder(root->right);
}
void PostOrder(BTNode* root)
{
	if (NULL == root)
		return;
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d ", root->data);
}
void LevelOrder(BTNode* root)
{
	if (root == NULL)
		return;
	std::queue<BTNode*> q;
	q.push(root);
	while (!q.empty())
	{
		BTNode* cur = q.front();
		q.pop();
		printf("%d ", cur->data);
		if (cur->left )
		{
			q.push(cur->left);
		}
		if (cur->right)
		{
			q.push(cur->right);
		}
	}
}
//获取二叉树中节点的个数
int BinaryTreeSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	return BinaryTreeSize(root->left) + BinaryTreeSize(root->right) + 1;
	
}
//获取二叉树中叶子节点的个数
int BinaryTreeLeafSize(BTNode* root)
{
	if (root == NULL)
		return 0;
	else if (root->left == NULL && root->right == NULL)
		return 1;
	else
		return BinaryTreeLeafSize(root->left) + BinaryTreeLeafSize(root->right);
}
//获取二叉树中第k层节点的个数
int BinaryTreeLevelKSize(BTNode* root, int k)
{
	if (root == NULL || k == 0)
	{
		return 0;
	}
	if (1 == k)
		return 1;
	return BinaryTreeLevelKSize(root->left, k - 1) + BinaryTreeLevelKSize(root->right, k - 1);
}
//找data节点
BTNode* BinaryTreeFind(BTNode* root, BTDataType x)
{
	if (root == NULL)
		return NULL;
	if (root->data == x)
		return root;
	BTNode* ret = NULL;
	(ret= BinaryTreeFind(root->left, x) )||(ret= BinaryTreeFind(root->right, x));
	return ret;
}
int GetHeight(BTNode* root)
{
	if (root == NULL)
		return 0;
	int left = GetHeight(root->left);
	int right = GetHeight(root->right);
	return left > right ? left + 1 : right + 1;
}

// 判断二叉树是否是完全二叉树
int BinaryTreeComplete(BTNode* root)
{
	std::queue<BTNode*> q;
	int flag=0;
	//空树也是完全二叉树
	if (root == NULL)
		return 1;

	//非空
	//1、按照层序遍历规则找第一个不饱和的节点
	q.push(root);
	while (!q.empty())
	{
		BTNode* cur = q.front();
		if (flag)
		{
			//后续的节点不能有孩子
			if (cur->left || cur->right)
				return 0;
		}
		else
		{
			//找第一个不饱和的节点
			if (cur->left && cur->right)
			{
				q.push(cur->left);
				q.push(cur->right);
			}
			else if (cur->left)
			{
				//cur只有左孩子
				q.push(cur->left);
				flag = 1;
			}
			else if (cur->right)
			{
				//只有右孩子
				return 0;
			}
			else
			{
				flag = 1;
			}
			
		}
		q.pop();
	}
	return 1;
}
void BinaryTreeDestory(BTNode** root)
{
	assert(root);
	if (*root)
	{
		BinaryTreeDestory(&(*root)->left);
		BinaryTreeDestory(&(*root)->right);
		free(*root);
		*root = NULL;
	}
}
void TestBinTree()
{
	int array[] = {1,2,3,-1,-1,-1,4,5,-1,-1,6};
	int index = 0;
	BTNode* root = CreateBinaryTree(array, sizeof(array) / sizeof(array[0]), &index,-1);
	BTNode* newroot = NULL;
	PrevOrder(root);
	printf("\n");
	InOrder(root);
	printf("\n");
	PostOrder(root);
	printf("\n");
	LevelOrder(root);
	printf("\n");

	printf("%d\n",BinaryTreeSize(root));
	printf("%d\n", BinaryTreeLeafSize(root));
	printf("%d\n", BinaryTreeLevelKSize(root,3));

	BTNode* cur = BinaryTreeFind(root, 5);
	if (cur == NULL)
		printf("no\n");
	else\
		printf("yes\n");

	printf("%d\n", GetHeight(root));
	if (BinaryTreeComplete(root))
		printf("yes\n");
	else
		printf("no\n");
	newroot = CopyBinTree(root);
	PrevOrder(newroot);
	printf("\n");
	InOrder(newroot);
	printf("\n");
	PostOrder(newroot);
	printf("\n");
	LevelOrder(newroot);
	printf("\n");
	BinaryTreeDestory(&root);
	
	
}