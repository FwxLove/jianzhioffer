//22 栈的压入，弹出序列：输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否为该栈的弹出顺序
#include <iostream>
#include <stack>
using namespace std;

bool IsPopOrder(const int *pPush, const int *pPop, int nLength)
{
	bool bPossible = false;

	if (pPush == NULL || pPop == NULL || nLength <= 0)
	{
		return bPossible;
	}

	const int* pNextPush = pPush;
	const int* pNextPop = pPop;

	stack<int> stackData;

	while (pNextPush - pPush < nLength)
	{
		while (stackData.empty() || stackData.top() != *pNextPop)
		{
			if (pNextPush - pPush == nLength)
			{
				break;
			}

			stackData.push(*pNextPush);
			pNextPush++;
		}

		if (stackData.top() != *pNextPop)
		{
			break;
		}

		stackData.pop();
		pNextPop++;
	}

	if (stackData.empty() && pNextPop-pPop==nLength)
	{
		bPossible = true;
	}

	return bPossible;
}

