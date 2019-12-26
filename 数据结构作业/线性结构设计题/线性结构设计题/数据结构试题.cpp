#include<iostream>
using namespace std;

#if 0
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
#endif

#if 0
//线性表

#define MAXSIZE 100
typedef struct
{
	int elem[MAXSIZE];
	int last;
}SeqList;

//顺序表查找运算
int Locate(SeqList L, int e)
{
	int i = 0;
	while ((i <= L.last) && (L.elem[i] != e))
	{
		i++;
	}
	if (i <= L.last)
	{
		return (i + 1);
	}
	else
	{
		return -1;
	}
}


//顺序表的插入算法

#define OK 1
#define ERROR 0
int InList(SeqList* L, int i, int e)
{
	int k;
	if ((i < 1) || (i > L->last + 2))
	{
		cout << "插入不合法";
		return ERROR;
	}
	if (L->last >= MAXSIZE - 1)
	{
		cout << "表已满，无法插入";
		return ERROR;
	}
	for (k = L->last; k >= i - 1; k--)
	{
		L->elem[k + 1] = L->elem[k];
	}
	L->elem[i - 1] = e;
	L->last++;
	return OK;
}

//顺序表的删除运算
int DelList(SeqList* L, int i, int e)
{
	int k;
	if (i < 1 || (i > L->last - 1))
	{
		cout << "删除位置不合法";
		return ERROR;
	}
	e = L->elem[i - 1];
	for (k = i; i <= L->last; k++)
	{
		L->elem[k - 1] = L->elem[k];
	}
	L->last--;
	return OK;
}


//线性表的合并运算

void mergeList(SeqList* LA, SeqList* LB, SeqList* LC)
{
	int i, j, k, l;
	i = 0; j = 0; k = 0;
	while (i <= LA->last&&j <= LB->last)
	{
		if (LA->elem[i] <= LB->elem[j])
		{
			LC->elem[k] = LA->elem[i];
			i++;
			k++;
		}
		else
		{
			LC->elem[k] = LB->elem[j];87
			j++;
			k++;
		}
	}
	while (i <= LA->last)
	{
		LC->elem[k] = LA->elem[i];
		i++;
		k++;
	}
	while (j <= LB->last)
	{
		LC->elem[k] = LB->elem[j];
		j++;
		k++;
	}
	LC->last = LA->last + LB->last + 1;
}
#endif

//链式存储

typedef struct Node
{
	int data;
	struct Node* next;
}Node,*LinkList;



#define OK 1
#define ERROR 0
//初始化单链表
void InitList(LinkList* L)
{
	*L = (LinkList)malloc(sizeof(Node));
	(*L)->next = NULL;
}

//用头插法建立单链表
void CreateFromHead(LinkList L)
{
	Node* s;
	char c;
	int flag = 1;
	while (flag)
	{
		c = getchar();
		if (c != '$')
		{
			s = (Node*)malloc(sizeof(Node));
			s->data = c;
			s->next = L->next;
			L->next = s;
		}
		else
		{
			flag = 0;
		}
	}
}


//尾插法建立单链表
void CreateFromTail(LinkList L)
{
	Node* r;
	Node* s;
	char c;
	int flag = 1;
	r = L;
	while (flag)
	{
		c = getchar();
		if (c != '$')
		{
			s = (Node*)malloc(sizeof(Node));
			s->data = c;
			r->next = s; 
			r = s;
		}
		else
		{
			flag = 0;
			r->next = NULL;
		}
	}
}


//在单链表L中查找第i个节点
Node* Get(LinkList L, int i)
{
	int j;
	Node* p;
	if (i <= 0)
		return NULL;
	p = L;
	j = 0;
	while ((p->next != NULL) && (j < i))
	{
		p = p->next;
		j++;
	}
	if (i == j)
	{
		return p;
	}
	else
	{
		return NULL;
	}
}

Node* Locate(LinkList L, int key)
{
	Node* p;
	p = L->next;
	while (p != NULL)
	{
		if (p->data != key)
		{
			p = p->next;
		}
		else
			break;
	}
	return p;
}

//单链表的长度
int ListLength(LinkList L)
{
	Node* p;
	p = L->next;
	int j = 0;
	while (p != NULL)
	{
		p = p->next;
		j++;
	}
	return j;
}

