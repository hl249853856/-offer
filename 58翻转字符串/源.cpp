#include<cstring>

void Reverse(char* pBegin, char* pEnd)
{
	if (pBegin == nullptr || pEnd == nullptr)
		return;

	while (pBegin < pEnd)
	{
		char temp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = temp;

		pBegin++;
		pEnd--;
	}
}

char* ReverseSentence(char* pData)
{
	if (pData == nullptr)
		return nullptr;

	char* pBegin = pData;
	char* pEnd = pData;
	while (*pEnd != '\0')
		pEnd++;
	pEnd--;

	//��ת��������
	Reverse(pBegin, pEnd);

	//��ת�����е�ÿ������
	pBegin = pEnd = pData;
	while (*pBegin != '\0')
	{
		if (*pBegin == ' ')
		{
			pBegin++;
			pEnd++;
		}
		else if (*pEnd == ' ' || *pEnd == '\0')
		{
			Reverse(pBegin, --pEnd);
			pBegin = ++pEnd;
		}
		else
			pEnd++;
	}
	return pData;
}


//����ת�ַ���
char* LeftRotateString(char* pStr, int n)
{
	if (pStr != nullptr)
	{
		int length = strlen(pStr);
		if (length > 0 && n > 0 && n < length)
		{
			char* pFirstStart = pStr;
			char* pFirstEnd = pStr + n - 1;
			char* pSecondStart = pStr + n;
			char* pSecondEnd = pStr + length - 1;

			//��ת�ַ�����ǰ��n���ַ�
			Reverse(pFirstStart, pFirstEnd);
			//��ת�ַ������沿��
			Reverse(pSecondStart, pSecondEnd);
			//��ת�����ַ���
			Reverse(pFirstStart, pSecondEnd);
		}
	}
	
	return pStr;
}