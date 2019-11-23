#if 0

#include<iostream>
using namespace std;

//结点
typedef struct Node
{
	int val;
	struct Node* next;
}Node;



//初始化链表
void ListInit(Node *head)
{
	head = NULL;
}

//尾插

void ListpushBack(Node *head, int val)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->val = val;
	node->next = NULL;
	if (head == NULL)
	{
		head = node;
	}
	else
	{
		Node* cur = head;
		while (cur->next != NULL)
		{
			cur = cur->next;
		}
		cur->next = node;
	}
}
//插入
void Insert(Node *head, int num)
{
	Node* node = (Node*)malloc(sizeof(Node));
	node->val = num;
	if (head == NULL)
	{
		node=head;
	}
	else
	{
		int count = 0;
		for (Node *cur = head; cur != NULL; cur = cur->next)
		{
			count++;
		}
		Node* prev = head;
		for (int i = 0; i < count; ++i)
		{
			if (node->val < prev->val)
			{
				node->next = prev;
				prev = prev->next;
				break;
			}
			else
			{
				prev = prev->next;
			}
		}
	}
}

Node *createNode(int val)
{
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	return node;
}
//插入之后的链表
void  Travel_List(Node *head)
{
	for (Node* cur = head; cur != NULL; cur = cur->next)
	{
		cout << cur->val << " ";
		
	}
	cout << endl;
	
}

int main()
{
	Node *n1 = createNode(1);
	Node *n2 = createNode(2);
	Node *n3 = createNode(3);
	Node *n4 = createNode(4);
	Node *n5 = createNode(5);
	Node *n6 = createNode(6);
	Node *n7 = createNode(7);
	Node *n8 = createNode(8);
	Node *n9 = createNode(9);
	Node *n10 = createNode(10);

	n1->next = n2;
	n2->next = n3;
	n3->next = n4;
	n4->next = n5;
	n5->next = n6;
	n6->next = n7;
	n7->next = n8;
	n8->next = n9;
	n9->next = n10;
	n10->next = NULL;

	Travel_List(n1);

	Insert(n1, 11);
	Travel_List(n1);

	Insert(n1, 6);
	Travel_List(n1);

	system("pause");
	return 0;
}
#endif
