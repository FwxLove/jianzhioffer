#include <iostream>
using namespace std;

//��ת�������С����
int MinInorder(int *numbers, int index1, int index2)
{
	int result = numbers[index1];
	for (int i = index1+1; i <=index2 ; i++)
	{
		if (result > numbers[i])
		{
			result = numbers[i];
		}
	}
	return result;
}
int Min(int *numbers, int length)
{
	if (numbers == NULL || length <= 0)
	{
		throw new exception("Invalid parameters");
	}
	//int len = length;
	
	int index1 = 0, index2 = length - 1;
	int index = index1;
	while (numbers[index1] >= numbers[index2])
	{
		if (index2 - index1 == 1)
		{
			index = index2;
			break;
		}

		index = (index1 + index2) / 2;

		//����±�Ϊindex1��index��index2ָ�������������ȣ���ֻ��˳�����
		if (numbers[index1] == numbers[index2] && numbers[index1] == numbers[index])
		{
			return MinInorder(numbers, index1, index2);
		}

		if (numbers[index] <= numbers[index2])
		{
			index2 = index;
		}
		else if (numbers[index] >= numbers[index1])
		{
			index1 = index;
		}
		
		
	}
	return numbers[index];
}
