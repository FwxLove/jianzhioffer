//二进制中1的个数
#include <iostream>
using namespace std;

int NumberOf1(int n)
{
	int count = 0;
	unsigned int flag = 1;
	while (flag)
	{
		if (n&flag)
		{
			count++;
		}
		flag = flag << 1;
	}
	return count;
}

int NumberOf2(int n)
{
	int count = 0;
	while (n)
	{
		++count;
		n = n&(n - 1);
		
	}
	return count;
}