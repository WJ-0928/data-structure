#define _CRT_SECURE_NO_WARNINGS

#include<iostream>
#include<stdlib.h>
using namespace std;
#define initsize 3
#define increment 3

//结构体定义
typedef struct Node
{
	char name[9];//姓名
	int num;//编号
	int score;//得分
	int tax;//名次
}Node;

typedef struct
{
	Node *data;
	int len;
	int listsize;
}SeqList;

void Init_sq(SeqList *L, int n)
{
	L->data = (Node*)malloc(n * sizeof(Node));
	if (!L->data)
		exit(1);

	L->len = n;
	L->listsize = n;
}

void Init(SeqList *L)
{
	Node* newnode;
	int i, n;
	cout << "请输入选手个数：";
	cin >> n;
	Init_sq(L, n);
	cout << "请输入选手的姓名和编号" << endl;
	printf("姓名\t 编号\t\n");
	if (L->len >= L->listsize)
	{
		newnode = (Node*)realloc(L->data, (L->listsize + increment) * sizeof(Node));
		if (!newnode)
			exit(1);
		L->data = newnode;
		L->listsize += increment;
	}
	for (i = 1; i <= L->len; i++)
	{
		cin >> L->data[i].name >> L->data[i].num;
		L->data[i].score = L->data[i].tax = 0;
	}
}

void Vote(SeqList *L)
{
	int i, num;
	cout << "请输入你要为几号选手投票:(0结束)" << endl;
	do
	{
		cin >> num;
		if (num<0 || num>L->len)
		{
			cout << "你输入的编号错误请重新输入(1--" << L->len << ")" << endl;
			continue;
		}
		else
		{
			for (i = 1; i <= L->len; i++)
			{
				if (L->data[i].num == num)
				{
					L->data[i].score += 1;
				}
			}
		}
	} while (num != 0);
}

void Shellsort(SeqList *L)
{
	int i, j;
	int crement = L->len;
	do
	{
		crement = crement / 3 + 1;
		for (i = crement + 1; i <= L->len; i++)
		{
			if (L->data[i].score > L->data[i - crement].score)
			{
				L->data[0] = L->data[i];
				for (j = i - crement; j > 0 && L->data[0].score > L->data[j].score; j -= crement)
				{
					L->data[j + crement] = L->data[j];
					L->data[j + crement] = L->data[0];
				}
			}
		}
	} while (crement > 1);
}

void count(SeqList* L)
{
	int i;
	L->data[1].tax = 1;
	for (i = 2; i <= L->len; i++)
	{
		if (L->data[i - 1].score == L->data[i].score)
		{
			L->data[i].tax = L->data[i - 1].tax;
		}
		else
		{
			L->data[i].tax = L->data[i - 1].tax + 1;
			
		}
	}
	cout << "正在计算选手名次请稍候" << endl;
    cout << "排序成功" << endl;
}

void Display(SeqList *L)
{
	int i;
	printf("姓名\t 编号\t 票数\t 名次\t\n");
	for (i = 1; i <= L->len; i++)
	{
		printf("%s\t%d\t%d\t%d\t\n", L->data[i].name, L->data[i].num, L->data[i].score, L->data[i].tax);
		
	}
	cout << endl;
}

void Save(SeqList *L)
{
	FILE* fp;
	int i;
	char filename[20];
	cout << "请输入目标文件名:" << endl;
	cin >> filename;

	fp = fopen(filename, "w");
	fprintf(fp, "姓名\t编号\t票数\t名次\n");
	for (i = 1; i <= L->len; i++)
	{
		fprintf(fp, "%s\t%d\t%d\t%d\t\n", L->data[i].name, L->data[i].num, L->data[i].score, L->data[i].tax);	
	}
	fclose(fp);
	cout << "数据已成功保存！" << endl;
}

void Meun()
{
	cout << "************电视大赛观众投票及排名系统*************" << endl;
	cout << "****        1、输入选手信息(姓名、编号)        ****" << endl;
	cout << "****        2、开始投票                        ****" << endl;
	cout << "****        3、排序                            ****" << endl;
	cout << "****        4、查看结果                        ****" << endl;
	cout << "****        5、保存到文件                      ****" << endl;
	cout << "****        6、退出                            ****" << endl;
	cout << "***************************************************" << endl;
}

int main()
{
	int sel;
	SeqList L;
	while (1)
	{
		Meun();
		printf("\n 请输入您要选择的操作序号，按回车键确认：");
		cin >> sel;

		while (sel < 1 || sel>6)
		{
			cout << "输入有误，请重新输入：";
			cin >> sel;
		}
		switch (sel)
		{
		case 1:
			Init(&L);
			break;
		case 2:
			Vote(&L);
			break;
		case 3:
			Shellsort(&L);
			count(&L);
			break;
		case 4:
			Display(&L);
			break;
		case 5:
			Save(&L);
			break;
		case 6:
			cout << "谢谢使用，再见！" << endl;
			exit(0);
			break;
		default:
			break;
		}
	}
}






