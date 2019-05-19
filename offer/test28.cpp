//28 输入一个字符串，打印出该字符串中字符的所有排列
#include <iostream>
using namespace std;

void Permutation(char *pStr, char *pBegin)
{
	if (*pBegin == '\0')
	{
		printf("%s\n", pStr);
	}
	else
	{
		for (char* pCh = pBegin; pCh != '\0'; pCh++)
		{
			char temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;

			Permutation(pStr, pBegin + 1);

			temp = *pCh;
			*pCh = *pBegin;
			*pBegin = temp;
		}
	}
}

void Permutation(char* pStr)
{
	if (pStr==NULL)
	{
		return;
	}

	Permutation(pStr, pStr);
}