//一个整型数组里除了两个数字之外，其他数字都出现了两次，请找出这两个只出现了一次的数字
//利用异或
#include <iostream>
using namespace std;

unsigned int FindFirstBitIs1(int num)
{
	int indexBit = 0;
	while (((num & 1) == 0) && (indexBit < 8 * sizeof(int)))
	{
		num = num >> 1;
		++indexBit;
	}
	return indexBit;
}

bool IsBit1(int num, unsigned int indexBit)
{
	num = num >> indexBit;
	return (num & 1);
}

void FindNumsAppearOnce(int data[], int length, int* num1, int* num2)
{
	if (data == NULL || length < 2)
	{
		return;
	}

	int resultExclusiveOR = 0;
	for (int i=0;i<length;i++)
	{
		resultExclusiveOR ^= data[i];
	}

	unsigned int indexOf1 = FindFirstBitIs1(resultExclusiveOR);

	*num1 = *num2 = 0;
	for (int j=0;j<length;j++)
	{
		if (IsBit1(data[j]),indexOf1)
		{
			*num1 ^= data[j];
		}
		else
		{
			*num2 ^= data[j];
		}
	}
}