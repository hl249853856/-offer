#include<cstdio>
#include<vector>
using namespace std;
struct TreeNode {
	int val;
	TreeNode* Left;
	TreeNode* Right;
	TreeNode(int x) :val(x), Left(nullptr), Right(nullptr) {}
};

void FindPath(TreeNode* root, int expectedSum, vector<int> path, int currentSum);

void FindPath(TreeNode* root, int expectedSum)
{
	if (root == nullptr)
		return;
	vector<int> path;
	int currentSum = 0;
	FindPath(root, expectedSum, path, currentSum);
}

void FindPath(TreeNode* root, int expectedSum, vector<int> path, int currentSum)
{
	currentSum += root->val;
	path.push_back(root->val);

	//�����Ҷ�ڵ���·���Ͻڵ�ֵ�ĺ͵��������ֵ�����ӡ·��
	bool isLeaf = (root->Left == nullptr&&root->Right == nullptr);
	if (currentSum == expectedSum&&isLeaf)
	{
		printf("A path is found: ");
		for (auto i : path)
			printf("%d\t", i);
		printf("\n");
	}

	//�������Ҷ�ڵ�����������ӽڵ�
	if (root->Left)
		FindPath(root->Left, expectedSum, path, currentSum);
	if (root->Right)
		FindPath(root->Right, expectedSum, path, currentSum);

	//���ظ��ڵ�֮ǰ����·����ɾ����ǰ�ڵ�
	path.pop_back();
}

int main()
{
	TreeNode* node1 = new TreeNode(10);
	TreeNode* node2 = new TreeNode(5);
	TreeNode* node3 = new TreeNode(12);
	TreeNode* node4 = new TreeNode(4);
	TreeNode* node5 = new TreeNode(7);

	node1->Left = node2;
	node1->Right = node3;
	node2->Left = node4;
	node2->Right = node5;

	FindPath(node1, 22);
	return 0;
}