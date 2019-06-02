//42：输入一个英文句子，翻转句子中单词的顺序，但单词内字符的顺序不变。为简单起见，标点符号和普通字母一样处理
#include <iostream>
using namespace std;

//两次翻转
void Reverse(char *pBegin, char *pEnd)
{
	if (pBegin==NULL || pEnd==NULL)
	{
		return;
	}

	while (pBegin<pEnd)
	{
		char temp = *pBegin;
		*pBegin = *pEnd;
		*pEnd = temp;

		pBegin++;
		pEnd--;
	}
}

char* ReverseSentence(char* pData)
{
	if (pData == NULL)
	{
		return NULL;
	}

	char* pBegin = pData;
	char* pEnd = pData;

	while (*pEnd != '\0')
	{
		pEnd++;
	}
	pEnd--;

	Reverse(pBegin, pEnd);

	pBegin = pEnd = pData;
	while (*pBegin != '\0')
	{
		if (*pBegin == ' ')
		{
			pBegin++;
			pEnd++;
		}
		else if (*pEnd == ' ' || *pEnd == '\0')
		{
			Reverse(pBegin, pEnd);
			pBegin = ++pEnd;
		}
		else
		{
			pEnd++;
		}
	}

	return pData;

}


//字符串的左旋转操作是把字符串前面的若干个字符转移到字符串的尾部。请定义一个函数实现字符串左旋转操作的功能。
char* LeftRotateString(char* pStr, int n)
{
	if (pStr != NULL)
	{
		int nLength = static_cast<int>(strlen(pStr));
		if (nLength > 0 && n < nLength&& n>0)
		{
			char* pFirstStart = pStr;
			char* pFirstEnd = pStr + n - 1;
			char* pSecondStart = pStr + n;
			char* pSecondEnd = pStr + nLength - 1;

			//翻转字符串的前面n个字符
			Reverse(pFirstStart, pFirstEnd);
			Reverse(pSecondStart, pSecondEnd);
			Reverse(pFirstStart, pSecondStart);
		}
	}
	return pStr;
}