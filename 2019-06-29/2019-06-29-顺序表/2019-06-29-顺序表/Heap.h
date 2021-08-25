#pragma once
typedef int HDataType;

int Less(HDataType left, HDataType right);
int Greater(HDataType left, HDataType right);

//函数指针变量:可以指向任何有两个HDataType参数以及一个int类型返回值得所有函数
//cmp势函数指针变量，Cmp可以指向Less，也可以指向Greater
//Cmp的类型：int(*)(HDataType,HDataType)

static int (*Cmp)(HDataType left, HDataType right);
typedef int(*CMP)(HDataType, HDataType);

typedef struct Heap
{
	HDataType* array;
	int capacity;
	int size;
	CMP Cmp;//函数指针变量
}Heap;

void HeapInit(Heap* hp,int initCap,CMP cmp);
void HeapCreate(Heap* hp, int* array, int size, CMP cmp);
void HeapPush(Heap* hp, HDataType* data);
void HeapPop(Heap* hp);
HDataType HeapTop(Heap* hp);
int HeapEmpty(Heap* hp);
int HeapSize(Heap* hp);
void HeapDestroy(Heap* hp);

void Swap(HDataType* left, HDataType* right);
void TestHeap();