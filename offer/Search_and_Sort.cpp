//排序与查找算法
#include <iostream>
#include <time.h>
using namespace std;

//快速排序
int Partition(int data[], int length, int start, int end)		//为快速排序选择一个较为合适的数字
{
	if (data==NULL || length <=0 || start < 0 || end >= length)	//判断数组是否有效
	{
		throw new exception("Invalid Parameters");
	}
	srand((unsigned)time(NULL));								
	int index = rand() % length;								//产生一个随机索引
	swap(data[index], data[end]);								//把索引上的数与末位数进行交换

	int small = start - 1;										
	for ( index = start; index < end; index++)					//遍历整个数组
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