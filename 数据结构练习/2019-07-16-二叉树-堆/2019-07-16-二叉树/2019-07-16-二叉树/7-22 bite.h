#pragma once

typedef struct Node
{
	int val;
	struct Node *left;
	struct Node *right;
} Node;

typedef struct ReturnType
{
	int use;// �������������õ���ֵ����
	Node *root;// ���������ĸ��ڵ�
} ReturnType;

//Ҫ��:
//1. ��Ϥ���ĸ����Լ���ظ���
//2. �˽����Ĵ洢��ʽ�Լ�������
//3. �˽�����Ӧ�ó���
//4. ��Ϥ�������Ļ��������Լ�����
//5. ��Ϥ������������ȫ��������������������
//6. ��Ϥ�������ľ�̬�洢����ʽ�洢
//7. ʵ����ʽ���ݽṹ�����»���������



//�������Ĺ���������
ReturnType createTree(char preordered[], int size);

// ���������� 
Node* CopyBinTree(Node* pRoot);

// ���ٶ����� 
void DestroyBinTree(Node* pRoot);
// �����������ֱ�����ʽ 
void PreOrder(Node* pRoot);
void PreOrderNor(Node* pRoot);
void InOrder(Node* pRoot);
void InOrderNor(Node* pRoot);
void PostOrder(Node* pRoot);
void PostOrderNor(Node* pRoot);
void LevelOrder(Node* pRoot);

// ��ȡ�������нڵ�ĸ��� 
int GetNodeCount(Node* pRoot);

// ��������ĸ߶� 
int Height(Node* pRoot);

// ���������Ƿ�ƽ��O(N^2) 
int IsBalanceTree(Node* pRoot);
// ���������Ƿ�ƽ��O(N) 
int IsBalanceTree_P(Node* pRoot, int* height);

// ��ȡ��������Ҷ�ӽڵ�ĸ��� 
int GetLeafNodeCount(Node* pRoot);

// ��ȡ��������K��ڵ�ĸ��� 
int GetKLevelNodeCount(Node* pRoot, int K);

// ��ȡ��������ĳ���ڵ��˫�׽ڵ� 
Node* GetNodeParent(Node* pRoot, Node* pNode);

// ��������ľ��� 
void Mirror(Node* pRoot);


