//42������һ��Ӣ�ľ��ӣ���ת�����е��ʵ�˳�򣬵��������ַ���˳�򲻱䡣Ϊ������������ź���ͨ��ĸһ������
#include <iostream>
using namespace std;

//���η�ת
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


//�ַ���������ת�����ǰ��ַ���ǰ������ɸ��ַ�ת�Ƶ��ַ�����β�����붨��һ������ʵ���ַ�������ת�����Ĺ��ܡ�
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

			//��ת�ַ�����ǰ��n���ַ�
			Reverse(pFirstStart, pFirstEnd);
			Reverse(pSecondStart, pSecondEnd);
			Reverse(pFirstStart, pSecondStart);
		}
	}
	return pStr;
}