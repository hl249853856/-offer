
//题目一：数组中只出现一次的两个数字，其他数字都出现了两次
unsigned int FindFirstBitIs1(int num);
bool IsBit1(int num, unsigned int indexBit);

void FindNumsAppearOnce(int data[], int length, int* num1, int* num2)
{
	if (data == nullptr || length < 2)
		return;

	int resultExclusiveOR = 0;
	for (int i = 0; i < length; ++i)
		resultExclusiveOR ^= data[i];

	unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);

	*num1 = *num2 = 0;
	for (int i = 0; i < length; i++)
	{
		if (IsBit1(data[i], indexOf1))
			*num1 ^= data[i];
		else
			*num2 ^= data[i];
	}
}

unsigned int FindFirstBitIs1(int num)
{
	int indexBit = 0;
	while (((num & 1) == 0) && (indexBit < 8 * sizeof(int)))
	{
		num = num >> 1;
		++indexBit;
	}
	return indexBit;
}

bool IsBit1(int num, unsigned int indexBit)
{
	num = num >> indexBit;
	return (num & 1);
}


//题目二：数组中唯一只出现一次的数字，其他数字都出现三次
int FindNumberAppearingOnce(int numbers[], int length)
{
	if (numbers == nullptr || length <= 0)
		return 0;

	int bitSum[32] = { 0 };
	for (int i = 0; i < length; ++i)
	{
		int bitMask = 1;
		for (int j = 31; j >= 0; --j)
		{
			int bit = numbers[i] & bitMask;
			if (!bit)
				bitSum[j] += 1;
			bitMask = bitMask << 1;
		}
	}

	int result = 0;
	for (int i = 0; i < 32; ++i)
	{
		result = result << 1;
		result += bitSum[i] % 3;
	}
	return result;
}