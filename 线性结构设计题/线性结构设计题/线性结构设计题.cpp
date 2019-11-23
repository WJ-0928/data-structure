
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <malloc.h>
using namespace std;

typedef  struct  Lnode
{
	int  data;
	struct  Lnode  *next;
}Node;

//链表初始化
int Create_Init_List(Node*  &L)
{
	L = (Node*)malloc(sizeof(Node));
	if (!L)  return  -1;
	else
	{
		L->data = 0;
		L->next = NULL;
	}
	int  m;
	cout<<"请输入第一个数字(以0表示结束)："<<endl;
	cin >> m;
	Node*  fp;
	fp = L;
	while (m != 0)
	{
		//尾插法如下：
		Node*  p = (Node*)malloc(sizeof(Node));
		p->data = m;
		fp->next = p;
		fp = p;
		p->next = NULL;
		cout << "请输入一个数字：" << endl;
		cin>>m;

	}
	return  1;
}

//插入元素
void  Insert_Static_List(Node* L, int number)
{
	Node*  p = (Node*)malloc(sizeof(Node));
	
	Node*  q = L->next;
	Node*  fp = L->next;
	int  i = 0;
	while (number > q->data)
	{
		q = q->next;
		i = i + 1;
	}

	if (number <= q->data)
	{
		p->data = number;
		while (i > 1)
		{
			fp = fp->next;
			i--;
		}
		fp->next = p;
		p->next = q;
	}
}

//打印链表
void  Travel_List(Node* L)
{
	Node*  p;
	p = L->next;
	while (p != NULL)
	{
		cout<<p->data<<" ";
		p = p->next;
	}
}
/*
int main()
{
	Node*  L;
	int  data;
	Create_Init_List(L);
	cout << "插入之前的序列：" << endl;
	Travel_List(L);
	cout<<"请输入要插入的数："<<endl;
	cin >> data;
	Insert_Static_List(L, data);
	cout << "插入之后的序列:" << endl;
	Travel_List(L);
	system("pause");
	return 0;
}*/
void menu()
{
	printf("***************************************************\n");
	printf("*\t欢迎使用有序单链表保序插入系统\t*\n");
	printf("***************************************************\n");
	printf("*\t\t请选择功能列表\t\t\t*\n");
	printf("***************************************************\n");
	printf("*\t\t1.插入元素\t\t\t*\n");
	printf("*\t\t2.查看链表元素\t\t\t*\n");
	printf("*\t\t0.退出系统\t\t\t*\n");
	printf("***************************************************\n");

}
int main()
{
	menu();
	Node*  L;
	int  data;
	cout << "输入数据" << endl;
	Create_Init_List(L);
	while (1)
	{
		menu();
		cout << "要进行的操作" << endl;
		int n;
		cin >> n;
		switch (n)
		{
		case 1:
			cout << "请输入要插入的数：" << endl;
			cin >> data;
			Insert_Static_List(L, data);
			break;
		case 2:
			Travel_List(L);
			break;
		case 0:
			exit(0);
		default:
			break;
		}
		cin >> n;
	}
	return 0;

}



