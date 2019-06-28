#include<cstdio>
#include<cstdlib>
#include<cstring>

const int MaxN = 10;//最大数字长度


//存储连接后的字符串
char* strCombine1 = new char[MaxN * 2 + 1];
char* strCombine2 = new char[MaxN * 2 + 1];

int compare(const void* strNumber1, const void* strNumber2);

void PrintMinNumber(int* numbers, int length)
{
	if (numbers == nullptr || length <= 0)
		return;

	char** strNumbers = (char**)(new int[length]);
	for (int i = 0; i < length; i++)
	{
		strNumbers[i] = new char[MaxN + 1];
		sprintf(strNumbers[i], "%d", numbers[i]);
	}
	qsort(strNumbers, length, sizeof(char*), compare);

	for (int i = 0; i < length; ++i)
		printf("%s", strNumbers[i]);
	printf("\n");

	for (int i = 0; i < length; ++i)
		delete[]strNumbers[i];
	delete[]strNumbers;
}

int compare(const char* strNumber1, const char* strNumber2)
{
	strcpy(strCombine1, strNumber1);
	strcat(strCombine1, strNumber2);

	strcpy(strCombine2, strNumber2);
	strcat(strCombine2, strNumber1);

	return strcmp(strCombine1, strCombine2);
}