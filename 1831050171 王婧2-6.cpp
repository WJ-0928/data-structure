#include<stdio.h>

void Sort(int L[] , int len)
{
	int *p1,*p2 ,tmp;//��������ָ��
	p1 = L;//�ֱ�ָ���һ��λ�ã������һ��λ�ã�

	p2 = L+len-1;
	while(p1<p2)
	//��ǰ��ĵ�һ��ָ��������ż�������Һ���һ��ָ����������������ô�Ͱ�������ָ��ָ���λ�ý��н������ݡ��ŵ��ǲ��õ�������һ�����顣
	{
		if((*p1%2==1)) //����
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
 










