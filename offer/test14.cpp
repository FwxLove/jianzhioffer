//14 调整数组顺序使奇数位于偶数前面
#include <iostream>
using namespace std;

bool isEven(int n)
{
	return (n & 1) == 0;
}

void Reorder(int *pData, unsigned int length,bool (*func)(int))
{
	if (pData == NULL || length <= 0)
	{
		return;
	}

	int iBegin = 0;
	int iEnd = length - 1;
	int tmp;
	while (iBegin<iEnd)
	{
		while (iBegin <iEnd && !func(pData[iBegin]))
		{
			iBegin++;
		}
		while (iBegin<iEnd && func(pData[iEnd]))
		{
			iEnd--;
		}
		if (iBegin<iEnd)
		{
			tmp = pData[iBegin];
			pData[iBegin] = pData[iEnd];
			pData[iEnd] = tmp;
		}
		
	}
}