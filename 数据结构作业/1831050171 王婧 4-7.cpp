#include<iostream>
using namespace std;
char * Strncpy(char *d, const char* s, int n)//д��Strncpy�㷨����s�����n���ֽڸ��Ƶ�d��
{
	char* p = NULL;//������һ��ָ��
	if (d == s) { return d; }
	else if (d < s)
	{
		p = d;//��ָ��ָ���ַ���d�����ָ�
		while (n)
		{
			*p++ = *s++;
			n--;
		}
	}
	else
	{
		p = d + n;
		s = s + n;
		while (n)
		{
			*--p = *--s;
			n--;
		}
	}
	return d;
}
char* StrReplace(char* s, char* t,char* v)
{
	int t_len, v_len;
	char *p, *q, *p1;

	t_len = strlen(t);//t�ĳ���
	v_len = strlen(v);//v�ĳ���

	for (p = s;* p != 0; p++)//��ָ��p��s�ַ����ĵ�һ���ַ���ʼ����
	{
		for (p1 = p, q = t; *p1 == *q&&*q; p1++, q++)//����ָ��p1��q�ֱ��s��t���ַ���ʼ�����ָ��p1��qָ����ַ���ͬ��t�Ѿ������棬�˳�ѭ��
		{}
		if (*q) { continue; }//��t��û�б����꣬����û���ҵ���t��ȵ��ַ���������p++
		if (t_len != v_len)//�ߵ���һ��˵���ҵ���t��ȵ��ַ���
		{
			Strncpy(p+v_len, p+t_len, strlen(p+t_len)+1);
		}
		Strncpy(p, v, v_len);//��v����s�е�t
		p += v_len;//�´�ָ��ֱ��ָ��v���ַ���
	}
	return s;

}

int main()
{
	char a[100] = "abcdef,abcdef,abcdef";
	char b[] = "bcde";
	char c[] = "2018";
	cout << a << endl;
	cout << StrReplace(a, b, c) << endl;
	system("pause");
	return 0;
}