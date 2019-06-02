//����������ĵ�һ����������
#include <iostream>
#include <stack>
using namespace std;

struct ListNode
{
	int m_nKey;
	ListNode* m_pNext;
};

unsigned int GetListLength(ListNode* pHead)
{
	unsigned int nLength = 0;
	ListNode* pNode = pHead;
	while (pNode != NULL)
	{
		++nLength;
		pNode = pNode->m_pNext;
	}
	return nLength;
}

ListNode* FindFirstCommonNode(ListNode* pHead1, ListNode* pHead2)
{
	//�õ���������ĳ���
	unsigned int nLength1 = GetListLength(pHead1);
	unsigned int nLength2 = GetListLength(pHead2);

	int nLengthDif = nLength1 - nLength2;

	ListNode* pListHeadLong = pHead1;
	ListNode* pListHeadShort = pHead2;

	if (nLength2 > nLength1)
	{
		pListHeadLong = pHead2;
		pListHeadShort = pHead1;
		nLengthDif = nLength2 - nLength1;
	}

	//���ڳ��������߼�������ͬʱ�����������ϱ���
	for (int i = 0; i < nLengthDif; i++)
	{
		pListHeadLong = pListHeadLong->m_pNext;
	}

	while ((pListHeadLong != NULL) && (pListHeadShort != NULL) && (pListHeadLong != pListHeadShort))
	{
		pListHeadLong = pListHeadLong->m_pNext;
		pListHeadShort = pListHeadShort->m_pNext;
	}

	//�õ���һ���������
	ListNode* pFirstCommonNode = pListHeadLong;
	return pFirstCommonNode;
}