#pragma once

typedef int SDataType;
typedef struct Seqlist
{
	SDataType* array;//存放元素的空间，不够的时候在申请
	SDataType capacity;//空间总得大小
	SDataType size;  //空间中有效元素个数
}Seqlist;
//typedef struct Seqlist Seqlist;
	
void  SeqListInit(Seqlist* s, int initcapacity);
//尾插
void SeqListPushBack(Seqlist* s, SDataType data);
//尾删
void SeqListPopBack(Seqlist* s);
//首插
void SeqListPushFront(Seqlist* s, SDataType data);
//首删
void SeqListPopFront(Seqlist* s);
//任意位置插入
void SeqListInsert(Seqlist* s, int pos, SDataType data);
//任意位置删除
void SeqListErase(Seqlist* s, int pos);
//获取顺序表中有效元素个数
int SeqListSize(Seqlist* s);
//获取顺序表的容量
int SeqListCapacity(Seqlist* s);
//检测顺序表是否为空
int SeqListEmpty(Seqlist* s);
//查找data是否在顺序表中
int SeqListFind(Seqlist* s, SDataType data);
//清空
void SeqListClear(Seqlist* s);
//销毁
void SeqListDestroy(Seqlist* s);

//测试
void TestSeqList();