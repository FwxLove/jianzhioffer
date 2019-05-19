//34 丑数：把只包含因子2，3，5的数称作丑数。求按从小到大的顺序的第1500个丑数
#include <iostream>
using namespace std;

int Min(int number1, int number2, int number3)
{
	int min = (number1 < number2) ? number1 : number2;
	min = (min < number3) ? min : number3;
	return min;
}

int GetUglyNumber_Solution2(int index)
{
	if (index <= 0)
	{
		return 0;
	}

	int *pUglyNumbers = new int[index];
	pUglyNumbers[0] = 1;
	int nextUglyIndex = 1;

	int *pMultiply2 = pUglyNumbers;
	int *pMultiply3 = pUglyNumbers;
	int *pMultiply5 = pUglyNumbers;

	while (nextUglyIndex < index)
	{
		int min = Min(*pUglyNumbers * 2, *pUglyNumbers * 3, *pUglyNumbers * 5);
		pUglyNumbers[nextUglyIndex] = min;

		while (*pUglyNumbers * 2 <= pUglyNumbers[nextUglyIndex])
		{
			++pUglyNumbers;
		}
		while (*pUglyNumbers * 3 <= pUglyNumbers[nextUglyIndex])
		{
			++pUglyNumbers;
		}
		while (*pUglyNumbers * 5 <= pUglyNumbers[nextUglyIndex])
		{
			++pUglyNumbers;
		}
	}
	int ugly = pUglyNumbers[nextUglyIndex - 1];
	delete[] pUglyNumbers;
	return ugly;
}