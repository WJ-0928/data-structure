#include"DHCList.h"
#include<assert.h>
#include<malloc.h>
#include<stdio.h>

Node* BuyDHCListNode(DLDataType data)
{
	Node* newNode = (Node*)malloc(sizeof(Node));
	if (NULL == newNode)
	{
		assert(0);
		return NULL;
	}
	newNode->next = NULL;
	newNode->data = data;
	newNode->prev = NULL;
	return newNode;
}
//头结点申请好
Node* DHCListInit()
{
	Node* head = BuyDHCListNode(0);
	head->next = head;
	head->prev = head;
	return head;
}
void DHCListPushBack(Node* head, DLDataType data)
{
	assert(head);
	DHCListInsert(head, data);
}
void DHCListPopBack(Node* head)
{
	assert(head);
	DHCListErase(head->prev);
}
void DHCListPushFront(Node* head, DLDataType data)
{
	assert(head);
	DHCListInsert(head->next, data);
}
void DHCListPopFront(Node* head)
{
	assert(head);
	DHCListErase(head->next);
}

void DHCListInsert(Node* pos, DLDataType data)
{
	if (NULL == pos)
	{
		return;
	}
	//1、现申请新节点
	Node* newNode = BuyDHCListNode(data);
	//2、将新节点链接到原链表
	newNode->next = pos;
	newNode->prev = pos->prev;
	//2、断开链表,插入节点
	pos->prev = newNode;
	newNode->prev->next = newNode;
}
void DHCListErase(Node* pos)
{
	if (NULL == pos)
		return;

	pos->prev->next = pos->next;
	pos->next->prev = pos->prev;
	free(pos);
}

int DHCListSize(Node* head)
{
	assert(head);
	Node* cur = head->next;
	int count = 0;
	while (cur != head)
	{
		count++;
		cur = cur->next;
	}
	return count;
}
int DHCListEmpty(Node* head)
{
	assert(head);
	return head->next == head;
}
Node* DHCListFind(Node* head, DLDataType data)
{
	assert(head);
	Node* cur = head->next;
	while (cur!=head)
	{
		if (cur->data == data)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}
void DHCClear(Node* head)
{
	assert(head);
	Node* cur = head->next;
	while (cur!=head)
	{
		head->next = cur->next;
		free(cur);
		cur = head->next;
	}
	head->next = head;
	head->prev = head;
}
//删除所有头结点及有效节点
void DHCListDestroy(Node** head)
{
	assert(head);
	DHCClear(*head);
	free(*head);
	*head = NULL;
}
void Print(Node* head)
{
	Node* cur = head->next;
	while (cur!=head)
	{
		printf("%d--->", cur->data);
		cur = cur->next;
	}
	printf("NULL\n");
}

void TestDHList()
{
	Node* head = DHCListInit();
	DHCListPushBack(head, 1);
	DHCListPushBack(head, 2);
	DHCListPushBack(head, 3);
	DHCListPushBack(head, 4);
	DHCListPushBack(head, 5);

	Print(head);

	DHCListPushFront(head,0);
	Print(head);

	DHCListPopBack(head);
	DHCListPopFront(head);
	Print(head);

	DHCListInsert(DHCListFind(head, 3), 100);
	Print(head);

	DHCListErase(DHCListFind(head, 3));
	Print(head);
	DHCListDestroy(&head);
}
