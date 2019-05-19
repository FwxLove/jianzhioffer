//30 输入n个整数，找出其中最小的k个数
#include <iostream>
#include <set>
#include <time.h>
#include <vector>
#include <functional>
using namespace std;

//解法1

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

void GetLeastNumbers(int* input, int n, int* output, int k)
{
	if (input == NULL || output == NULL || k>n || n <=0 || k<=0)
	{
		return;
	}

	int start = 0;
	int end = n - 1;
	int index = Partition(input, n, start, end);

	while (index != k)
	{
		if (index < k)
		{
			start = index + 1;
			index = Partition(input, n, start, end);
		}
		else
		{
			end = index - 1;
			index = Partition(input, n, start, end);
		}
	}

	for (int i = 0; i < k; i++)
	{
		output[i] = input[i];
	}
}


//2 
typedef multiset<int, greater<int>> inSet;
typedef multiset<int, greater<int>>::iterator setIterator;

void GetLeastNumbers(const vector<int>& data, inSet& leastNumbers, int k)
{
	leastNumbers.clear();

	if (k < 1 || data.size() < k)
	{
		return;
	}

	vector<int>::const_iterator iter = data.begin();
	for (; iter != data.begin() ; iter++)
	{
		if (leastNumbers.size() < k)
		{
			leastNumbers.insert(*iter);
		}
		else
		{
			setIterator iterGreater = leastNumbers.begin();
			if (*iter < *(iterGreater))
			{
				leastNumbers.erase(iterGreater);
				leastNumbers.insert(*iter);
			}
		}
	}
}