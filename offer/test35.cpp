//35 ��һ��ֻ����һ�ε��ַ�  ���ַ������ҳ���һ��ֻ����һ�ε��ַ��������롰abaccdeff������� b
#include <iostream>
#include <map>
using namespace std;

char FirstNotRepeatingChar(char* pString)
{
	if (pString == NULL)
	{
		return '\0';
	}
	map<char, int> hasbTable;
	int index = 0;
	for ( ; pString[index] != '\0' ; index++)
	{
		hasbTable[pString[index]]++;
	}
	int index1 = 0;
	char tmp;
	while (pString[index1] != '\0')
	{
		if (hasbTable[pString[index1]] > 1)
		{
			tmp = pString[index1];
			break;
		}
		index1++;
	}
	if (pString[index1] == '\0')
	{
		tmp = '\0';
	}
	return tmp;
}