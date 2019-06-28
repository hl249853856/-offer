int GetNumberSameAsIndex(int* data, int length)
{
	if (data == nullptr || length <= 0)
		return -1;

	int left = 0;
	int right = length - 1;
	int center;
	while (left <= right)
	{
		center = (left + right) >> 1;
		if (data[center] < center)
			left = center + 1;
		else if (data[center] > center)
			right = center - 1;
		else
			return center;
	}

	return -1;
}