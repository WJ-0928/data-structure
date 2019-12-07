#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>  
#define MaxVertexNum 50  
#define QueueSize 50  

typedef enum { FALSE, TRUE }shifou;
shifou visited[MaxVertexNum];

typedef char VertexType;   //�������ַ���
typedef int EdgeType;   //��������

typedef struct    //ͼ���ڽӾ���洢�ṹ
{

	VertexType vexs[MaxVertexNum];  //��������  

	EdgeType edges[MaxVertexNum][MaxVertexNum];     //�ڽӾ���  

	int vexnum, arcnum;    //ͼ�е�ǰ�Ķ������ͱ���  

}MGraph;

/* �ڽӾ���Ľ���*/

void CreateGraph(MGraph *G)
{
	int i, j, k;
	char ch1, ch2;

	printf("�����붥�����ͱ���(�����ʽΪ:������,����):");

	scanf("%d,%d", &(G->vexnum), &(G->arcnum));

	printf("�����붥������(�����ʽΪ:a,b,c...)��");

	for (i = 0; i < G->vexnum; i++)
	{
		getchar();
		scanf("%c", &(G->vexs[i]));
	}

	for (i = 0; i < G->vexnum; i++)
		for (j = 0; j < G->vexnum; j++)
			G->edges[i][j] = 0;

	printf("������ÿ���߶�Ӧ��������������(�����ʽΪ:a,b):\n");

	for (k = 0; k < G->arcnum; k++)
	{
		getchar();
		printf("�������%d���ߵ������������ƣ�", k + 1);
		scanf("%c,%c", &ch1, &ch2);
		for (i = 0; ch1 != G->vexs[i]; i++);
		for (j = 0; ch2 != G->vexs[j]; j++);
		G->edges[j][i] = 1;
		G->edges[i][j] = 1;
	}
}

/*������ȱ���*/

typedef struct
{
	int front;
	int rear;
	int count;
	int data[QueueSize];
}AQueue;

void InitQueue(AQueue *Q)
{
	Q->front = Q->rear = 0;
	Q->count = 0;
}

int QueueEmpty(AQueue *Q)
{
	return Q->count != QueueSize;

}

int QueueFull(AQueue *Q)
{
	return Q->count == QueueSize;
}

void EnQueue(AQueue *Q, int x)
{

	if (QueueFull(Q))
		printf("Queue overflow");
	else
	{
		Q->count++;
		Q->data[Q->rear] = x;
		Q->rear = (Q->rear + 1) % QueueSize;
	}
}

int DeQueue(AQueue *Q)
{
	int temp;
	if (QueueEmpty(Q))
	{
		printf("Queue underflow");
		return 0;
	}
	else
	{
		temp = Q->data[Q->front];
		Q->count--;
		Q->front = (Q->front + 1) % QueueSize;
		return temp;
	}
}

void Breadth(MGraph *G, int k)
{
	int i, j;
	AQueue Q;
	InitQueue(&Q);
	printf("%c\n", G->vexs[k]);
	visited[k] = TRUE;
	EnQueue(&Q, k);
	while (!QueueEmpty(&Q))
	{
		i = DeQueue(&Q);
		for (j = 0; j < G->vexnum; j++)
			if (G->edges[i][j] == 1 && !visited[j])
			{
				printf("%c\n", G->vexs[j]);
				visited[j] = TRUE;
				EnQueue(&Q, j);
			}
	}
}

void Breadthsearch(MGraph *G)
{
	int i;
	for (i = 0; i < G->vexnum; i++)
		visited[i] = FALSE;
	for (i = 0; i < G->vexnum; i++)
		if (!visited[i])
			Breadth(G, i);
}

int  main()
{
	MGraph G;
	CreateGraph(&G);
	printf("��������������Ϊ��");
	printf("\n");
	Breadthsearch(&G);
}

