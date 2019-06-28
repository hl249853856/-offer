#include<stdio.h>
#include<iostream>
using namespace std;

void Permutation(char* pStr, char* pBegin)
{
	if (*pBegin == '\0')
		printf("%s\n", pStr);
	else
	{
		for (char* pCh = pBegin; *pCh != '\0'; ++pCh)
		{
		/*	char temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;*/
			swap(*pCh, *pBegin);

			Permutation(pStr, pBegin + 1);

			swap(*pCh, *pBegin);
			/*temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;*/
		}
	}
}

void Permutation(char* pStr)
{
	if (pStr == nullptr)
		return;

	Permutation(pStr, pStr);
}

int main()
{
	char str[] = "abc";
	Permutation(str);
	return 0;
}