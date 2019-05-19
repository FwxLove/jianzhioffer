#include <iostream>
#include <set>
#include <list>
#include <string>
using namespace std;

void ReplaceBlank(char str[], int lenth)
{
	if (str == NULL || lenth <=0)
	{
		return;
	}

	int originalLength = 0;
	int numberOfBlank = 0;
	int i = 0;
	while (str[i] != '\0')
	{
		++originalLength;

		if (str[i] == ' ')
		{
			++numberOfBlank;
		}
		++i;
	}

	int newLength = originalLength + numberOfBlank * 2;
	if (newLength > lenth)
	{
		return;
	}

	int indexOfOriginal = originalLength;
	int indexOfNew = newLength;
	while (indexOfOriginal < indexOfNew && indexOfOriginal >=0 )
	{
		//cout << str[indexOfOriginal] << endl;
		if (str[indexOfOriginal] == ' ')
		{
			str[indexOfNew--] = '0';
			str[indexOfNew--] = '2';
			str[indexOfNew--] = '%';
			indexOfOriginal--;
		}
		else
		{
			str[indexOfNew--] = str[indexOfOriginal--];
		}
	}
	
}

void MergeAndSort(int A[],int lenA, int B[],int lenB,int length)
{
	if (A == NULL || B == NULL)
	{
		return;
	}
	if ((lenA +lenB) > length )
	{
		return;
	}
	int La = lenA - 1;
	int Lb = lenB - 1;
	int Len = lenA + lenB - 1;
	while (Len>La && La>=0)
	{
		if (A[La] >= B[Lb])
		{
			A[Len--] = A[La--];
		}
		else
		{
			A[Len--] = B[Lb--];
		}
	}
}

