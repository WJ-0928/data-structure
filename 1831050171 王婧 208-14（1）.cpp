# if 0

//˳��洢
#include<iostream>
using namespace std;

typedef struct TNode
{
	char data;
	struct TNode* left;
	struct TNode* right;
}Node;

Node* createTree()
{
	Node* node;
	char nodedata;
	cin >> nodedata;
	if (nodedata != '#')
	{
		node = new Node;
		node->data = nodedata;
		node->left=createTree();
		node->right=createTree();
	}
	else
		node = NULL;

	return node;
}


int CountLeaf(Node* node)
{
	static int count = 0;//Ҷ�ӳ�ʼ����ĿΪ0
	if (node == NULL)
	{
		return 0;
	}
	if ( NULL== node->left  && NULL == node->right )
		count++;
	CountLeaf(node->left);
	CountLeaf(node->right);

	return count;
}

int Num(Node* top)
{
	if (top == NULL)
	{
		return 0;
	}
	return Num(top->left) + Num(top->right) + 1;
}
int main()
{
	Node* top = NULL;
	top = createTree();
	cout << "��Ҷ�ӽڵ�ĸ�����" << Num(top) - CountLeaf(top) << endl;

	return 0;
}

#endif

