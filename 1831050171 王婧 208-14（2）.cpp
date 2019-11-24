#if 0
//非顺序存储（链式存储）
#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>

typedef struct node {
	char data;
	struct node * lchild;
	struct node * rchild;
}BiTree;

BiTree * CreatTree() {

	BiTree *t;
	char ch;
	ch = getchar();
	if (ch != '#') {
		t = (BiTree *)malloc(sizeof(BiTree));
		t->data = ch;
		t->lchild = CreatTree();
		t->rchild = CreatTree();
	}
	else {
		t = NULL;
	}
	return t;
}
int Count(BiTree * top) {
	if (top == NULL) {
		return 0;
	}
	else if ((top->lchild == NULL) && (top->rchild == NULL)) {
		return 1;
	}
	else {
		return Count(top->lchild) + Count(top->rchild);
	}
}
int Num(BiTree* top)
{
	if (top == NULL)
	{
		return 0;
	}
	return Num(top->lchild) + Num(top->rchild) + 1;
}

int main() {
	BiTree * top = NULL;
	top = CreatTree();
	printf("非叶子节点的个数： %d\n",Num(top)-Count(top));

	system("pause");
	return 0;
}
# endif




