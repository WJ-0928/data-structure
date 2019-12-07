#include<stdio.h>

void Sort(int L[] , int len)
{
	int *p1,*p2 ,tmp;//采用俩个指针
	p1 = L;//分别指向第一个位置，和最后一个位置，

	p2 = L+len-1;
	while(p1<p2)
	//当前面的第一个指针遇到了偶数，并且后面一个指针遇到了奇数，那么就把这俩个指针指向的位置进行交换数据。优点是不用单独声明一个数组。
	{
		if((*p1%2==1)) //奇数
		{
			p1++;
			continue;
		}
		if(*p2%2==0)
		{
			p2--;
			continue;
		}
		tmp = *p1;
		*p1 = *p2;
		*p2 = tmp;
 
		
	}
	int i;
	for(i= 0 ;i<len ;i++)
	{
		printf("%d",L[i]);
	}
}
int main()
{
	int L[]={1,2,3,5,4,7};
	int len;
	len = sizeof(L)/sizeof(int);
	Sort(L,len);
	return 0;
}
 










