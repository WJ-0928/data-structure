#include<stdio.h>
#include<stdlib.h>

typedef struct Node
{
	int val;
	struct Node *next;
}Node;

Node *createNode(int val)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	return node;
}

void deletenode(Node* b)
{
	Node* cur = b;
	Node* newnode = NULL;
	while (1)
	{
		if (cur->next == b)
		{
			newnode = cur;
			break;
		}
		cur = cur->next;
	}
	cur = b;
	while (cur->next!=newnode)
	{
		cur = cur->next;
	}
	cur->next = b;

}

int main()
{
	Node *n1 = createNode(1);
	Node *n2 = createNode(2);
	Node *n3 = createNode(3);
	Node *n4 = createNode(4);
	Node *n5 = createNode(5);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n1;

	Node* s = n1;
	deletenode(s);
	return 0;
}
