//29  ��������һ�����ֳ��ֵĴ����������鳤�ȵ�һ�룬���ҳ��������
#include <iostream>
#include <time.h>
using namespace std;

//�ⷨ1
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

int Partition(int data[], int length, int start, int end)		//Ϊ��������ѡ��һ����Ϊ���ʵ�����
{
	if (data == NULL || length <= 0 || start < 0 || end >= length)	//�ж������Ƿ���Ч
	{
		throw new exception("Invalid Parameters");
	}
	srand((unsigned)time(NULL));
	int index = rand() % length;								//����һ���������
	swap(data[index], data[end]);								//�������ϵ�����ĩλ�����н���

	int small = start - 1;
	for (index = start; index < end; index++)					//������������
	{
		if (data[index] < data[end])							//�����ָ����С��  ָ������
		{
			++small;											//small����+1
			if (small != index)									//���small ������ index
			{													//�������ϴ���ָ������ ��С��ָ���������н���
				swap(data[index], data[small]);					//����index��small������
			}
		}
	}

	++small;
	swap(data[small], data[end]);								//��end��small�����ֽ��н�������ָ������߶�С������ָ�����ұ߶�������

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

//�ⷨ2
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