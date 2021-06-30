#include"Seqlist.h"
#include<assert.h>
int removeElement(int* nums, int numsize, int val)
{
	int count = 0;//用来记录val的个数
	for (int i = 0; i < numsize; ++i)
	{
		if (nums[i] == val)
			count++;
		else
			nums[i - count] = nums[i];
	}
	int n = numsize - count;
	return n;
}
int main()
{
	int array[5] = { 1,2,4,5,2 };
	removeElement(array, 5, 2);
	return 0;
}