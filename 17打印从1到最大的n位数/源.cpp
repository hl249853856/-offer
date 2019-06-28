#include<iostream>
#include<stdio.h>
using namespace std;

bool Increment(char* number);
void PrintNumber(char* number);
void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index);

void Print1ToMaxOfDigits(int n)
{
	if (n <= 0)
		return;
	char* number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';

	while (!Increment(number))
	{
		PrintNumber(number);
	}
	delete[]number;
}

bool Increment(char* number)
{
	bool IsOverflow = false;//是否溢出
	int nTakeOver = 0;//进位
	int nLength = strlen(number);

	for (int i = nLength - 1; i >= 0; i--)
	{
		int nSum = number[i] - '0' + nTakeOver;
		if (i == nLength - 1)		//如果是个位，加1操作
			nSum++;
		if (nSum >= 10)
		{
			if (i == 0)
				IsOverflow = true;
			else
			{
				nSum -= 10;
				nTakeOver = 1;
				number[i] = '0' + nSum;
			}
		}
		else
		{
			number[i] = '0' + nSum;
			break;
		}
	}
	return IsOverflow;
}

void PrintNumber(char* number)
{
	char* p = number;
	while (*p == '0')
		p++;
	while (*p!='\0')
	{
		printf("%c", *p);
		p++;
	}
	printf("\t");
}

//数字排列法
void Print1ToMaxOfNDigits(int n)
{
	if (n <= 0)
		return;
	char* number = new char[n + 1];
	number[n] = '\0';

	for (int i = 0; i < 10; i++)
	{
		number[0] = i + '0';
		Print1ToMaxOfNDigitsRecursively(number, n, 0);
	}
	delete[]number;
}

void Print1ToMaxOfNDigitsRecursively(char* number, int length, int index)
{
	if (index == length - 1)
	{
		PrintNumber(number);
		return;
	}
	for (int i = 0; i < 10; i++)
	{
		number[index + 1] = i + '0';
		Print1ToMaxOfNDigitsRecursively(number, length, index + 1);
	}
}

int main()
{
	Print1ToMaxOfDigits(2);
	printf("\n");
	Print1ToMaxOfNDigits(2);
	printf("\n");
	return 0;
}