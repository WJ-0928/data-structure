
#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <malloc.h>
using namespace std;

typedef  struct  Lnode
{
	int  data;
	struct  Lnode  *next;
}Node;

//�����ʼ��
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
	cout<<"�������һ������(��0��ʾ����)��"<<endl;
	cin >> m;
	Node*  fp;
	fp = L;
	while (m != 0)
	{
		//β�巨���£�
		Node*  p = (Node*)malloc(sizeof(Node));
		p->data = m;
		fp->next = p;
		fp = p;
		p->next = NULL;
		cout << "������һ�����֣�" << endl;
		cin>>m;

	}
	return  1;
}

//����Ԫ��
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

//��ӡ����
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
	cout << "����֮ǰ�����У�" << endl;
	Travel_List(L);
	cout<<"������Ҫ���������"<<endl;
	cin >> data;
	Insert_Static_List(L, data);
	cout << "����֮�������:" << endl;
	Travel_List(L);
	system("pause");
	return 0;
}*/
void menu()
{
	printf("***************************************************\n");
	printf("*\t��ӭʹ���������������ϵͳ\t*\n");
	printf("***************************************************\n");
	printf("*\t\t��ѡ�����б�\t\t\t*\n");
	printf("***************************************************\n");
	printf("*\t\t1.����Ԫ��\t\t\t*\n");
	printf("*\t\t2.�鿴����Ԫ��\t\t\t*\n");
	printf("*\t\t0.�˳�ϵͳ\t\t\t*\n");
	printf("***************************************************\n");

}
int main()
{
	menu();
	Node*  L;
	int  data;
	cout << "��������" << endl;
	Create_Init_List(L);
	while (1)
	{
		menu();
		cout << "Ҫ���еĲ���" << endl;
		int n;
		cin >> n;
		switch (n)
		{
		case 1:
			cout << "������Ҫ���������" << endl;
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



