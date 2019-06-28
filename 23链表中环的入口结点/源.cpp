#include<iostream>
using namespace std;

struct ListNode {
	int val;
	ListNode* next;
};

ListNode* MeetingNode(ListNode* pHead)
{
	if (pHead == nullptr)
		return nullptr;

	ListNode* pSlow = pHead->next;
	if (pSlow->next == nullptr)
		return nullptr;
	ListNode* pFast = pSlow->next;

	while (pFast != nullptr&&pSlow != nullptr)
	{
		if (pFast == pSlow)
			return pFast;
		pSlow = pSlow->next;
		pFast = pFast->next;
		if (pFast != nullptr)
			pFast = pFast->next;
	}
	return nullptr;
}

ListNode* EntryOfLoop(ListNode* pHead)
{
	ListNode* meetingNode = MeetingNode(pHead);
	if (meetingNode == nullptr)
		return nullptr;

	//���н�����
	int nodesInLoop = 1;
	ListNode* pNode1 = meetingNode;
	while (pNode1->next != meetingNode)
	{
		nodesInLoop++;
		pNode1 = pNode1->next;
	}

	//��pNode1���ƶ�n��
	pNode1 = pHead;
	for (int i = 0; i < nodesInLoop; i++)
		pNode1 = pNode1->next;

	//ͬʱ�ƶ�pNode1��pNode2
	ListNode* pNode2 = pHead;
	while (pNode1 != pNode2)
	{
		pNode1 = pNode1->next;
		pNode2 = pNode2->next;
	}
	return pNode1;
}