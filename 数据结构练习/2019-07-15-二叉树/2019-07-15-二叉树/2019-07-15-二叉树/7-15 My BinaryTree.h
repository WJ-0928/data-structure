#pragma once

typedef struct Node
{
	char value;
	struct Node *left;
	struct Node *right;
}Node;


typedef struct ReturnType
{
	int use;// �������������õ���ֵ����
	Node *root;// ���������ĸ��ڵ�
} ReturnType;




//�������Ĺ���������
ReturnType createTree(char preorder[], int size);
//����һ������ǰ����������������
Node *bulidTree1(int *preorder, int preorderSize, int *inorder, int inorderSize);
//����һ�������к���������������
Node *bulidTree2( int *inorder, int *postorder,int size1);
