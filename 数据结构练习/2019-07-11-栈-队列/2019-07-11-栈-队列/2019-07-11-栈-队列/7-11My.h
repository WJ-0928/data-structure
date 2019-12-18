#pragma once

#if 0
//��������
typedef struct CNode
{
	int val;
	struct CNode *next;
	struct CNode *random;
} CNode;
//��ͨ����
typedef struct Node
{
	int val;
	struct Node *next;
}Node;
//����
typedef struct Queue 
{
    Node *front;	// head;
    Node *rear;	    // last;
}Queue;

//ջ
typedef struct Stack
{
	int array[100];//capacity
	int top;//size
}Stack;


//������������
CNode * copy(CNode *head);
//������
Node *createNode(int val);
//ջ��ʼ��
void StackInit(Stack *s);
//ѹջ
void StackPush(Stack *s,int val);
//��ջ
int StackPop(Stack *s);
//�鿴ջ��Ԫ��
int StackTop(Stack *s);
//�鿴ջ�Ĵ�С
int StackSize(Stack *s);
//�ж�ջ�Ƿ�Ϊ��
int StackEmpty(Stack *s);
//���г�ʼ��
void QueueInit(Queue *q);
//���в���
void QueuePush(Queue *q, int val);
//����ɾ��
int QueuePop(Queue *q);
//������Ԫ��
int QueueFront(Queue *q);

//����ƥ������
#endif
typedef struct Stack
{
	int a[100];
	int top;//ջ��
}Stack;
typedef struct Stack
{
	int* _array;
	int _capacity;
	int _top; // ���ջ��λ�� 
}Stack;

// ��ʼ��ջ 
void StackInit(Stack* ps);

// ��ջ 
void StackPush(Stack* ps, int data);

// ��ջ 
void StackPop(Stack* ps);

// ��ȡջ��Ԫ�� 
int StackTop(Stack* ps);

// ��ȡջ����ЧԪ�ظ��� 
int StackSize(Stack* ps);

// ���ջ�Ƿ�Ϊ�գ����Ϊ�շ��ط������������Ϊ�շ���0 
int StackEmpty(Stack* ps);

// ����ջ 
void StackDestroy(Stack* ps);


// ��ʽ�ṹ����ʾ���� 
typedef struct QListNode
{
	struct QListNode* _pNext;
	int _data;
}QNode;

// ���еĽṹ 
typedef struct Queue
{
	QNode* _front;
	QNode* _rear;
}Queue;

// ��ʼ������ 
void QueueInit(Queue* q);

// ��β����� 
void QueuePush(Queue* q, int data);

// ��ͷ������ 
void QueuePop(Queue* q);
// ��ȡ����ͷ��Ԫ�� 
int QueueFront(Queue* q);

// ��ȡ���ж�βԪ�� 
int QueueBack(Queue* q);

// ��ȡ��������ЧԪ�ظ��� 
int QueueSize(Queue* q);

// �������Ƿ�Ϊ�գ����Ϊ�շ��ط�����������ǿշ���0 
int QueueEmpty(Queue* q);

// ���ٶ��� 
void QueueDestroy(Queue* q);


