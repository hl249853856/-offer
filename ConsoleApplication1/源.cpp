#include<iostream>
using namespace std;

void ReorderOddEvent(int *arr, int length)
{
	if (arr == nullptr || length <= 1)
		return;
	int i = 0;
	int j = length - 1;

	while (i<j)
	{
		//iָ�򽫴�0��ʼ�ĵ�һ��ż��
		while (i < length && (arr[i] & 1 == 1))
			i++;

		//jָ��Ӻ���ǰ��һ������
		while (j >= 0 && (arr[j] & 1 == 0))
			j--;

		if (i < j)
			swap(arr[i], arr[j]);
		else
			break;
	}
}

int main()
{
	int A[] = { 1,4,2,8,7,9,6 };
	for (auto i : A)
		cout << i << " ";
	cout << endl;
	ReorderOddEvent(A, 7);
	for (auto i : A)
		cout << i << " ";
	cout << endl;
	return 0;
}