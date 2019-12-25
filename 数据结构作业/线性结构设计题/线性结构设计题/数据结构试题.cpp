#include<iostream>
using namespace std;

typedef struct Node
{
	int data;
	struct Node* next;
}Node;

int Count(Node* Head, int x)
{
	int count = 0;
	Node* cur = Head;
	while (cur != NULL)
	{
		if (cur->data == x)
		{
			count++;
		}
		cur = cur->next;
	}
	return count;
}


int length(Node* head)
{
	int count = 0;
	Node* cur = head;
	while (cur != NULL)
	{
		count++;
		cur = cur->next;
	}
	return count;
}

typedef struct Tree
{
	int data;
	struct Tree* left;
	struct Tree* right;
}Tree;

int Height(Tree* Head)
{
	if (Head == NULL)
	{
		return 0;
	}
	else
	{
		int LH = Height(Head->left);
		int RH = Height(Head->right);
		return LH > RH ? (LH + 1) : (RH + 1);
	}
}


void ChangeTree(Tree* Head)
{
	if (Head != NULL)
	{
		Tree* p = Head->left;
		Head->left = Head->right;
		Head->right = p;

		ChangeTree(Head->left);
		ChangeTree(Head->right);
	}
}

#define MAXSIZE 100
typedef struct
{
	int elem[MAXSIZE];
	int last;
}SeqList;

