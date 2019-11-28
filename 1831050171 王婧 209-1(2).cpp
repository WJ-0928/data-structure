#if 0
//非递归

#include<iostream>
#include<stack>
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
	Node * cur = node;
	std::stack<Node *> st;
	while (cur != NULL || !st.empty())
	{
		while (cur != NULL)
		{
			cout<<cur->data<<" ";
			st.push(cur);
			cur = cur->left;
		}
		Node *top = st.top();
		st.pop();
		cur = top->right;
	}

}

void inOrder(Node* node)
{
	Node * cur = node;
	std::stack<Node *> st;
	while (cur != NULL || !st.empty())
	{
		while (cur != NULL)
		{
			st.push(cur);
			cur = cur->left;
		}
		Node *top = st.top();
		cout << top->data << " ";
		st.pop();
		cur = top->right;
	}

}


void posOrder(Node* node)
{
	Node *cur = node;
	Node *last = NULL;

	std::stack<Node *> st;
	while (cur != NULL || !st.empty())
	{
		while (cur != NULL)
		{
			st.push(cur);
			cur = cur->left;
		}
		Node *top = st.top();
		if (top->right == NULL || top->right == last)
		{
			st.pop();
			cout << top->data << " ";
			last = top;
		}
		else
		{
			cur = top->right;
		}
	}
}

int main()
{
	Node* root;
	createTree(&root);

	cout << "先序遍历" << endl;
	preOrder(root);
	cout << endl;

	cout << "中序遍历" << endl;
	inOrder(root);
	cout << endl;

	cout << "后序遍历" << endl;
	posOrder(root);
	cout << endl;
}

#endif
