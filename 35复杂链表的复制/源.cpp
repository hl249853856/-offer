#include<cstdio>

struct Node {
	int val;
	Node* next;
	Node* random;
	Node() {}
	Node(int _val) :val(_val), next(nullptr), random(nullptr) {}
	Node(int _val, Node* _next, Node* _random) :val(_val), next(_next), random(_random) {}
};


//复杂度O（n*n)
Node* copyRandomList(Node* head) {
	if (head == nullptr)
		return head;
	Node* newHead = new Node(head->val, nullptr, nullptr);
	Node* pToNew = newHead;
	Node* pToOld = head->next;
	//第一步，复制只带next指针的链表
	while (pToOld)
	{
		Node* newNode = new Node(pToOld->val, nullptr, nullptr);
		pToNew->next = newNode;
		pToNew = newNode;
		pToOld = pToOld->next;
	}
	//第二步，复制random指针
	pToNew = newHead;
	pToOld = head;
	Node* pOld = head;//寻找random指向的节点
	Node* pNew = newHead;
	while (pToOld)
	{
		if (pToOld->random)
		{
			pOld = head;
			pNew = newHead;
			while (pToOld->random != pOld)
			{
				pOld = pOld->next;
				pNew = pNew->next;
			}
			pToNew->random = pNew;
		}
		pToOld = pToOld->next;
		pToNew = pToNew->next;
	}
	return newHead;
}


//分三步	  1.复制每个节点并插在其后
//		  2.复制random指针
//		  3.分离新旧链表
//第一步
void CloneNodes(Node* head)
{
	Node* pNode = head;
	while (pNode)
	{
		Node* pCloned = new Node(pNode->val);
		pCloned->next = pNode->next;
		pNode->next = pCloned;
		pNode = pCloned->next;
	}
}

//连接随机节点
void ConnectedRandomNodes(Node* head)
{
	Node* pNode = head;
	while (pNode)
	{
		pNode->next->random = pNode->random->next;
		pNode = pNode->next->next;
	}
}

//拆分成两个链表,返回复制的链表
Node* DivideList(Node* head)
{
	Node* pNode = head;
	Node* pClonehead = nullptr;
	Node* pCloneNode = nullptr;

	if (pNode)
	{
		pClonehead = pCloneNode = pNode->next;
		pNode->next = pClonehead->next;
		pNode = pNode->next;
	}

	while (pNode)
	{
		pCloneNode->next = pNode->next;
		pCloneNode = pCloneNode->next;
		pNode->next = pCloneNode->next;
		pNode = pNode->next;
	}

	return pClonehead;
}


Node* Clone(Node* head)
{
	CloneNodes(head);
	ConnectedRandomNodes(head);
	return DivideList(head);
}

void test()
{
	Node* node1 = new Node(1);
	Node* node2 = new Node(2);
	Node* node3 = new Node(3);
	Node* node4 = new Node(4);
	Node* node5 = new Node(5);

	node1->next = node2;
	node2->next = node3;
	node3->next = node4;
	node4->next = node5;

	node1->random = node3;
	node2->random = node5;
	node4->random = node2;

	Node* p = node1;
	while (p)
	{
		printf("%d->", p->val);
		p = p->next;
	}
	printf("nullptr\n");
	p = node1;

	while (p)
	{
		if (p->random)
		{
			printf("%d->%d\n", p->val, p->random->val);
		}
		p = p->next;
	}
}

int main()
{
	test();

	return 0;
}