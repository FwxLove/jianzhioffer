//��O(1)ʱ����ɾ��������
//�������������ͷָ���һ�����ָ�룬����һ��������O(1)ʱ��ɾ���ý��
//
#include <iostream>
#include "LINK.cpp"
using namespace std;

extern struct ListNode;

void DeleteNode(ListNode** pListHead, ListNode* pToBeDeleted)
{
	if (!*pListHead || !pToBeDeleted)
	{
		return;
	}

	//Ҫɾ���Ľ�㲻��β���
	if (pToBeDeleted->m_pNext != NULL)
	{
		ListNode *pTmp;
		pToBeDeleted->m_nValue = pToBeDeleted->m_pNext->m_nValue;
		pTmp = pToBeDeleted->m_pNext;
		pToBeDeleted->m_pNext = pTmp->m_pNext;
		delete pTmp;
		pTmp = NULL;
	}
	else
	{
		if (*pListHead == pToBeDeleted)
		{
			delete pToBeDeleted;
			pToBeDeleted = NULL;
			*pListHead = NULL;
		}
		else
		{
			ListNode* pTmp = NULL;
			pTmp = *pListHead;
			while (pTmp->m_pNext != pToBeDeleted && pTmp != NULL)
			{
				pTmp = pTmp->m_pNext;
			}
				pTmp->m_pNext = NULL;
				delete pToBeDeleted;
				pToBeDeleted = NULL;
		}
	}
}