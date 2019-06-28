#include<stdio.h>
#include<iostream>
using std::cout;
using std::endl;

void ReplaceBlank(char string[], int length)
{
	if (string == nullptr || length <= 0)
		return;
	int cnt_string = 0;
	int cnt_blank = 0;
	int cnt_new_string = 0;
	int i = 0;
	while (string[i] != '\0')
	{
		if (string[i] == ' ')
			cnt_blank++;
		cnt_string++;
		i++;
	}
	cnt_new_string = cnt_string + 2 * cnt_blank;
	if (cnt_new_string > length)
		return;
	int indexOfOriginal = cnt_string;
	int indexOfNew = cnt_new_string;
	while (indexOfOriginal >= 0 && indexOfNew > indexOfOriginal)
	{
		if (string[indexOfOriginal] == ' ')
		{
			string[indexOfNew--] = '0';
			string[indexOfNew--] = '2';
			string[indexOfNew--] = '%';
		}
		else
			string[indexOfNew--] = string[indexOfOriginal];

		indexOfOriginal--;
	}
}

int main()
{
	char string[18] = "We are happy.";
	ReplaceBlank(string, 18);
	printf("%s", string);
	

	return 0;
}