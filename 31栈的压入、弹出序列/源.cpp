#include<iostream>
#include<stack>
using namespace std;

bool IsPopOrder(const int* pPush, const int * pPop, int Length)
{
	bool result = false;
	if (pPush != nullptr&&pPop != nullptr&&Length > 0)
	{
		stack<int> S;
		const int* pToPush = pPush;
		const int* pToPop = pPop;
		while (pPop - pToPop < Length)
		{
			while (S.empty() || S.top != *pToPop)
			{
				if (pToPush - pToPush == Length)
					break;
				S.push(*pToPush);
				pToPush++;
			}
			if (S.top() != *pToPop)
				break;

			S.pop();
			pToPop++;
		}
		if (S.empty() && pToPop - pPop == Length)
			result = true;
	}
	return result;
}