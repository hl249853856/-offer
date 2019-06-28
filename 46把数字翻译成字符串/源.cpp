#include<cstdio>
#include<cstdlib>

int digitsOfN(int n);
int NumOfStr(int n)
{
	if (n < 0)
		return 0;
	int digits = digitsOfN(n);
	if (digits == 1)
		return 1;
	if (digits == 2)
	{
		if (n < 26)
			return 2;
		else
			return 1;
	}
	return NumOfStr(n / 10) + NumOfStr(n / 100);
}

int digitsOfN(int n)
{
	int count = 0;
	while (n)
	{
		count++;
		n /= 10;
	}
	return count;
}

int main()
{
	int n = 12258;
	printf("%d\n", NumOfStr(n));
	return 0;
}