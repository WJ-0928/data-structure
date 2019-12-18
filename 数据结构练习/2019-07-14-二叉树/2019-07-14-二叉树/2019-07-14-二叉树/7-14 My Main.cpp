#include"7-14 My  Binary Tree.h"
#include<stdio.h>

void test()
{
	Node *a = createNode('A');
	Node *b = createNode('B');
	Node *c = createNode('C');
	Node *d = createNode('D');
	Node *e = createNode('E');
	Node *f = createNode('F');
	Node *g = createNode('G');
	Node *h = createNode('H');


	a->left = b; a->right = c;
	b->left = d; b->right = e;
	c->left = f; c->right = g;
	d->left = NULL; d->right = NULL;
	e->left = NULL; e->right = h; 
	f->left = NULL; f->right = NULL;

	preOrderTraversal(a); printf("\n");
	inOrderTraversal(a); printf("\n");
	postOrderTraversal(a); printf("\n");

	int count = 0; getNodeCount(a);
	printf("��������%d\n",count);

	printf("������2: %d\n", getNodeCount2(a));
	printf("���ĸ߶ȣ�%d\n", getHeight(a));
	printf("Ҷ�ӽ�������%d\n", getLeafCount(a));

	printf("��һ��Ľ�������%d\n", getKLevelCount(a, 1));
	printf("�ڶ���Ľ�������%d\n", getKLevelCount(a, 2));
	printf("������Ľ�������%d\n", getKLevelCount(a, 3));
	printf("���Ĳ�Ľ�������%d\n", getKLevelCount(a, 4));
	printf("�����Ľ�������%d\n", getKLevelCount(a, 5));

	printf("���������"); levelOrderTraversal(a); printf("\n");

	if (isCompleteTree(a)) {
		printf("A ����ȫ������\n");
	}
	else {
		printf("A ������ȫ������\n");
	}

	if (isCompleteTree(c)) {
		printf("C ����ȫ������\n");
	}
	else {
		printf("C ������ȫ������\n");
	}
}


int main() {
	test();
}