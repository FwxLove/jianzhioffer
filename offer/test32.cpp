//32 从1到n整数中1出现的次数  
//输入一个整数n，求从1到n这n个整数的十进制表示中1出现的次数
#include <iostream>
#include <string>
#include <time.h>

using namespace std;

int PowerBase10(unsigned int n)
{
	int result = 1;
	for (unsigned int i = 0; i < n; i++)
	{
		result *= 10;
	}
	return result;
}

int NumberOf1(const char* strN)
{
	if (!strN || *strN < '0' || *strN > '9' || *strN == '\0')
	{
		return 0;
	}

	int first = *strN - '0';
	unsigned int length = static_cast<unsigned int>(strlen(strN));

	if (length == 1 && first == 0)
	{
		return 0;
	}

	if (length == 1 && first > 0)
	{
		return 1;
	}

	//假设strN是“21345”；
	//numFirstDigit是数字10000~19999的第一个位中的数目
	int numFirstDigit = 0;
	if (first > 1)
	{
		numFirstDigit = PowerBase10(length - 1);
	}
	else if (first == 1)
	{
		numFirstDigit = atoi(strN + 1) + 1;
	}

	//numOtherDigits是1346~21345除了第一位之外的数位中的数目
	int numOtherDigits = first*(length - 1)*PowerBase10(length - 2);
	//numRecursive是1~1345中的数目
	int numRecursive = NumberOf1(strN + 1);

	return numFirstDigit + numOtherDigits + numRecursive;
}

int NumberOf1Between1AndN( int n)
{
	if (n<=0)
	{
		return 0;
	}

	char strN[50];
	sprintf(strN, "%d", n);

	return NumberOf1(strN);
}
