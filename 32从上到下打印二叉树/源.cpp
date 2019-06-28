#include<cstdio>
#include<queue>
#include<stack>
using namespace std;

struct TreeNode {
	int val;
	TreeNode* Left;
	TreeNode* Right;
	TreeNode(int x) :val(x), Left(nullptr), Right(nullptr) {}
};

void PrintTree(TreeNode* root)
{
	if (root == nullptr)
		return;
	queue<TreeNode*> Q;
	Q.push(root);
	TreeNode* node;
	while (!Q.empty())
	{
		node = Q.front();
		Q.pop();
		printf("%d ", node->val);
		if (node->Left)
			Q.push(node->Left);
		if (node->Right)
			Q.push(node->Right);
	}
}


//*****************************
//分行从上到下打印二叉树
void Print(TreeNode* root)
{
	if (root == nullptr)
		return;
	queue<TreeNode*> Q;
	Q.push(root);
	TreeNode* node;
	int nextLevel = 0;
	int ToBePrinted = 1;
	
	while (!Q.empty())
	{
		node = Q.front();
		Q.pop();
		printf("%d ", node->val);
		if (node->Left)
		{
			Q.push(node->Left);
			++nextLevel;
		}
		if (node->Right)
		{
			Q.push(node->Right);
			++nextLevel;
		}
		
		--ToBePrinted;
		if (ToBePrinted == 0)
		{
			printf("\n");
			ToBePrinted = nextLevel;
			nextLevel = 0;
		}
	}
}



//*****************************
//之字形分行从上到下打印二叉树
void PrintZ(TreeNode* root)
{
	if (root == nullptr)
		return;
	
	stack<TreeNode*> S[2];
	TreeNode* node;
	int current = 0;
	int next = 1;
	S[0].push(root);
	while (!S[0].empty() || !S[1].empty())
	{
		node = S[current].top();
		S[current].pop();
		printf("%d ", node->val);

		if (current == 0)
		{
			if (node->Left)
				S[next].push(node->Left);
			if (node->Right)
				S[next].push(node->Right);
		}
		else
		{
			if (node->Right)
				S[next].push(node->Right);
			if (node->Left)
				S[next].push(node->Left);
		}

		if (S[current].empty())
		{
			printf("\n");
			current = 1 - current;
			next = 1 - next;
		}
	}
}

int main()
{
	TreeNode* node1 = new TreeNode(1);
	TreeNode* node2 = new TreeNode(2);
	TreeNode* node3 = new TreeNode(3);
	TreeNode* node4 = new TreeNode(4);
	TreeNode* node5 = new TreeNode(5);
	TreeNode* node6 = new TreeNode(6);
	TreeNode* node7 = new TreeNode(7);
	TreeNode* node8 = new TreeNode(8);
	TreeNode* node9 = new TreeNode(9);
	TreeNode* node10 = new TreeNode(10);
	TreeNode* node11 = new TreeNode(11);
	TreeNode* node12 = new TreeNode(12);
	TreeNode* node13 = new TreeNode(13);
	TreeNode* node14 = new TreeNode(14);
	TreeNode* node15 = new TreeNode(15);

	node1->Left = node2;
	node1->Right = node3;
	node2->Left = node4;
	node2->Right = node5;
	node3->Left = node6;
	node3->Right = node7;
	node4->Left = node8;
	node4->Right = node9;
	node5->Left = node10;
	node5->Right = node11;
	node6->Left = node12;
	node6->Right = node13;
	node7->Left = node14;
	node7->Right = node15;

	PrintTree(node1);
	printf("\n");
	Print(node1);
	PrintZ(node1);

	return 0;
}