//15 链表中倒数第k个结点
#include <iostream>
#include "LINK.cpp"
using namespace std;

extern struct ListNode;

ListNode* FindKthToTail(ListNode* pListHead, unsigned int k)
{
	if (pListHead == NULL || k == 0)
	{
		return NULL;
	}

	ListNode* tmp1 = pListHead;
	ListNode* tmp2 = pListHead;

	for (unsigned i = 0; i < k-1; i++)
	{
		if (tmp1->m_pNext != NULL)
		{
			tmp1 = tmp1->m_pNext;
		}
		else
		{
			return NULL;
		}
	}

	while (tmp1->m_pNext != NULL)
	{
		tmp1 = tmp1->m_pNext;
		tmp2 = tmp2->m_pNext;
	}
	return tmp2;
}