#if 0

//�ݹ�
#include<iostream>
using namespace std;

typedef struct TNode
{
	char data;
	struct TNode* left;
	struct TNode* right;
}Node;

void createTree(Node **node)
{
	char nodedata;
	cin >> nodedata;
	if (nodedata != '#')
	{
		*node = (Node*)malloc(sizeof(Node));
		(*node)->data = nodedata;
		createTree(&((*node)->left));
		createTree(&((*node)->right));
	}
	else
		*node = NULL;
}

void preOrder(Node* node)
{
	if (node != NULL)
	{
		cout << node->data << " ";
		preOrder(node->left);
		preOrder(node->right);
	}
}

void inOrder(Node* node)
{
	if (node != NULL)
	{
		inOrder(node->left);
		cout << node->data << " ";
		inOrder(node->right);
	}
}


void posOrder(Node* node)
{
	if (node != NULL)
	{
		posOrder(node->left);
		posOrder(node->right);
		cout << node->data << " ";
	}
}

int main()
{
	Node* root;
	createTree(&root);

	cout << "�������" << endl;
	preOrder(root);
	cout << endl;

	cout << "�������" << endl;
	inOrder(root);
	cout << endl;

	cout << "�������" << endl;
	posOrder(root);
	cout << endl;
}

#endif