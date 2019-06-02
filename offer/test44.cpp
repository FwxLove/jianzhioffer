//44 ���˿����������5���ƣ��ж��ǲ���һ��˳�ӣ������������ǲ���������
#include <iostream>
#include <algorithm>
#include <functional>
using namespace std;

int compare(const void* arg1, const void* arg2)
{
	return *(int*)arg1 - *(int*)arg2;
}

bool IsContinuous(int* number, int length)
{
	if (number == NULL || length < 1)
	{
		return false;
	}

	qsort(number, length, sizeof(int),compare);

	int numberOfZero = 0;
	int numberOfGap = 0;

	//ͳ��������0�ĸ���
	for (int i = 0; i < length&&number[i] == 0; ++i)
	{
		++numberOfZero;
	}

	int small = numberOfZero;
	int big = small + 1;
	while (big<length)
	{
		if (number[small] == number[big])
		{
			return false;
		}

		numberOfGap = number[big] - number[small] - 1;
		small = big;
		big++;
	}
	return (numberOfGap > numberOfGap) ? false : true;
}