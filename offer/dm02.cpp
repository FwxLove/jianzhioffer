#include <stdio.h>
#include <string.h>

void pri(char str[])
{
	int length = strlen(str);
	for (int i = 0; i<length; i++)
	{
		for (int j = 0; j<length - i; j++)
		{
			if (str[j]>str[j + 1])
			{
				int temp = str[j];
				str[j] = str[j + 1];
				str[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < 100; i++)
	{
		for (int i = 0; i < 100; i++)
		{
			if (str[i] == str[i + 1])
			{
				str[i + 1] = str[i + 2];
			}
		}
	}
}
int main02()
{
	char str[53];
	gets(str);
	puts(str);
	pri(str);
	return 0;
}