//打印1到最大的n位数
#include <iostream>
using namespace std;
//第一种方法
bool Increment(char *number)				//在表示的字符串number上增加1
{
	bool isOverflow = false;
	int nTakeOver = 0;
	int nLength = strlen(number);
	for (int i = nLength-1; i >= 0; i--)
	{
		int nSum = number[i] - '0' + nTakeOver;
		if (i == nLength - 1)
		{
			nSum++;
		}

		if (nSum >= 10)
		{
			if (i == 0)
			{
				isOverflow = true;
			}
			else
			{
				nSum -= 10;
				nTakeOver = 1;
				number[i] = '0' + nSum;
			}
		}
		else
		{
			number[i] = '0' + nSum;
			break;
		}
	}

	return isOverflow;
}
	
void PrintNumber(char *number)				//打印出number
{
	bool isBegining0 = true;
	int nLength = strlen(number);

	for (int i = 0; i < nLength; i++)
	{
		if (isBegining0 && number[i] != '0')
		{
			isBegining0 = false;
		}

		if (!isBegining0)
		{
			printf("%c", number[i]);
		}
	}
	printf("\t");
}

void Porint1ToMaxOfNDigits(int n)
{
	if (n <= 0)
	{
		return;
	}

	char *number = new char[n + 1];
	memset(number, '0', n);
	number[n] = '\0';

	while (!Increment(number))
	{
		PrintNumber(number);
	}

	delete []number;
}

//第二种  用递归
void print1ToMaxOfNDigitsRecursively(char *number, int length, int index)
{
	if (index == length - 1)
	{
		PrintNumber(number);
		return;
	}

	for (int i = 0; i < 10; i++)
	{
		number[index + 1] = i + '0';
		print1ToMaxOfNDigitsRecursively(number, length, index + 1);
	}
}

void PrintTOMaxOfNDigits(int n)
{
	if (n <= 0)
	{
		return;
	}

	char *number = new char[n + 1];
	number[n] = '\0';

	for (int i = 0; i < 10; i++)
	{
		number[0] = i + '0';
		print1ToMaxOfNDigitsRecursively(number, n, 0);
	}

	delete[] number;
}

