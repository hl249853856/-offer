struct TreeNode {
	int val;
	TreeNode* left;
	TreeNode* right;
	TreeNode(int x) :val(x), left(nullptr), right(nullptr) {}
};

TreeNode* KthNodeCore(TreeNode* root, unsigned int& k);
TreeNode* KthNode(TreeNode* root, unsigned int k)
{
	if (root == nullptr || k == 0)
		return nullptr;

	return KthNodeCore(root, k);
}

TreeNode* KthNodeCore(TreeNode* root, unsigned int& k)
{
	TreeNode* target = nullptr;

	if (root->left != nullptr)
		target = KthNodeCore(root->left, k);

	if (target == nullptr)
	{
		if (k == 1)
			return root;

		k--;
	}

	if (target == nullptr&&root->right != nullptr)
		target = KthNodeCore(root->right, k);

	return target;
}