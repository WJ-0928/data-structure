#if 0
#include<iostream>
using namespace std;
int Sum(int m, int n)
{
	if (m >= 0 && n >= 0)
	{
		if (m > 0)
		{
			return Sum(m - 1, 2 * n) + n;
		}
		else { return 0; }
	}
}
int main()
{
	cout << Sum(3, 5) << endl;
	system("pause");
	return 0;
}
#endif