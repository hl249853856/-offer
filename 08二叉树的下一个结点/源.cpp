#include<iostream>

typedef struct TreeNode* PtrToTreeNode;
typedef PtrToTreeNode BinTree;
struct TreeNode {
	int value;
	BinTree Left;
	BinTree Right;
	BinTree Parent;
};

BinTree GetNext(BinTree TNode)
{
	if (TNode == nullptr)
		return nullptr;
	BinTree pNext = nullptr;
	if (TNode->Right != nullptr)
	{
		pNext = TNode->Right;
		while (pNext->Left != nullptr)
			pNext = pNext->Left;
		return pNext;
	}
	else if (TNode->Parent != nullptr)
	{
		BinTree pCur = TNode;
		BinTree pParent = TNode->Parent;
		while (pParent != nullptr&&pCur == pParent->Right)
		{
			pCur = pParent;
			pParent = pParent->Parent;
		}
		pNext = pParent;
	}
	return pNext;
}