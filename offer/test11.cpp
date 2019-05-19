//数值的整数次方   
#include <iostream>
using namespace std;

bool g_InvalidInput = false;

bool Equal(double num1, double num2)
{
	if ((num1-num2 > -0.0000001) && (num1-num2 < 0.0000001))
	{
		return true;
	}
	else
	{
		return false;
	}
}

double PowerWithUnsignedExponent(double base, unsigned int exponent)
{
	if (exponent == 0)
	{
		return 1;
	}
	if (exponent == 1)
	{
		return base;
	}

	double result = PowerWithUnsignedExponent(base,exponent>>1);
	result *= result;
	if (exponent & 0x1 == 1)
	{
		result *= base;
	}
	return result;
}

double Power(double base, int exponent)
{
	g_InvalidInput = false;

	if (Equal(base,0.0) && exponent < 0)
	{
		g_InvalidInput = true;
		return 0.0;
	}

	unsigned int absExponent = (unsigned int)(exponent);
	if (exponent < 0)
	{
		absExponent = (unsigned int)(-exponent);
	}

	double result = PowerWithUnsignedExponent(base, absExponent);

	if (exponent < 0)
	{
		return 1.0 / result;
	}
	return result;
}
