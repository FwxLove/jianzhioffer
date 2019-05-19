//在O(1)时间内删除链表结点
//给定单向链表的头指针和一个结点指针，定义一个函数在O(1)时间删除该结点
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

	//要删除的结点不是尾结点
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