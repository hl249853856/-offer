struct TreeNode
{
	int val;
	TreeNode* Left;
	TreeNode* Right;
};

void ConvertNode(TreeNode* root, TreeNode** pLastInList);
TreeNode* Convert(TreeNode* root)
{
	TreeNode* pLastNodeInList = nullptr;
	ConvertNode(root, &pLastNodeInList);

	//pLastNodeInList指向双向链表的尾节点，
	//我们需要返回头节点
	TreeNode* pHeadOfList = pLastNodeInList;
	while (pHeadOfList != nullptr&&pHeadOfList != nullptr)
		pHeadOfList = pHeadOfList->Left;

	return pHeadOfList;
}

void ConvertNode(TreeNode* pNode, TreeNode** pLastNodeInList)
{
	if (pNode == nullptr)
		return;

	TreeNode* pCurrent = pNode;

	if (pCurrent->Left != nullptr)
		ConvertNode(pCurrent->Left, pLastNodeInList);

	pCurrent->Left = *pLastNodeInList;
	if (*pLastNodeInList != nullptr)
		(*pLastNodeInList)->Right = pCurrent;

	*pLastNodeInList = pCurrent;

	if (pCurrent->Right != nullptr)
		ConvertNode(pCurrent->Right, pLastNodeInList);

}