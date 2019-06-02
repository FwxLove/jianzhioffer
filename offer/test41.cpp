//41:����һ����������������һ������s���������в�����������ʹ�����ǵĺ�������s������ж�����ֵĺ͵���s���������һ�Ѽ���
#include <iostream>
using namespace std;

bool FindNumbersWithSum(int data[], int length, int sum, int* num1, int* num2)
{
	bool found = false;
	if (length<1||num1==NULL||num2==NULL)
	{
		return found;
	}

	int ahead = length - 1;
	int behind = 0;

	while (ahead > behind)
	{
		long long cursum = data[ahead] + data[behind];
		if (cursum == sum)
		{
			*num1 = data[behind];
			*num2 = data[ahead];
			found = true;
			break;
		}
		else if (cursum < sum)
		{
			behind++;
		}
		else
		{
			ahead--;
		}
	}
	return found;
}


//����һ������s����ӡ�����к�Ϊs�������������У����ٺ�����������������15 ��1+2+3+4+5=4+5+6=7+8=15
void PrintContinuousSequence(int small, int big)
{
	for (int i=small;i<big;i++)
	{
		cout << i << " ";
	}
	cout << endl;
}

void FindContinuousSequence(int sum)
{
	if (sum<3)
	{
		return;
	}

	int small = 1;
	int big = 2;
	int middle = (1 + sum) / 2;
	int curSum = small + big;

	while (small < middle)
	{
		if (curSum == sum)
		{
			PrintContinuousSequence(small, big);
		}

		while (curSum > sum && small < middle)
		{
			curSum -= sum;
			small++;

			if (curSum == sum)
			{
				PrintContinuousSequence(small, big);
			}
			
		}
		big++;
		curSum += big;
	}
}