#include<iostream>

struct TreeNode {
	double val;
	TreeNode* Left;
	TreeNode* Right;
	TreeNode(double x) :val(x), Left(nullptr), Right(nullptr) {}
};
bool Symmetrical(TreeNode* root1, TreeNode* root2);
bool isSymmetrical(TreeNode* root)
{
	return Symmetrical(root, root);
}

bool Symmetrical(TreeNode* root1, TreeNode* root2)
{
	if (root1 == nullptr&&root2 == nullptr)
		return true;
	if (root1 == nullptr || root2 == nullptr)
		return false;
	if (root1->val != root2->val)
		return false;

	return Symmetrical(root1->Left, root2->Right) &&
		Symmetrical(root1->Right, root2->Left);
}

