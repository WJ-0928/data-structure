#pragma once

typedef struct Node
{
	char value;
	struct Node *left;//ָ���ҵ�����
	struct Node *right;//ָ���ҵ��Һ���
} Node;

// ǰ�����
void preOrderTraversal(Node *root);
// �������
void inOrderTraversal(Node *root);
// �������
void postOrderTraversal(Node *root);
//�������
void getNodeCount(Node *root);
int getNodeCount2(Node *root);
//��������ĸ߶�
int getHeight(Node *root);
//�������Ҷ�ӽ�����
int getLeafCount(Node *root);
//��k�������
int getKLevelCount(Node *root, int k);
//����
Node * find(Node *root, char v);
//�������
void levelOrderTraversal(Node *root);
//�ж��Ƿ�����ȫ������
bool isCompleteTree(Node *root);
//�ж��������Ƿ����
bool isSameTree(Node *p, Node *q);
//�ж��������Ƿ���
bool isMirror(Node *p, Node *q);
//�������
Node * createNode(char ch);

