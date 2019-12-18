#include"7-14 My  Binary Tree.h"

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
#include <queue>


// ǰ�����
void preOrderTraversal(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	//��
	printf("%c", root->value);
	//��������ǰ�����
	preOrderTraversal(root->left);
	//��������ǰ�����
	preOrderTraversal(root->right);
}


// �������
void inOrderTraversal(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	//��������ǰ�����
	inOrderTraversal(root->left);
	//��
	printf("%c", root->value);
	//��������ǰ�����
	inOrderTraversal(root->right);
}


// �������
void postOrderTraversal(Node *root)
{
	if (root == NULL)
	{
		return;
	}
	//��������ǰ�����
	postOrderTraversal(root->left);
	//��������ǰ�����
	postOrderTraversal(root->right);
	//��
	printf("%c", root->value);
}


//�������
void getNodeCount(Node *root)
{
	int count = 0;
	if (root == NULL)
	{
		return ;
	}
	getNodeCount(root->left);
	count++;
	getNodeCount(root->right);
}


int getNodeCount2(Node *root)
{
	if (root == NULL)
	{
		return 0;
	}
	int left = getNodeCount2(root->left);
	int right = getNodeCount2(root->right);
	return left + right + 1;
}


//��������ĸ߶�
int getHeight(Node *root)
{
	if (root == NULL)
	{
		return 0;
	}
	int left = getHeight(root->left);
	int right = getHeight(root->right);
	return (left > right ? left : right) + 1;
}


//�������Ҷ�ӽ�����
int getLeafCount(Node *root)
{
	if (root == NULL)
	{
		return 0;
	}
	else if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	else
	{
		return getLeafCount(root->left) + getLeafCount(root->right);
	}
}
//��k�������
int getKLevelCount(Node *root, int k)
{
	assert(k >= 1);
	if (root == NULL)
	{
		return 0;
	}
	else if (k == 1)
	{
		return 1;
	}
	else
	{
		return getKLevelCount(root->left, k - 1) + getKLevelCount(root->right, k - 1);
	}

}
//����
/*
����ҵ������ؽ���ַ�����򷵻�NULL
(�������NULL����ʾû���ҵ���������ط�NULL����ʾ�ҵ���
1��������û�ҵ�
2�����������v�����ظ��ĵ�ַ������
3��ȥ���������ң�������������ҵ������ؽ���ַ
4������ȥ��������
*/
Node * find(Node *root, char v)
{
	if (root == NULL)
	{
		return NULL;
	}
	if (root->value == v)
	{
		return root;
	}
	Node *left = find(root->left, v);
	if (left != NULL)
	{
		return left;
	}
	Node *right = find(root->right, v);
	if (right != NULL)
	{
		return right;
	}
	else
	{
		return NULL;
	}
}
//�������
void levelOrderTraversal(Node *root)
{
	if (root == NULL) {
		return;
	}
	std::queue<Node *>	q;
	q.push(root);

	while (!q.empty()) {
		Node * front = q.front(); q.pop();

		printf("%c ", front->value);

		if (front->left != NULL) {
			q.push(front->left);
		}

		if (front->right != NULL) {
			q.push(front->right);
		}
	}
}

//�ж��Ƿ�����ȫ������
bool isCompleteTree(Node *root)
{
	if (root == NULL) {
		return true;
	}

	std::queue<Node *> q;
	q.push(root);

	while (true) {
		Node * front = q.front(); q.pop();
		if (front == NULL) {
			break;
		}

		q.push(front->left);
		q.push(front->right);
	}

	while (!q.empty()) {
		Node * front = q.front(); q.pop();
		if (front != NULL) {
			return false;
		}
	}

	return true;
}


//�ж��������Ƿ����
bool isSameTree(Node *p, Node *q)
{
	if (p == NULL && q == NULL)
	{
		return true;
	}
	if (p == NULL || q == NULL)
	{
		return false;
	}
	return p->value == q->value
		&&isSameTree(p->left, q->left)
		&& isSameTree(p->right, q->right);
}
//�ж��������Ƿ���
bool isMirror(Node *p, Node *q)
{
	if (p == NULL && q == NULL)
	{
		return true;
	}
	if (p == NULL || q == NULL)
	{
		return false;
	}
	return p->value == q->value
		&&isMirror(p->left, q->right)
		&& isMirror(p->right, q->left);
}

//�������
Node * createNode(char ch)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->value = ch;
	node->left = node->right = NULL;

	return node;
}
