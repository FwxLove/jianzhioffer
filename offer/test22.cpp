//22 ջ��ѹ�룬�������У����������������У���һ�����б�ʾջ��ѹ��˳�����жϵڶ��������Ƿ�Ϊ��ջ�ĵ���˳��
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

