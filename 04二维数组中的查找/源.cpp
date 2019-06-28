#include<iostream>
#include<vector>
using namespace std;

bool Find(vector<vector<int>> matrix, int number)
{
	int row = matrix.size();
	int col = matrix[0].size();
	bool Found = false;

	if (row > 0 && col > 0)
	{
		int r = 0;
		int c = col - 1;
		while (r < row&&c >= 0)
		{
			if (matrix[r][c] < number)
				++r;
			else if (matrix[r][c] > number)
				--c;
			else
			{
				Found = true;
				break;
			}
		}
	}
	return Found;
}