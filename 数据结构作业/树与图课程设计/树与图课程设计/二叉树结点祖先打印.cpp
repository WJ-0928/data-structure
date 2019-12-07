#if 0
#include<iostream>
#include<string>
using namespace std;

typedef struct TreeNode
{
	string data;
	struct TreeNode* _pLeft;
	struct TreeNode* _pRight;

}Node;


//创建树
void CreateTree(Node* t)
{
	char ch;
	cin >> ch;
	if (ch == '*')
	{
		t = NULL;
	}
	else
	{
		t = new Node;
		t->data = ch;

		CreateTree(t->_pLeft);
		CreateTree(t->_pRight);
	}
}


void findNode(Node* t, string s, int &flag, string first)
{
	if (t == nullptr || flag == 1)
	{
		return;
	}
	else
	{
		findNode(t->_pLeft, s, flag, first);
		findNode(t->_pRight, s, flag, first);
		if (t->data == s)
		{
			flag = 1;
		}
		if (flag == 1 && t->data != s)
		{
			cout << t->data << " ";
		}
	}
}
int main()
{
	Node* t = new Node;
	CreateTree(t);
	string ch;
	cin >> ch;
	if (t->data == ch)
	{
		cout << "没有祖先节点" << endl;
	}
	int flag = 0;
	findNode(t, ch, flag, t->data);
	if (flag == 0)
	{
		cout << ch << "不存在" << endl;
	}
	return 0;
}


//找一个值为x的节点
Node* findnode(Node* T, string s)
{
	if (!T)
	{
		return NULL;
	}
	if (T->data == s)
	{
		return T;
	}
	else
	{
		Node* temp;
		temp = findnode(T->_pLeft, s);
		if (!temp)
		{
			return findnode(T->_pRight, s);
		}
		return temp;
	}
	return NULL;
}


//打印X节点所有父节点
int putRoot(Node* T, string s)
{
	if (!T)
	{
		return 0;
	}
	if (T->data == s)
	{
		return 1;
	}
	if (T)
	{
		if (putRoot(T->_pLeft, s) || putRoot(T->_pRight, s))
		{
			cout << T->data << endl;
			return 1;
		}
	}
	return 0;
}
#endif
#include<iostream>
#include<string>
#include<queue>
using namespace std;

typedef struct node {

	string data;

	node* lChild, *rChild;

}Node;

//创建二叉树
void CreateTree(Node*& t) {
	char ch;
	cin >> ch;
	if (ch == '*') {
		t = NULL;
	}
	else {
		t = new Node;
		t->data = ch;

		CreateTree(t->lChild);
		CreateTree(t->rChild);
	}

}

//在二叉树中找到字符x
void FindItem(Node* t, string Item, int &flag, string first) {

	if (t == NULL || flag == 1) {
		return;
	}
	else {
		FindItem(t->lChild, Item, flag, first);
		FindItem(t->rChild, Item, flag, first);
		if (t->data == Item) {
			flag = 1;
		}
		if (flag == 1 && t->data != Item) {
			cout << t->data << " ";

		}
	}

}


int main() {

	Node* T = new Node;
	CreateTree(T);
	string ch;
	cin >> ch;
	if (T->data == ch) {
		cout << "没有祖先节点" << endl;
		return 0;
	}
	int flag = 0;
	FindItem(T, ch, flag, T->data);
	if (flag == 0) {
		cout << ch << "不存在" << endl;
	}

	return 0;
}
