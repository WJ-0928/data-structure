#include"7-15 My BinaryTree.h"
#include<stdio.h>
#include<stdlib.h>
#include<assert.h>

//�������Ĺ���������

// A B D F # # # # C # E # G # #
// CreateTree ������Ҫ��������ֵ
// 1. Node *	�����
// 2. int		ʹ���˶���ֵ
ReturnType createTree(char preordered[], int size)
{
	char rootvalue = preordered[0];
	if (rootvalue == '#')
	{
		ReturnType returnvalue;
		returnvalue.root = NULL;
		returnvalue.use = 1;
		return returnvalue;
	}
	//ǰ������ĵ�һ��ֵ���Ǹ���ֵ��
	//���ԣ�ȡ��һ��ֵ��������ǰ���ĸ��ڵ�
	Node *root = (Node *)malloc(sizeof(Node));
	root->value = rootvalue;
	//�õݹ��˼·������ǰ����
	//1)������
	//��Ҫ������������ǰ�����ֵ
	ReturnType left = createTree(preordered + 1, size - 1);
    //������
	//��Ҫ������������ǰ�����ֵ
	//��������ǰ�����ֵ����Ҫ�ȼ��㴴���������������õ���ֵ����
	ReturnType right = createTree(preordered + 1 + left.use, size - 1 - left.use);
	root->left = left.root;
	root->right = right.root;
	//�����ú󣬷���
	//1�����������ĸ��ڵ�
	//2)�������������õ��Ľڵ����
	ReturnType returnvalue;
	returnvalue.root = root;
	returnvalue.use = 1 + left.use + right.use;
	return returnvalue;
}


//����һ������ǰ����������������
Node *bulidTree1(int *preorder, int preorderSize, int *inorder, int inorderSize)
{
	if (preorderSize == 0)
	{
		return NULL;
	}
	int size = preorderSize;
	int rootValue = preorder[0];
	Node *root = (Node *)malloc(sizeof(Node));
	root->value = rootValue;
	//�������в���rootValue���ֵ��±꣬��¼��leftSize��
	int leftSize = -1;
	for (int i = 0; i < leftSize; i++)
	{
		if (inorder[i] == rootValue)
		{
			leftSize = i;
			break;
		}
	}
	root->left = bulidTree1(preorder + 1, leftSize, inorder, leftSize);
	root->right = bulidTree1(preorder + 1 + leftSize, size - leftSize - 1, inorder - 1 - leftSize, size - 1 - leftSize);
	return root;
}


//����һ�������к���������������
Node *bulidTree2(int *inorder, int *postorder, int size1)
{
	if (size1 == 0)
	{
		return NULL;
	}
	int rootValue = postorder[size1 - 1];
	Node *root = (Node *)malloc(sizeof(Node));
	root->value = rootValue;
	int leftSize = -1;
	for (int i = 0; i < size1; i++)
	{
		if (inorder[i] == rootValue)
		{
			leftSize = i;
			break;
		}
	}
	root->left = bulidTree2(inorder, postorder, leftSize);
	root->right = bulidTree2(inorder + 1 + leftSize, postorder + leftSize, size1 - 1 - leftSize);
	return root;
}


