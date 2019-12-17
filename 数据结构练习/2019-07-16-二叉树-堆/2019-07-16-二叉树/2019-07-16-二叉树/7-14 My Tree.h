#pragma once

typedef struct Node
{
	int val;
	struct Node *left;
	struct Node *right;
} Node;


//˫������
void toDList(Node *node);
//�������
void inorder(Node *node);
//����������ת��������˫������
Node * searchTreeToDList(Node *root);
//�ǵݹ�ʵ��ǰ�����
void preorderNoR(Node * root);
//�ǵݹ�ʵ���������
void inorderNoR(Node * root);
//�ǵݹ�ʵ�ֺ������
void postorderNoR(Node * root);
//�������
void levelOrder(Node *root);
