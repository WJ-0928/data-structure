#include"Sort.h"
#include<stdio.h>
#include<stack>
#include<assert.h>
#include<string.h>
void PrintArray(int array[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d ", array[i]);
	}
	printf("\n");
}
//插入排序
void InsertSort(int array[], int size)
{
	for (int i = 1; i < size; ++i)
	{
		int key = array[i];
		int end = i - 1;

		while (key < array[end] && end >= 0)
		{
			array[end + 1] = array[end];
			end--;
		}
		array[end + 1] = key;
	}
	
}

//希尔排序
void ShellSort(int* array, int size)
{
	int gap = size;
	while (gap > 1)
	{
		gap = gap / 3 + 1;//gap=gap/2;
		for (int i = gap; i < size; i++)
		{
			int key = array[i];
			int end = i - gap;

			while (key < array[end] && end >= 0)
			{
				array[end + gap] = array[end];
				end -= gap;
			}
			array[end + gap] = key;
		}
	}
}
void Swap(int* left, int* right)
{
	int temp = *left;
	*left = *right;
	*right = temp;
}
void SelectSortOp(int* array, int size)
{
	int begin = 0, end = size - 1;

	while (begin < end)
	{
		//无序区间内最大最小
		int minPos = begin;
		int maxPos = begin;
		int index = begin + 1;
		while (index <= end)
		{
			if (array[index] > array[maxPos])
				maxPos = index;
			if (array[index] < array[minPos])
				minPos = index;

			++index;
		}

		//注意：最右侧位置可能存储得是当前最小值
		if (maxPos != end)
		{
			Swap(&array[maxPos], &array[end]);//最大的数和最后一个数交换
		}
		//如果最右侧的位置可能存储得是当前的最小值，经过上述交换之后,最小值的位置已经发生改变
		//必须要更新minPos
		if (minPos == end)
		{
			minPos = maxPos;
		}
		if (minPos != begin)
		{
			Swap(&array[minPos], &array[begin]);//等于（a+min，a+left）最小的数和无序区间的第一个数交换
		}
		++begin;
		--end;
	}
}
void SelectSort(int* array, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int maxPos = 0;
		for (int j = 1; j < size - i; ++j)
		{
			if (array[j] > array[maxPos])
			{
				maxPos = j;
			}
		}
		if (maxPos != size - 1 - i)
		{
			Swap(&array[maxPos], &array[size - i - 1]);
		}
	}
}

void HeapAdjust(int* array, int size, int parent)
{
	int child = parent * 2 + 1;
	while (child<size)
	{
		//如果右子树的值大于左子树的值，则最大的数为右子树
		if (child + 1 < size && array[child + 1] > array[child])
			child += 1;

		if (array[child] > array[parent])
		{
			Swap(&array[parent], &array[child]);
			parent = child;
			child = parent * 2 + 1;
		}
		else
			return;
	}
}
void HeapSort(int* array, int size)
{
	int end = size - 1;
	//1、建堆
	//找到倒数第一个非叶子节点
	for(int root = ((size - 2) >> 1); root >= 0; --root)
	{
		HeapAdjust(array, size, root);
	}
	//2、利用堆删除的思想来进行排序
	while (end)
	{
		Swap(&array[0], &array[end]);//堆顶元素和无序区间的最后一个数交换
		HeapAdjust(array, end, 0);
		end--;
	}
}

void BubbleSort(int* array, int size)
{
	//外层循环控制的是冒泡排序的趟数，既需要冒泡多少次
	for (int i = 0; i < size-1; ++i)
	{
		int isChange = 0;
		//具体冒泡的方式：依次用相邻两个元素进行比较，将大的元素往后翻
		//j:表示数组的下标--->j表示后一个元素的标志
		for (int j = 1; j < size - i; ++j)
		{
			if (array[j-1] > array[j])
			{
				Swap(&array[j - 1], &array[j]);
				isChange = 1;
			}
		}
		//如果没有被修改，说明有序
		if (!isChange)
		{
			return;
		}
	}
}
int GetIndexOfmid(int* array, int left, int right)
{
	int mid = left + ((right - left) >> 1);
	if (array[left] < array[right - 1])
	{
		if (array[mid] < array[left])
			return left;
		else if (array[mid] > array[right - 1])
			return right - 1;
		else
			return mid;
	}
	else
	{
		if (array[mid] > array[left])
			return left;
		else if (array[mid] < array[right - 1])
			return right - 1;
		else
			return mid;
	}
}

//hoare版本
int Partion1(int* array, int left, int right)
{
	int begin = left;
	int end = right - 1;
	int key;
	int mid = GetIndexOfmid(array, left, right);
	Swap(&array[mid], &array[right - 1]);
	key = array[end];

	while (begin < end)
	{
		//让begin从前往后找，找比基准直大的元素，找到之后停止
		while (begin < end && array[begin] <= key)
			begin++;
		//让end从前往前找，找比基准直小的元素，找到之后停止
		while (begin < end && array[end] >= key)
			end--;
		if (begin < end)
		{
			Swap(&array[begin], &array[end]);
		}
	}
	if (begin != right - 1)
		Swap(&array[begin], &array[right - 1]);

	return begin;
}
//挖坑法

int Partion2(int* array, int left, int right)
{
	int begin = left;
	int end = right - 1;
	int key;
	int mid = GetIndexOfmid(array, left, right);
	Swap(&array[mid], &array[right - 1]);
	key = array[end];

	while (begin<end)
	{
		//让begin从前往后找，找比基准直大的元素，找到之后停止
		while (begin < end && array[begin] <= key)
			begin++;
		//让begin位置的元素填end位置的坑
		if (begin < end)
		{
			array[end--] = array[begin];
		}

		//现在begin位置形成一个新的坑
		//让end从前往前找，找比基准直小的元素，找到之后停止
		while (begin < end && array[end] >= key)
			end--;

		//end找到了一个比基准值小的元素
		//让end位置的元素填begin位置的坑
		if (begin < end)
		{
			array[begin++] = array[end];
		}
	}
	//用基准值填最后的坑
	array[begin] = key;
	return begin;
}
//前后指针版本
int Partion3(int* array, int left, int right)
{
	int cur = left;
	int prev = cur - 1;
	int key;
	int mid = GetIndexOfmid(array, left, right);
	Swap(&array[mid], &array[right - 1]);
	key = array[right-1];

	while (cur < right)
	{
		if (array[cur] < key && ++prev != cur)
		{
			Swap(&array[prev], &array[cur]);
		}
		++cur;
	}
	if (++prev != right - 1)
		Swap(&array[prev], &array[right - 1]);

	return prev;
}

void QuickSort(int* array, int left, int right)
{
	
	if (right - left < 16)
	{
		InsertSort(array + left, right - left);
	}
	else
	{
		int div = Partion1(array, left, right);
		QuickSort(array, left, div);
		QuickSort(array, div + 1, right);
	}
}
void QuickSort(int* a, int size)
{
	QuickSort(a, 0, size);
}
//循环版本：
void QuickSortNor(int* array, int size)
{
	std::stack<int> s;
	//将数据整体插入
	s.push(size);
	s.push(0);

	int left = 0, right = 0;
	while (!s.empty())
	{
		left = s.top();
		s.pop();
		right = s.top();
		s.pop();

		if (right - left > 1)
		{
			int div = Partion2(array, left, right);

			//div是基准值的位置
			//基准值的左侧：[left，div)
			//基准值的右侧：[div+1,right)

			s.push(right);
			s.push(div + 1);

			s.push(div);
			s.push(left);
		}
	}
}

void MergeData(int* array, int left, int mid, int right, int* temp)
{
	int begin1 = left, end1 = mid;
	int begin2 = mid, end2 = right;
	int index = left;
	while (begin1 < end1 && begin2 < end2)
	{
		if (array[begin1] <= array[begin2])
			temp[index++] = array[begin1++];
		else
			temp[index++] = array[begin2++];
	}
	while (begin1 < end1)
		temp[index++] = array[begin1++];
	while (begin2 < end2)
		temp[index++] = array[begin2++];
}
void MergeSort(int* array, int left, int right, int* temp)
{
	//只有一个元素
	if (right - left > 1)
	{
		//先找中间位置
		int mid = (left + ((right - left) >> 1));
		//[0,mid)[mid,size)
		MergeSort(array, left, mid, temp);
		MergeSort(array, mid, right, temp);
		MergeData(array, left, mid, right, temp);//归并
		memcpy(array + left, temp + left, (right - left) * sizeof(array[0]));
	}
	
}

void MergeSort(int* array, int size)
{
	int* temp = (int*)malloc(sizeof(array[0]) * size);
	if (temp == NULL)
	{
		assert(0);
		return;
	}
	MergeSort(array, 0, size, temp);
	free(temp);
}
//循环方式的归并排序
void MergeSortNor(int* array, int size)
{
	int gap = 1;
	int* temp = (int*)malloc(sizeof(array[0]) * size);
	if (temp == NULL)
	{
		assert(0);
		return;
	}
	while (gap < size)
	{
		for (int i = 0; i < size; i += 2 * gap)
		{
			int left = i;
			int mid = left + gap;
			int right = mid + gap;

			//随着gap的变化，mid和right可能会越界
			if (mid > size)
				mid = size;
			if (right > size)
				right = size;
			MergeData(array, left, mid, right, temp);
		}
		memcpy(array, temp, size*sizeof(array[0]));
		gap <<= 1;
	}
	free(temp);
}
void CountSort(int*  array, int size)
{
	//1、统计数据的范围，并不是必须的（如果用户告诉数据范围，就不需要来统计范围）
	int min = array[0];
	int max = array[0];
	for (int i = 1; i < size; ++i)
	{
		if (array[i] < min)
			min = array[i];
		if (array[i] > max)
			max = array[i];
	}
	//2、申请计数空间
	int range = max - min + 1;
	int* arraycount = (int*)malloc(range * sizeof(int));
	if (NULL == range)
	{
		assert(0);
		return;
	}
	memset(arraycount, 0, range * sizeof(int));
	//3、统计每个元素出现的次数
	for (int i = 0; i < size; ++i)
	{
		arraycount[array[i] - min]++;
	}
	//4、对数据进行回收
	int index = 0;
	for (int i = 0; i < range; ++i)
	{
		while (arraycount[i]--)
		{
			array[index++] = i + min;
		}
	}
	free(arraycount);
}

void TestSort()
{
	int array[] = { 4,1,7,1,3,4,6,2,6,3,2,5,8,0,9 };
	PrintArray(array, sizeof(array) / sizeof(array[0]));
	/*SelectSortOp(array, sizeof(array) / sizeof(array[0]));
	PrintArray(array, sizeof(array) / sizeof(array[0]));
	SelectSort(array, sizeof(array) / sizeof(array[0]));*/
	//ShellSort(array, sizeof(array) / sizeof(array[0]));
	//HeapSort(array, sizeof(array) / sizeof(array[0]));
	//BubbleSort(array, sizeof(array) / sizeof(array[0]));
	//QuickSort(array, sizeof(array) / sizeof(array[0]));
	//QuickSortNor(array, sizeof(array) / sizeof(array[0]));
	//MergeSort(array, sizeof(array) / sizeof(array[0]));
	/*MergeSortNor(array, sizeof(array) / sizeof(array[0]));*/
	CountSort(array, sizeof(array) / sizeof(array[0]));
	PrintArray(array, sizeof(array) / sizeof(array[0]));
}