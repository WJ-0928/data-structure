#if 0
#include<iostream>
using namespace std;
#define MAXSIZE 20
typedef struct
{
	char data[MAXSIZE];
	int front;
	int rear;
	int tag;//标志量：tag=0时出队列，tag=1时入队列成功
}Queue;
void InitQueue(Queue* Q)//初始化队列
{
	Q->front = Q->rear = 0;
	Q->tag = 0;
}

int EnQueue(Queue* Q, char n)//入队列
{
	if (Q->front == (Q->rear + 1) % MAXSIZE&&Q->tag==1)//尾指针加1追上头指针，标志队列已经满了
	{
		return 0;
	}
	Q->data[Q->rear] = n;
	Q->rear = (Q->rear + 1) % MAXSIZE;
	Q->tag = 1;
	return 1;//操作成功
}

int DeQueue(Queue* Q, char *x)//出队列
{
	if(Q->front==Q->rear&&Q->tag==0)//队列为空
	{
		return 0;
	}
	*x = Q->data[Q->front];
	Q->front = (Q->front + 1) % MAXSIZE;
	Q->tag = 0;
	return 1;//操作成功
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