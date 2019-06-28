#include<iostream>
using namespace std;

//1.先排序，再比较相邻数  时间复杂度O(n)  空间复杂度O(1)

//2.构建哈希表   时间复杂度O(n)   空间复杂度O(n)

//3.时间复杂度O(n)  空间复杂度O(1)
bool duplicate(int numbers[], int length, int* duplication)
{
	if (numbers == nullptr || length <= 0)
		return false;
	for (int i = 0; i < length; i++)
		if (numbers[i]<0 || numbers[i]>length - 1)
			return false;
	for (int i = 0; i < length; i++)
	{
		while (numbers[i] != i)
		{
			if (numbers[i] == numbers[numbers[i]])
			{
				*duplication = numbers[i];
				return true;
			}
			//交换numbers[i]和numbers[numbers[i]]
			int temp = numbers[i];
			numbers[i] = numbers[numbers[i]];
			numbers[numbers[i]] = temp;
		}
	}
	return false;
}