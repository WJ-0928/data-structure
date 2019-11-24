#if 0
#include<iostream>
using namespace std;
#define MAXSIZE 20
typedef struct
{
	char data[MAXSIZE];
	int front;
	int rear;
	int tag;//��־����tag=0ʱ�����У�tag=1ʱ����гɹ�
}Queue;
void InitQueue(Queue* Q)//��ʼ������
{
	Q->front = Q->rear = 0;
	Q->tag = 0;
}

int EnQueue(Queue* Q, char n)//�����
{
	if (Q->front == (Q->rear + 1) % MAXSIZE&&Q->tag==1)//βָ���1׷��ͷָ�룬��־�����Ѿ�����
	{
		return 0;
	}
	Q->data[Q->rear] = n;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	Q->tag = 1;
	return 1;//�����ɹ�
}

int DeQueue(Queue* Q, char *x)//������
{
	if(Q->front==Q->rear&&Q->tag==0)//����Ϊ��
	{
		return 0;
	}
	*x = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	Q->tag = 0;
	return 1;//�����ɹ�
}
int main()
{
	Queue Q;
	char x;
	InitQueue(&Q);
	EnQueue(&Q, 'a');
	EnQueue(&Q, 'n');
	EnQueue(&Q, 'm');
	EnQueue(&Q, 'o');
	DeQueue(&Q, &x);
	DeQueue(&Q, &x);
	system("pause");
	return 0;
}
#endif