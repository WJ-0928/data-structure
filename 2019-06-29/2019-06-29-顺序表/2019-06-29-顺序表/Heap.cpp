#if 0
#include"Heap.h"
#include<malloc.h>
#include<assert.h>
#include<stdio.h>
#include<string.h>

int Less(HDataType left, HDataType right)
{
	return left < right;
}
int Greater(HDataType left, HDataType right)
{
	return left > right;
}
//初始化一个空堆
void HeapInit(Heap* hp, int initCap, CMP cmp)
{
	assert(hp);
	initCap = initCap < 10 ? 10 : initCap;
	hp->array = (HDataType*)malloc(sizeof(HDataType) * initCap);
	if (NULL == hp->array)
	{
		assert(0);
		return;
	}
	hp->capacity = initCap;
	hp->size = 0;
	//接受比较方式
	hp->Cmp = cmp;
}
void Swap(HDataType* left, HDataType* right)
{
	HDataType temp = *left;
	*left = *right;
	*right = temp;
}
void AdjustDown(Heap* hp, int parent)
{
	//用child标记娇小的孩子
	int size = hp->size;
	int* array = hp->array;
	int child = parent * 2 + 1;
	while (child < size)
	{
		//找到parent中两个孩子中娇小的孩子
		if (child + 1 < size && hp->Cmp(array[child + 1],array[child]))//array[child + 1] > array[child]大堆
		{
			child += 1;
		}
		//parent娇小的孩子已经找到
		//检测parent是否满足堆得性质
		if (hp->Cmp(array[child] , array[parent]))//array[child] > array[parent]
		{
			Swap(&array[child], &array[parent]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			return;
	}
}
//用数组中的元素创建堆
void HeapCreate(Heap* hp, int* array, int size, CMP cmp)
{
	//1、先将数组的元素放入堆中
	HeapInit(hp, size, cmp); 
	memcpy(hp->array, array, sizeof(HDataType*) * size);
	hp->size = size;
	//2、进行调整
	for (int root = (size - 2) / 2; root >= 0; root--)
	{
		AdjustDown(hp, root);
	}
}
void AdjustUP(Heap* hp, int child)
{
	HDataType* array = hp->array;
	int size = hp->size;
	int parent = ((child - 1) >> 1);
	while (child)
	{
		if (hp->Cmp(array[child] ,array[parent]))
		{
			Swap(&array[child], &array[parent]);
			child = parent;
			parent = ((child - 1) >> 1);
		}
		else
		{
			return;
		}
	}
}
void CheckCapacityHP(Heap* hp)
{
	assert(hp);
	if (hp->size == hp->capacity)
	{
		int newCapacity = hp->capacity * 2;
		HDataType* temp = (HDataType*)malloc(sizeof(HDataType) * newCapacity);
		if (temp == NULL)
		{
			assert(0);
			return;
		}
		//memcpy(temp, hp->array, hp->size * sizeof(HDataType));
		for (int i = 0; i < hp->size; ++i)
			temp[i] = hp->array[i];
		free(hp->array);
		hp->array = temp;
		hp->capacity = newCapacity;
	}
}
void HeapPush(Heap* hp, HDataType data)
{
	assert(hp);
	//0、检测是否需要扩容
	CheckCapacityHP(hp);

	//1、将新元素插入数组的末尾，将元素插入到完全二叉树最后
	hp->array[hp->size++] = data;
	//2、新元素插入后，可能会破坏堆得性质
	AdjustUP(hp, hp->size - 1);

}
void HeapPop(Heap* hp)
{
	if (HeapEmpty(hp))
		return;

	Swap(&hp->array[0], &hp->array[hp->size - 1]);
	hp->size--;
	AdjustDown(hp,0);
}
//获取堆顶元素
HDataType HeapTop(Heap* hp)
{
	assert(!HeapEmpty(hp));
	return hp->array[0];
}

//堆为空返回非0值
int HeapEmpty(Heap* hp)
{
	assert(hp);
	return 0 == hp->size;
}
int HeapSize(Heap* hp)
{
	assert(hp);
	return hp->size;
}
void HeapDestroy(Heap* hp)
{
	assert(hp);
	free(hp->array);
	hp->array = NULL;
	hp->capacity = 0;
	hp->size = 0;
}
void TestHeap()
{
	int array[] = { 3,6,9,1,5,2,0,7,8,4 };
	Heap hp;
	HeapCreate(&hp, array, sizeof(array) / sizeof(array[0]),Less);
	printf("heap size=%d\n", HeapSize(&hp));
	printf("heap top=%d\n", HeapTop(&hp));

	HeapPop(&hp);
	printf("heap size=%d\n", HeapSize(&hp));
	printf("heap top=%d\n", HeapTop(&hp));

	HeapPush(&hp, 0);
	HeapDestroy(&hp);
}
#endif