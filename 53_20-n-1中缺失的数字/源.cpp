int GetMissingNumber(int* numbers, int length)
{
	if (numbers == nullptr || length <= 0)
		return -1;

	int left = 0;
	int right = length - 1;
	while (left <= right)
	{
		int center = (left + right) >> 1;
		if (numbers[center] != center)
		{
			if (center == 0 || numbers[center - 1] == center - 1)
				return center;
				
			right = center - 1;
		}
		else
			left = center + 1;
	}
	if (left == length)
		return length;

	return -1;
}