#include<cstdio>

int GetFirstK(int* data, int length, int k, int start, int end)
{
	if (start > end)
		return -1;

	int center = (start + end) / 2;
	if (data[center] == k)
	{
		if (center > 0 && data[center - 1] != k || center == 0)
			return center;
		else
			end = center - 1;
	}
	else if (data[center] > k)
		end = center - 1;
	else
		start = center + 1;

	return (data, length, k, start, end);
}

int GetLastK(int* data, int length, int k, int start, int end)
{
	if (start > end)
		return -1;

	int center = (start + end) / 2;
	if (data[center] == k)
	{
		if (center < length - 1 && data[center + 1] != k || center == length - 1)
			return center;
		else
			start = center + 1;
	}
	else if (data[center] < k)
		start = center + 1;
	else
		end = center - 1;

	return GetLastK(data, length, k, start, end);
}

int GetNumberOfK(int* data, int length, int k)
{
	int number = 0;
	if (data != nullptr&&length > 0)
	{
		int first = GetFirstK(data, length, k, 0, length - 1);
		int last = GetLastK(data, length, k, 0, length - 1);

		if (first > -1 && last > -1)
			number = last - first + 1;
	}
	return number;
}