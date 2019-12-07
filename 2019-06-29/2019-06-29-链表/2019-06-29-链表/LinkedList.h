#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

// ���Ķ���
typedef struct Node {
	int val;			// ����
	struct Node *next;	// ��һ����������
						// �� next == NULL ʱ����ʾû�к��������
						// ������˵�����һ������ next һ�� == NULL
}	Node;

// O(1)
Node * ListPushFront(Node *head, int val) {
	// val ���ڽ���У���װ������
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	// �� node ����һ��Ϊԭ��һ�����
	node->next = head;
	// node ��Ϊ�µĵ�һ�����
	// head = node;
	return node;
}

// O(n)
Node * ListPushBack(Node *head, int val) {
	// 1. װ�������
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	// 2. node �� next ��Ϊ NULL
	node->next = NULL;

	if (head != NULL) {
		// �������н������
		// 3. �ҵ�ԭ���һ�����
		Node *cur = head;
		while (cur->next != NULL) {
			cur = cur->next;
		}
		// cur �������һ�����
		// ��ԭ���һ��������һ��Ϊ node
		cur->next = node;
	}
	else {
		head = node;
	}

	return head;
}

void ListPrint(Node *head) {
	// ��α�������
	for (Node *cur = head; cur != NULL; cur = cur->next) {
		printf("%d --> ", cur->val);
	}
	printf("NULL\n");
}

Node * ListPopFront(Node *head) {
	assert(head != NULL);
	/*
	Node *oldHead = head;
	free(oldHead);
	return head->next;
	*/

	Node *next = head->next;
	free(head);
	return next;
}

Node * ListPopBack(Node *head) {
	assert(head != NULL);
	if (head->next == NULL) {
		free(head);
		head = NULL;
	}
	else {
		// ���ҵ������ڶ������
		Node *cur = head;
		while (cur->next->next != NULL) {
			cur = cur->next;
		}
		// �ͷ� cur->next �Ŀռ�
		// �� cur->next = NULL
		free(cur->next);
		cur->next = NULL;
	}

	return head;
}

void Test() {
	Node *head = NULL;	// ����ĳ�ʼ��

	// ��������ͷ��
	ListPrint(head);
	head = ListPushFront(head, 1);
	ListPrint(head);
	head = ListPushFront(head, 2);
	ListPrint(head);
	head = ListPushFront(head, 3);
	ListPrint(head);
	head = ListPushFront(head, 4);
	ListPrint(head);
	head = ListPushBack(head, 10);
	head = ListPushBack(head, 20);
	head = ListPushBack(head, 30);
	ListPrint(head);


	head = ListPopFront(head);
	head = ListPopFront(head);
	head = ListPopFront(head);
	ListPrint(head);
	head = ListPopBack(head);
	head = ListPopBack(head);
	head = ListPopBack(head);
	head = ListPopBack(head);
	ListPrint(head);

	// ֮ǰ�Ľ���ڴ�й©�ˣ�û���ͷ�
	head = NULL;
	head = ListPushBack(head, 10);
	head = ListPushBack(head, 20);
	ListPrint(head);
	// head ��Ӧ���� NULL ��
	printf("�������\n");
}

#if 0

// �� val ͷ�嵽 head Ϊ��һ������������������
// �����µĵ�һ�����ĵ�ַ
Node * ListPushFront(Node *head, int val) {
	// �Ȱ� val װ�����
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	// �� node ����һ��Ӧ����ԭ���ĵ�һ����㣬Ҳ���� head
	node->next = head;
	// �����µĵ�һ����㣬��������ͨ�����صķ�ʽ����
	return node;
}

// �� val β�嵽 head Ϊ��һ������������������
// �����µĵ�һ�����ĵ�ַ
Node * ListPushBack(Node *head, int val) {
	//  �� val װ�����
	Node *node = (Node *)malloc(sizeof(Node));
	node->val = val;
	node->next = NULL;	// ��Ϊ node һ�������һ����㣬���� node->next == NULL
	// ���������
	if (head == NULL) {
		// ������ԭ��û�н�㣬��ͷ�巽ʽ����
		return node;
	}
	else {
		// ������ԭ���н��
		// ���ҵ�ԭ�������һ�����
		Node *last = head;
		// �ߵ� last->next == NULL ��ʱ��ͣ������last->next == NULL �ʹ��������һ�����
		while (last->next != NULL) {
			last = last->next;
		}
		// �����һ��������һ��Ϊ node
		last->next = node;
		return head;
	}
}

#endif