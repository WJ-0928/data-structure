#pragma once

// 1. ���

typedef struct DNode {
	int val;
	struct DNode *prev;
	struct DNode *next;
}	DNode;

// 2. ����

typedef struct DList {
	DNode * head;	// ͷ��㣨û����Чֵ��
}	DList;

// ��ʼ��
void DListInit(DList * list) {
	DNode * node = (DNode *)malloc(sizeof(DNode));
	node->val = 0;		// ��������ͷ���� val ���������е���Ч������
	node->next = node;
	node->prev = node;

	list->head = node;
}

void DListPushFront(DList *list, int val) {
	DNode * node = (DNode *)malloc(sizeof(DNode));
	node->val = val;

	node->prev = list->head;
	node->next = list->head->next;
	list->head->next->prev = node;
	list->head->next = node;
}

void DListPushBack(DList *list, int val) {
	DNode * node = (DNode *)malloc(sizeof(DNode));
	node->val = val;

	node->prev = list->head->prev;
	node->next = list->head;
	list->head->prev->next = node;
	list->head->prev = node;
}

void DListInsertAfterPos(Node *pos, int val) {
	DNode * node = (DNode *)malloc(sizeof(DNode));
	node->val = val;

	node->prev = pos;
	node->next = pos->next;
	pos->next->prev = node;
	pos->next = node;
}

void DListInsertBeforePos(Node *pos, int val) {
	DListInsertAfterPos(pos->prev, val);
}

void DListPushFront(DList *list, int val) {
	DListInsertAfterPos(list->head, val);
}

void DListPushBack(DList *list, int val) {
	DListInsertAfterPos(list->head->prev, val);
}