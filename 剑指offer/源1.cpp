#include<iostream>
using namespace std;

//1.�������ٱȽ�������  ʱ�临�Ӷ�O(n)  �ռ临�Ӷ�O(1)

//2.������ϣ��   ʱ�临�Ӷ�O(n)   �ռ临�Ӷ�O(n)

//3.ʱ�临�Ӷ�O(n)  �ռ临�Ӷ�O(1)
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
			//����numbers[i]��numbers[numbers[i]]
			int temp = numbers[i];
			numbers[i] = numbers[numbers[i]];
			numbers[numbers[i]] = temp;
		}
	}
	return false;
}