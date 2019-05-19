//����������㷨
#include <iostream>
#include <time.h>
using namespace std;

//��������
int Partition(int data[], int length, int start, int end)		//Ϊ��������ѡ��һ����Ϊ���ʵ�����
{
	if (data==NULL || length <=0 || start < 0 || end >= length)	//�ж������Ƿ���Ч
	{
		throw new exception("Invalid Parameters");
	}
	srand((unsigned)time(NULL));								
	int index = rand() % length;								//����һ���������
	swap(data[index], data[end]);								//�������ϵ�����ĩλ�����н���

	int small = start - 1;										
	for ( index = start; index < end; index++)					//������������
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

void QuickSort(int data[], int length, int start, int end)
{
	if (start == end)
	{
		return;
	}
	int index = Partition(data, length, start, end);
	if (index>start)
	{
		QuickSort(data, length, start, index - 1);
	}
	if (index < end)
	{
		QuickSort(data, length, index + 1, end);
	}
}