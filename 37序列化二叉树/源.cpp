#include<iostream>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* Left;
	TreeNode* Right;
};

//���л�������
void Serialize(TreeNode* root, ostream& stream)
{
	if (root == nullptr)
	{
		stream << "$,";
		return;
	}

	stream << root->val << ",";
	Serialize(root->Left, stream);
	Serialize(root->Right, stream);
}

//�����л�������
void Deserialize(TreeNode** root, istream& stream)
{
	int number;
	if (stream >> number)
	{
		*root = new TreeNode;
		(*root)->val = number;
		(*root)->Left = nullptr;
		(*root)->Right = nullptr;

		Deserialize((&(*root)->Left), stream);
		Deserialize(&((*root)->Right), stream);
	}
}