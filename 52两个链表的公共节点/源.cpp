#include<cstdio>

struct ListNode
{
	int val;
	ListNode* next;
	ListNode(int x) :val(x), next(nullptr) {}
};

unsigned int GetListLength(ListNode* head)
{
	unsigned int length = 0;
	ListNode* pNode = head;
	while (pNode != nullptr)
	{
		++length;
		pNode = pNode->next;
	}
	return length;
}
ListNode* FindFirstCommonNode(ListNode* head1, ListNode* head2)
{
	//�õ���������ĳ���
	unsigned int Length1 = GetListLength(head1);
	unsigned int Length2 = GetListLength(head2);
	int LengthDif = Length1 - Length2;

	ListNode* pListHeadLong = head1;
	ListNode* pListHeadShort = head2;
	if (Length2 > Length1)
	{
		ListNode* pListHeadLong = head2;
		ListNode* pListHeadShort = head1;
		LengthDif = Length2 - Length1;
	}
	//���ڳ��������߼�������ͬʱ�����������ϱ���
	for (int i = 0; i < LengthDif; i++)
		pListHeadLong = pListHeadLong->next;

	while ((pListHeadLong != nullptr) && (pListHeadShort != nullptr) && (pListHeadLong != pListHeadShort))
	{
		pListHeadLong = pListHeadLong->next;
		pListHeadShort = pListHeadShort->next;
	}

	//�õ���һ�������ڵ�
	ListNode* pFirstCommonNode = pListHeadLong;

	return pFirstCommonNode;
}