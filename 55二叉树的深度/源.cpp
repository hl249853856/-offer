struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};

int TreeDepth(TreeNode* root)
{
	if (root == nullptr)
		return 0;
	int LeftDepth = TreeDepth(root->left);
	int RightDepth = TreeDepth(root->right);

	return LeftDepth > RightDepth ? (LeftDepth + 1) : (RightDepth + 1);
}


//题目二：平衡二叉树
bool IsBalanced(TreeNode* root)
{
	if (root == nullptr)
		return true;

	int leftDepth = TreeDepth(root->left);
	int rightDepth = TreeDepth(root->right);

	int diff = leftDepth - rightDepth;
	if (diff > 1 || diff < -1)
		return false;

	return IsBalanced(root->left) && IsBalanced(root->right);
}


//每个节点只遍历一次的解法
bool IsBalanced(TreeNode* root, int* pDepth)
{
	if (root == nullptr)
	{
		*pDepth = 0;
		return true;
	}

	int left, right;
	if (IsBalanced(root->left, &left) && IsBalanced(root->right, &right))
	{
		int diff = left - right;
		if (diff <= 1 && diff >= -1)
		{
			*pDepth = 1 + (left > right ? left : right);
			return true;
		}
	}

	return false;
}


bool IsBalanced(TreeNode* root)
{
	int depth = 0;
	return IsBalanced(root, &depth);
}