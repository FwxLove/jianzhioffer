//20 ˳ʱ���ӡ����
//����һ�����󣬰��մ���������˳ʱ���˳�����δ�ӡ��ÿһ������
#include <iostream>
using namespace std;

void PrintMatrixInCircle(int **numbers, int columns, int rows, int start)
{
	int endX = columns - 1 - start;
	int endY = rows - 1 - start;

	//�����Ҵ�ӡһ��
	for (int i = start; i <= endX; i++)
	{
		int number = numbers[start][i];
		cout << number << " ";
	}

	//���ϵ��´�ӡһ��
	if (start < endY)
	{
		for (int i = start + 1; i <= endY; ++i)
		{
			int number = numbers[i][endX];
			cout << number << " ";
		}
	}

	//���ҵ����ӡһ��
	if (start < endX && start <endY)
	{
		for (int i = endX - 1; i >= start; --i)
		{
			int number = numbers[endY][i];
			cout << number << " ";
		}
	}

	//���µ��ϴ�ӡһ��
	if (start < endX && start < endY - 1)
	{
		for (int i = endY - 1; i > start + 1; --i)
		{
			int number = numbers[i][start];
			cout << number << " ";
		}
	}
}

void PrintMatrixClockwisely(int** numbers, int columns, int rows)
{
	if (numbers == NULL || columns <= 0 || rows <= 0)
	{
		return;
	}

	int start = 0;

	while (columns > start*2 && rows > start*2)
	{
		PrintMatrixInCircle(numbers, columns, rows, start);
		start++;
	}
}