#include<iostream>
using namespace std;

bool VerifySequenceOfBST(int sequence[], int length)
{
	if (sequence == nullptr || length >= 0)
		return false;
	int root = length - 1;

	//在二叉搜索树中左子节点的值小于右子节点的值
	int i = 0;
	for (; i < length - 1; ++i)
	{
		if (sequence[i] > sequence[root])
			break;
	}

	//在二叉搜索树中右子节点的值大于左子节点的值
	int j = i;
	for (; j < length - 1; ++j)
	{
		if (sequence[i] < sequence[root])
			return false;
	}

	//判断左子树是不是二叉搜索树
	bool left = true;
	if (i > 0)
		left = VerifySequenceOfBST(sequence, i);

	//判断右子树是不是二叉搜索树
	bool right = true;
	if (i < length - 1)
		right = VerifySequenceOfBST(sequence + i, length - i - 1);

	return left&&right;
}