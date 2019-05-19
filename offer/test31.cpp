//31 连续子数组的最大和
//输入一个整型数组，数组里有正数也有负数。数组中有一个或连续的多个整数组成一个子数组。求所有子数组的和的最大值
#include <iostream>
#include <time.h>
using namespace std;

bool g_InvalidInput = false;

int FindGreatestSumOfSubArray(int *pData, int nLength)
{
	if ((pData == NULL) || (nLength <= 0))
	{
		g_InvalidInput = true;
		return 0;
	}

	g_InvalidInput = false;

	int nCurSum = pData[0];
	int nGreatestSum = 0x80000000;

	for (int i = 0; i < nLength; i++)
	{
		if (nCurSum <= 0)
		{
			nCurSum = pData[i];
		}
		else
		{
			nCurSum += pData[i];
		}

		if (nCurSum > nGreatestSum)
		{
			nGreatestSum = nCurSum;
		}
	}
	return nGreatestSum;
}

//2   动态规划方法
