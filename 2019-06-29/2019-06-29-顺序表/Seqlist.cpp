#include "Seqlist.h"
#include<assert.h>
#include<malloc.h>
#include<stdio.h>
//初始化
void  SeqListInit(Seqlist* s, int initcapacity)
{
	assert(s);
	initcapacity = initcapacity <= 3 ? 3 : initcapacity;
	s->array = (SDataType*)malloc(sizeof(SDataType*) * initcapacity);
	if (NULL == s->array)
		return;

	s->capacity = initcapacity;
	s->size = 0;
}
//扩容
// 1、开辟新空间
// 2、拷贝元素
// 3、释放旧空间
// 4、使用新空间
int CheckCapacity(Seqlist* s)
{
	assert(s);
	if (s->size == s->capacity)
	{
		int newCapacity = s->capacity * 2;
		s->array = (SDataType*)realloc(s->array, newCapacity * sizeof(SDataType));
		if (NULL == s->array)
			return 0;

		s->capacity = newCapacity;
		////申请新空间
		//SDataType* temp = (SDataType*)malloc(newCapacity * sizeof(SDataType));
		////拷贝元素
		//memcpy(temp, s->array, s->capacity * sizeof(SDataType));
		////释放旧空间
		//free(s->array);
		////使用新空间
		//s->array = temp;
		//s->capacity = newCapacity;
	}
	return 1;
}

//尾插
//1、不需要扩容，直接将元素插在size位置
//2、需要扩容
void SeqListPushBack(Seqlist* s, SDataType data)
{
	assert(s);
	//在插入之前要保证有空间
	if (!CheckCapacity(s))
		return;

	s->array[s->size++] =data;
}
//尾删
void SeqListPopBack(Seqlist* s)
{
	assert(s);
	if (SeqListEmpty(s))
		return;
	s->size--;
}
//首插
//1、先检测是否需要扩容--如果需要则扩容
//2、将顺序表中所有元素整体往后搬移一个位置
//3、将data插入到顺序表的起始位置
void SeqListPushFront(Seqlist* s, SDataType data)
{
	if (!CheckCapacity(s))
		return;

	for (int i = s->size - 1; i >= 0; i--)
	{
		s->array[i + 1] = s->array[i];
	}
	s->array[0] = data;
	s->size++;
}

//首删--出第一个元素外，剩余元素整体向前搬移
void SeqListPopFront(Seqlist* s)
{
	if (SeqListEmpty(s))
		return;
	for (int i = 1; i < s->size; ++i)
	{
		s->array[i - 1] = s->array[i];
	}
	s->size--;
}
//任意位置插入
//1、pos的范围在[0，size]
//2、检测是否需要扩容
//3、将[pos，size)位置的元素整体往后搬移一个位置
//4、在pos的位置插入新元素
void SeqListInsert(Seqlist* s, int pos, SDataType data)
{
	assert(s);
	if (pos<0 || pos>s->size)
		return;
	if (!CheckCapacity(s))
		return;
	for (int i = s->size - 1; i >= pos; --i)
	{
		s->array[i + 1] = s->array[i];
	}
	s->array[pos] = data;
	s->size++;
}
//任意位置删除
//1、pos必须在[0，size）
//2、将pos之后的所有元素整体往前搬移一个位置
void SeqListErase(Seqlist* s, int pos)
{
	assert(s);
	if (pos < 0 || pos >= s->size)
		return;

	for (int i = pos + 1; i < s->size; ++i)
		s->array[i-1] = s->array[i];
	
	s->size--;
}
//获取顺序表中有效元素个数
int SeqListSize(Seqlist* s)
{
	assert(s);
	return s->size;
}
//获取顺序表的容量
int SeqListCapacity(Seqlist* s)
{
	assert(s);
	return s->capacity;
}
//检测顺序表是否为空
int SeqListEmpty(Seqlist* s)
{
	assert(s);
	return 0 == s->size;
}
//查找data是否在顺序表中
int SeqListFind(Seqlist* s, SDataType data)
{
	assert(s);
	for (int i = 0; i < s->size; ++i)
	{
		if (data == s->array[i])
		{
			return i;
		}
	}
	return -1;
}
//清空
void SeqListClear(Seqlist* s)
{
	assert(s);
	s->size = 0;
}
//销毁
void SeqListDestroy(Seqlist* s)
{
	assert(s);
	if (s->array)
	{
		free(s->array);
		s->array = NULL;
		s->capacity = 0;
		s->size = 0;
	}
}

//打印
void SeqListPrint(Seqlist* s)
{
	assert(s);
	for (int i = 0; i < s->size; ++i)
	{
		printf("%d", s->array[i]);
	}
	printf("\n");
}
void Test1()
{
	Seqlist s;
	SeqListInit(&s, 2);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);

	printf("%d\n", SeqListSize(&s));
	printf("%d\n", SeqListCapacity(&s));
	SeqListPrint(&s);

	SeqListPopBack(&s);
	SeqListPopBack(&s);
	SeqListPopBack(&s);

	SeqListPushFront(&s, 0);
	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPrint(&s);


	SeqListDestroy(&s);
}
void Test2()
{
	Seqlist s;
	SeqListInit(&s, 10);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPushBack(&s, 6);
	SeqListPrint(&s);

	//任意位置插入
	SeqListInsert(&s, 3, 0);
	SeqListPrint(&s);
	//删除第一个元素4
	SeqListErase(&s, SeqListFind(&s, 4));
	SeqListPrint(&s);
}
void TestSeqList()
{
	//Test1();
	Test2();
}