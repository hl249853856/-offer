#include<cstdio>
//题目一：和为s的两个数字
bool FindNumbersWithSum(int data[], int length, int Sum, int* num1, int* num2)
{
	bool found = false;
	if (data == nullptr || length < 1 || num1 == nullptr || num2 == nullptr)
		return found;

	int start = 0;
	int end = length - 1;
	while (start < end)
	{
		long long curSum = data[start] + data[end];

		if (curSum == Sum)
		{
			*num1 = data[start];
			*num2 = data[end];
			found = true;
			break;
		}
		else if (curSum > Sum)
			end--;
		else
			start++;
	}
	return found;
}


//题目二：和为s的连续正数序列
void PrintContinuousSequence(int small, int big);
void FindContinuousSequence(int sum)
{
	if (sum < 3)
		return;

	int small = 1;
	int big = 2;
	int middle = (1 + sum) / 2;
	int curSum = small + big;

	while (small < middle)
	{
		if (curSum == sum)
			PrintContinuousSequence(small, big);

		while (curSum > sum&&small < middle)
		{
			curSum -= small;
			small++;

			if (curSum == sum)
				PrintContinuousSequence(small, big);
		}

		big++;
		curSum += big;
	}
}

void PrintContinuousSequence(int small, int big)
{
	for (int i = small; i <= big; ++i)
		printf("%d", i);
	printf("\n");
}