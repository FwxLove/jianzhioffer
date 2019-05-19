//29  数组中有一个数字出现的次数唱过数组长度的一半，请找出这个数字
#include <iostream>
#include <time.h>
using namespace std;

//解法1
bool g_bInputInvalid = false;

bool CheckInvalidArray(int* numbers, int length)
{
	g_bInputInvalid = false;
	if (numbers == NULL && length <= 0)
	{
		g_bInputInvalid = true;
	}
	return g_bInputInvalid;
}

bool CheckMoreThanHalf(int* numbers, int length, int number)
{
	int times = 0;
	for (int i = 0; i < length; i++)
	{
		if (numbers[i] == number)
		{
			times++;
		}
	}

	bool isMoreThanHalf = true;
	if (times*2 <= length)
	{
		g_bInputInvalid = true;
		isMoreThanHalf = false;
	}

	return isMoreThanHalf;
}

int Partition(int data[], int length, int start, int end)		//为快速排序选择一个较为合适的数字
{
	if (data == NULL || length <= 0 || start < 0 || end >= length)	//判断数组是否有效
	{
		throw new exception("Invalid Parameters");
	}
	srand((unsigned)time(NULL));
	int index = rand() % length;								//产生一个随机索引
	swap(data[index], data[end]);								//把索引上的数与末位数进行交换

	int small = start - 1;
	for (index = start; index < end; index++)					//遍历整个数组
	{
		if (data[index] < data[end])							//如果所指的数小于  指定的数
		{
			++small;											//small索引+1
			if (small != index)									//如果small 不等于 index
			{													//将数组上大于指定的数 与小于指定的数进行交换
				swap(data[index], data[small]);					//交换index与small的数字
			}
		}
	}

	++small;
	swap(data[small], data[end]);								//将end与small的数字进行交换，则指定数左边都小于它，指定数右边都大于它

	return small;
}

int MoreThanHalfNum1(int* numbers, int length)
{
	if (CheckInvalidArray(numbers,length))
	{
		return 0;
	}

	int middle = length >> 1;
	int start = 0;
	int end = length - 1;
	int index = Partition(numbers, length, start, end);
	while (index != middle)
	{
		if (index > middle)
		{
			end = index - 1;
			index = Partition(numbers, length, start, end);
		}
		else
		{
			start = index + 1;
			index = Partition(numbers, length, start, end);
		}
	}

	int result = numbers[index];
	if (!CheckMoreThanHalf(numbers, length, result))
		result = 0;
	return result;
	{

	}
}

//解法2
int MoreThanHalfNum2(int* numbers, int length)
{
	if (CheckInvalidArray(numbers,length))
	{
		return 0;
	}

	int result = numbers[0];
	int times = 1;
	for (int i = 1; i < length; i++)
	{
		if (times == 0)
		{
			result = numbers[i];
			times++;
		}
		else if (numbers[i] == result)
		{
			times++;
		}
		else
		{
			times--;
		}
	}

	if (!CheckMoreThanHalf(numbers, length, result))
		result = 0;

	return result;
}