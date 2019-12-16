#include<stdio.h>
#include<stack>
#include<stdlib.h>

//��ӡ
void printArray(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%d", a[i]);
	}
	printf("\n");
}
//����
void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}


//ֱ�Ӳ�������

void insertSort(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int k = a[i];//Ҫ�������
		int j;
		//����������[0,1)����ǰ���������Ҫ�������С���������������һ�����������������������Ƚ�
		for (j = i - 1; j >= 0 && k < a[j]; j--)
		{
			a[j + 1] = a[j];
		}
		a[j + 1] = k;//�µ�Ҫ�����ֵ�������������һ��������һ����
	}
}



//ϣ������
void shellSort(int a[], int size)
{
	int gap = size;
	while (1)
	{
		gap = gap / 3 + 1;//gap=gap/2;
		for (int i = 0; i < size; i++)
		{
			int k = a[i];
			int j;
			for (j = i - gap; j >= 0 && k < a[j]; j -= gap)
			{
				a[j + gap] = a[j];
			}
			a[j + gap] = k;
		}
		if (gap == 1)
		{
			break;
		}
	}
}




//ѡ������
void selectsort(int a[], int size)
{
	int left = 0;
	int right = size - 1;

	//����������[left,right]
	//����������ֻʣ1��������û����
	while (left < right)
	{
		//���������������С
		int min = left;
		int max = left;
		for (int i = left + 1; i <= right; i++)
		{
			if (a[i] < a[min])
			{
				min = i;
			}
			if (a[i] > a[max])
			{
				max = i;
			}
		}
		swap(&a[min], &a[left]);//���ڣ�a+min��a+left����С��������������ĵ�һ��������
		if (max == left)
		{
			max = min;
		}
		swap(a + max, a + right);//�����������һ��������
		left++;
		right--;
	}
}



//������
//���µ���  �����
void heapify(int a[], int size, int index)//index�ǶѶ�Ԫ��
{
	int left = index * 2 + 1;
	int right = index * 2 + 2;
	if (left >= size)
	{
		return;
	}
	int max = left;//������������������
	if (right<size&&a[right]>a[left])//�����������ֵ������������ֵ����������Ϊ������
	{
		max = right;
	}
	if (a[index] >= a[max])//����Ѷ�Ԫ�ش��������ӽڵ㣬����
	{
		return;
	}
	swap(a + index, a + max);//��������ӽڵ��λ��
	heapify(a, size, max);
}


//����
void createHeap(int a[], int size)
{
	//�����һ�����ӽڵ㿪ʼ����
	for (int i = (size - 2) / 2; i >= 0; i--)
	{
		heapify(a, size, i);
	}
}


void heapSort(int a[], int size)
{
	createHeap(a, size);
	for (int i = 0; i < size; i++)
	{
		swap(a, a + size - 1 - i);//�Ѷ�Ԫ�غ�������������һ��������
		heapify(a, size - 1 - i, 0);
	}
}

//ð������

void bubbleSort(int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		int sort = 1;
		for (int j = 0; j < size - 1 - i; j++)
		{
			if (a[j] > a[j + 1])
			{
				swap(a + j, a + j + 1);

				sort = 0;
			}
		}
		if (sort == 1)
		{
			break;
		}
	}
}
//��������


//�һ�׼ֵ
int partition1(int a[], int left, int right)
{
	int begin = left;
	int end = right;
	int pivot = a[right];
	while (begin < end)
	{
		while (begin < end&&a[begin] <= pivot)
		{
			begin++;
		}
		while (begin < end&&a[end] >= pivot)
		{
			end--;
		}
		swap(a + begin, a + end);
	}
	swap(a + begin, a + right);
	return begin;
}

int partition2(int a[], int left, int right)
{
	int begin = left;
	int end = right;
	int pivot = a[right];
	while (begin < end)
	{
		while (begin < end&&a[begin] <= pivot)
		{
			begin++;
		}
		a[end] = a[begin];
		while (begin < end&&a[end] >= pivot)
		{
			end--;
		}
		a[begin] = a[end];
	}
	a[begin] = pivot;
	return begin;
}

int partition3(int a[], int left, int right)
{
	int div = left;
	int i = left;
	for (i = left; i < right; i++)
	{
		if (a[i] < a[right])
		{
			swap(a + i, a + div);
			div++;
		}
	}
	swap(a + div, a + right);
	return div;
}
//����������
void quickSortTnternal(int a[], int left, int right)
{
	if (left >= right)
	{
		//[left,right]������ֻʣ1������0����
		return;
	}
	//1.ȷ����׼ֵ�����ұ� a[right]
	//2.��partition��С���󣬴���ң����ػ�׼ֵ���յ��±�
	int pivotIndex = partition3(a, left, right);
	//3.���δ�����������С����
	quickSortTnternal(a, left, pivotIndex - 1);
	quickSortTnternal(a, pivotIndex + 1, right);
}

//�ǵݹ�
void quickSortNoR(int a[], int left, int right)
{
	std::stack<int> s;
	s.push(left);
	s.push(right);
	while (!s.empty())
	{
		int high = s.top();
		s.pop();
		int low = s.top();
		s.pop();
		if (low >= high)
		{
			continue;
		}
		int pivotIndex = partition3(a, low, high);
		s.push(pivotIndex + 1);
		s.push(high);
		s.push(low);
		s.push(pivotIndex - 1);
	}
}
void quickSort(int a[], int size)
{
	quickSortNoR(a, 0, size - 1);
}

//�鲢
void MergeData(int  a[], int left, int mid, int right, int *temp)
{
	int begin1 = left, end1 = mid;
	int begin2 = mid, end2 = right;
	int index = left;//��ʱ�ռ�������
	while (begin1 < end1&&begin1 < end2)//˵�����������ڶ���Ԫ��
	{
		if (a[begin1] <= a[begin2])//����
		{
			temp[index++] = a[begin1++];//�����������Ԫ��
		}
		else
		{
			temp[index++] = a[begin2++];//�����ұ�����Ԫ��
		}
	}
	while (begin1 < end1)
	{
		temp[index++] = a[begin1++];
	}
	while (begin2 < end2)
	{
		temp[index++] = a[begin2++];
	}
}





//�鲢����
void _MergeSort(int a[], int left, int right, int* temp)
{
	//ֻ��һ��Ԫ��
	if (right - left <= 1)
	{
		return;
	}
	//�����м�λ��
	int mid = (left+((right - left) >> 1));
	//[0,mid)[mid,size)
	_MergeSort(a, left, mid,temp);
	_MergeSort(a, mid, right, temp);
	MergeData(a, left, mid, right, temp);//�鲢
	memcpy(a + left, temp + left, (right - left) * sizeof(a[0]));
}

void MergeSort(int a[], int size)
{
	int *temp = (int *)malloc(sizeof(a[0])*size);
	if (temp == NULL)
	{
		return;
	}
	_MergeSort(a, 0, size, temp);
	free(temp);
}

//�ǵݹ�鲢����
void MergeSortNor(int a[], int size)
{
	int *temp = (int *)malloc(sizeof(a[0])*size);
	if (temp == NULL)
	{
		return;
	}
	int gap = 1;
	while (gap < size)
	{
		for (int i = 0; i < size; i+=2*gap)
		{
			int left = i;
			int mid = left + gap;
			int right = mid + gap;
			if (mid >= size)
			{
				mid = size;
			}
			if (right >= size)
			{
				right = size;
			}
			MergeData(a, left, mid, right, temp);
		}
		memcpy(a, temp, size * sizeof(a[0]));
		gap *= 2;
	}
	
	free(temp);
}
//�ǱȽ�����
//��������
/*
�ʺϳ����������ܼ��ĳ�����ĳһ����Χ��

1��ͳ��ÿ�����ݳ��ֵĴ���
    count[a[i]]++;
2�������ݽ��л��գ�����
   ���������������һ��--->ȡ��һ������
*/
void CountSort(int a[], int size)
{
	//1���������ݷ�Χ
	int minValue = a[0];
	int maxValue = a[0];
	for (int i = 0; i < size; ++i)
	{
		if (a[i] < minValue)
		{
			minValue = a[i];
		}
		if (a[i] > maxValue)
		{
			maxValue = a[i];
		}
	}
	//2����ȡ�����Ŀռ�
	int range = maxValue - minValue + 1;
	int *temp = (int *)malloc(range * sizeof(int));
	if (NULL == temp)
	{
		return;
	}
	//3��ͳ��ÿ��Ԫ�س��ֵĴ���
	memset(temp, 0, sizeof(int)*range);//��ʼ��Ϊ0������Ϊ���ֵ
	for (int i = 0; i < size; ++i)
	{
		temp[a[i] - minValue]++;
	}
	//4������
	int index = 0;
	for (int i = 0; i < range; ++i)
	{
		while (temp[i])
		{
			a[index++] = i + minValue;
			temp[i]--;
		}
	}
	free(temp);
}
int main() {
	int a[] = { 1,9,2,8,3,7,4,6,5 };
	int size = sizeof(a) / sizeof(int);
	//ֱ�Ӳ�������
	insertSort(a, size);
	printArray(a, size);
	//ϣ������
	shellSort(a, size);
	printArray(a, size);
	//ѡ������
	selectsort(a, size);
	printArray(a, size);
	//������
	heapSort(a, size);
	printArray(a, size);
	//ð������
	bubbleSort(a, size);
	printArray(a, size);
	//��������
	quickSort(a, size);
	printArray(a, size);
	//�鲢����
	MergeSort(a, size);
	printArray(a, size);
	//��������
	CountSort(a, size);
	printArray(a, size);
	//�ǵݹ�鲢����
	//MergeSortNor(a, size);
	//printArray(a, size);
	system("pause");
	return 0;
}