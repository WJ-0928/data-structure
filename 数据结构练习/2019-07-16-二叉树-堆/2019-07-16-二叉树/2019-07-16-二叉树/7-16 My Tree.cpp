#include"7-14 My Tree.h"
#include<stdio.h>
#include<stdlib.h>
#include <stack>
#include<queue>

//����������
//������������һ�����
//��֤�ýڵ������������е�ֵ��С�ڸýڵ��ֵ
//��֤�ýڵ������������е�ֵ�����ڸýڵ��ֵ
Node *head = NULL;
Node *prev = NULL;
//˫������
void toDList(Node *node)
{
	node->left = prev;
	if (prev == NULL) {
		head = node;
	}
	else {
		prev->right = node;
	}

	prev = node;
}
//�������
void inorder(Node *node)
{
	if (node == NULL) {
		return;
	}

	inorder(node->left);
	toDList(node);
	inorder(node->right);
}
//����������ת��������˫������
Node * searchTreeToDList(Node *root)
{
	head = NULL; prev = NULL;
	inorder(root);

	return head;
}
//�ǵݹ�ʵ��ǰ�����
void preorderNoR(Node * root)
{
	Node *cur = root;
	std::stack<Node *> st;

	while (cur != NULL || !st.empty())
	{
		while (cur != NULL)
		{
			printf("%d", cur->val);
			st.push(cur);
			cur = cur->left;
		}

		Node *top = st.top();
		st.pop();

		cur = top->right;
	}
}
//�ǵݹ�ʵ���������
void inorderNoR(Node * root)
{
	Node *cur = root;
	std::stack<Node *> st;

	while (cur != NULL || !st.empty())
	{
		while (cur != NULL)
		{
			
			st.push(cur);
			cur = cur->left;
		}

		Node *top = st.top();
		printf("%d", top->val);
		st.pop();

		cur = top->right;
	}
}
//�ǵݹ�ʵ�ֺ������
void postorderNoR(Node * root)
{
	Node *cur = root;
	Node *last = NULL;

	std::stack<Node *> st;

	while (cur != NULL || !st.empty())
	{
		while (cur != NULL)
		{
			st.push(cur);
			cur = cur->left;
		}

		Node *top = st.top();
		if (top->right == NULL || top->right == last)
		{
			st.pop();
			printf("%d", top->val);
			last = top;
		}
		else
		{
             cur = top->right;
		}
		
	}
}
//�������
void levelOrder(Node *root)
{
	if (root == NULL) {
		return;
	}

	std::queue<Node *> q;
	q.push(root);

	while (!q.empty()) {
		// Node * front = QueueFront(&q); QueuePop(&q);
		Node * front = q.front();	q.pop();

		printf("%d ", front->val);
		if (front->left != NULL) {
			q.push(front->left);
		}
		if (front->right != NULL) {
			q.push(front->right);
		}
	}
}
