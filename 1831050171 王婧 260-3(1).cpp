
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

/* ������ȱ��� */

void Depth(MGraph *G, int i)
{
	int j;

	printf("%c\n", G->vexs[i]);   //���ʶ���vi  

	visited[i] = TRUE;

	for (j = 0; j < G->vexnum; j++)           //��������vi�ڽӵ�  
		if (G->edges[i][j] == 1 && !visited[j])
			Depth(G, j);
}

void Depthsearch(MGraph *G)
{

	int i;

	for (i = 0; i < G->vexnum; i++)
		visited[i] = FALSE;

	for (i = 0; i < G->vexnum; i++)
		if (!visited[i])
			Depth(G, i);
}

int main()
{
	MGraph G;
	CreateGraph(&G);
	printf("��������������Ϊ��");
	printf("\n");
	Depthsearch(&G);
	
}

