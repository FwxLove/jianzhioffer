//24 �����������ĺ����������
//����һ���������飬�жϸ������ǲ���ĳ�����������ĺ�������Ľ��
#include <iostream>
using namespace std;

bool VerifySquenceOfBST(int sequence[], int length)
{
	if (sequence == NULL || length <= 0)
	{
		return false;
	}

	int root = sequence[length - 1];

	//�ڶ������������������Ľ��С�ڸ��ڵ�
	int i = 0;
	for (; i < length-1; i++)
	{
		if (sequence[i] > root)
			break;
	}
	//�ڶ������������������Ľ����ڸ��ڵ�
	int j = i;
	for ( ; j < length-1; j++)
	{
		if (sequence[j] < root)
			return false;
	}
	//�ж��������ǲ��Ƕ���������
	bool left = true;
	if (i>0)
	{
		left = VerifySquenceOfBST(sequence, i);
	}
	//�ж��������ǲ��Ƕ���������
	bool right = true;
	if (i<length-1)
	{
		right = VerifySquenceOfBST(sequence + i, length - i - 1);
	}
	return left && right;
}