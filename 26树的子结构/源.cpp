#include<iostream>
using namespace std;

struct TreeNode {
	double val;
	TreeNode* Left;
	TreeNode* Right;
	TreeNode(double x) :val(x), Left(nullptr), Right(nullptr) {}
};

bool Equal(double num1, double num2);
bool HasSubTree(TreeNode* root1, TreeNode* root2);
bool DoesTree1HaveTree2(TreeNode* root1, TreeNode* root2);

bool HasSubTree(TreeNode* root1, TreeNode* root2)
{
	bool result = false;

	if (root1 != nullptr&&root2 != nullptr)
	{
		if (Equal(root1->val, root2->val))
			result = DoesTree1HaveTree2(root1, root2);
		if (!result)
			result = HasSubTree(root1->Left, root2);
		if (!result)
			result = HasSubTree(root1->Right, root2);
	}
	return result;
}

bool DoesTree1HaveTree2(TreeNode* root1, TreeNode* root2)
{
	if (root2 == nullptr)
		return true;
	if (root1 == nullptr)
		return false;
	if (!Equal(root1->val, root2->val))
		return false;

	return DoesTree1HaveTree2(root1->Left, root2->Left) && DoesTree1HaveTree2(root1->Right, root2->Right);
}

bool Equal(double num1, double num2)
{
	if ((num1 - num2 > -0.0000001) && (num1 - num2 < 0.0000001))
		return true;
	else
		return false;
}


//*********************************************************
//其中当root2为空时，也看作root1的子树
bool  IsSubTree(TreeNode* root1, TreeNode* root2)
{
	bool result = false;
	if (root2 == nullptr)
		return true;
	if (root1 == nullptr)
		return false;
	if (Equal(root1->val, root2->val))
		result = IsSubTree(root1->Left, root2->Left) && IsSubTree(root1->Right, root2->Right);
	if(!result)
		result = IsSubTree(root1->Left, root2) || IsSubTree(root1->Right, root2);
	return result;
}



int main()
{
	TreeNode* Anode1 = new TreeNode(8);
	TreeNode* Anode2 = new TreeNode(8);
	TreeNode* Anode3 = new TreeNode(7);
	TreeNode* Anode4 = new TreeNode(9);
	TreeNode* Anode5 = new TreeNode(2);
	TreeNode* Anode6 = new TreeNode(4);
	TreeNode* Anode7 = new TreeNode(7);

	Anode1->Left = Anode2;
	Anode1->Right = Anode3;
	Anode2->Left = Anode4;
	Anode2->Right = Anode5;
	Anode5->Left = Anode6;
	Anode5->Right = Anode7;

	TreeNode* Bnode1 = new TreeNode(8);
	TreeNode* Bnode2 = new TreeNode(9);
	TreeNode* Bnode3 = new TreeNode(2);

	Bnode1->Left = Bnode2;
	Bnode1->Right = Bnode3;

	cout << HasSubTree(Anode1, Bnode1) << endl;
	cout << IsSubTree(Anode1, Bnode1) << endl;
	

	return 0;
}