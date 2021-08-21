#pragma once

typedef int DLDataType;
typedef struct DHCListNode
{
	DLDataType data;
	struct DHCListNode* next;//指向当前节点的下一个节点
	struct DHCListNode* prev;//指向当前节点的前一个节点
}Node;

Node* DHCListInit();
void DHCListPushBack(Node* head, DLDataType data);
void DHCListPopBack(Node* head);
void DHCListPushFront(Node* head, DLDataType data);
void DHCListPopFront(Node* head);

void DHCListInsert(Node* pos, DLDataType data);
void DHCListErase(Node* pos);

int DHCListSize(Node* head);
int DHCListEmpty(Node* head);
Node* DHCListFind(Node* head, DLDataType data);
void DHCClear(Node* head);
void DHCListDestroy(Node** head);

void TestDHList();
