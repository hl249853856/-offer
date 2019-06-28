#include<stdio.h>

struct ListNode
{
	int val;
	ListNode* next;
};

void PrintListReverse(ListNode* pHead)
{
	if (pHead != nullptr)
	{
		if (pHead->next != nullptr)
		{
			PrintListReverse(pHead->next);
		}
		printf("%d\t", pHead->val);
	}
}