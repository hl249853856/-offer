#include<iostream>
#include<vector>
using namespace std;

int MaxSubArraySum(const vector<int>& data)
{
	if (data.size() == 0)
		return 0;
	int MaxSum = 0;
	int currentSum = 0;
	for (int i = 0; i < data.size(); i++)
	{
		currentSum += data[i];
		if (currentSum > MaxSum)
			MaxSum = currentSum;
		else if (currentSum < 0)
			currentSum = 0;
	}
	return MaxSum;
}

int main()
{
	vector<int> data{ 1,-2,3,10,-4,7,2,-5 };
	cout << MaxSubArraySum(data) << endl;
	return 0;
}