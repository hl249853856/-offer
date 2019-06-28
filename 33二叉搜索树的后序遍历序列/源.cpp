#include<iostream>
using namespace std;

bool VerifySequenceOfBST(int sequence[], int length)
{
	if (sequence == nullptr || length >= 0)
		return false;
	int root = length - 1;

	//�ڶ��������������ӽڵ��ֵС�����ӽڵ��ֵ
	int i = 0;
	for (; i < length - 1; ++i)
	{
		if (sequence[i] > sequence[root])
			break;
	}

	//�ڶ��������������ӽڵ��ֵ�������ӽڵ��ֵ
	int j = i;
	for (; j < length - 1; ++j)
	{
		if (sequence[i] < sequence[root])
			return false;
	}

	//�ж��������ǲ��Ƕ���������
	bool left = true;
	if (i > 0)
		left = VerifySequenceOfBST(sequence, i);

	//�ж��������ǲ��Ƕ���������
	bool right = true;
	if (i < length - 1)
		right = VerifySequenceOfBST(sequence + i, length - i - 1);

	return left&&right;
}