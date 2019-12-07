#include<iostream>
using namespace std;
char * Strncpy(char *d, const char* s, int n)//写的Strncpy算法：将s中最多n个字节复制到d中
{
	char* p = NULL;//定义了一个指针
	if (d == s) { return d; }
	else if (d < s)
	{
		p = d;//让指针指向字符串d的首字附
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

	t_len = strlen(t);//t的长度
	v_len = strlen(v);//v的长度

	for (p = s;* p != 0; p++)//让指针p从s字符串的第一个字符开始遍历
	{
		for (p1 = p, q = t; *p1 == *q&&*q; p1++, q++)//两个指针p1和q分别从s和t首字符开始，如果指针p1和q指向的字符不同或t已经遍历玩，退出循环
		{}
		if (*q) { continue; }//把t还没有遍历完，及还没有找到与t相等的字符串，就让p++
		if (t_len != v_len)//走到这一步说明找到与t相等的字符串
		{
			Strncpy(p+v_len, p+t_len, strlen(p+t_len)+1);
		}
		Strncpy(p, v, v_len);//让v代替s中的t
		p += v_len;//下次指针直接指向v个字符后
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