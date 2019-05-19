//30 ����n���������ҳ�������С��k����
#include <iostream>
#include <set>
#include <time.h>
#include <vector>
#include <functional>
using namespace std;

//�ⷨ1

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