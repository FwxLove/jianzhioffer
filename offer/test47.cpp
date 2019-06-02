//47 写一个函数，求两个整数之和，不能使用加减乘除运算符号
#include <iostream>
using namespace std;

int Add(int num1, int num2)
{
	int sum, carry;
	do 
	{
		sum = num1^num2;
		carry = num1&num2;
		num1 = sum;
		num2 = carry;
	} while (num2 != 0);

	return num1;
}