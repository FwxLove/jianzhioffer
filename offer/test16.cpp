//·´×ªÁ´±í
#include <iostream>
#include "LINK.cpp"
using namespace std;

extern struct ListNode;

ListNode* ReverseList(ListNode* pHead)
{
	if (pHead == NULL)
	{
		return NULL;
	}

	if (pHead->m_pNext == NULL)
	{
		return pHead;
	}
	ListNode* pReverseHead = NULL;
	ListNode* pNode=pHead;
	ListNode* pPrev=NULL;
	ListNode* pNext = NULL;

	while (pNode != NULL)
	{
		pNext = pNode->m_pNext;

		if (pNext == NULL)
		{
			pReverseHead = pNode;
		}

		pNode->m_pNext = pPrev;
		pPrev = pNode;
		pNode = pNext;
	}
	
	return pReverseHead;
}


/*int main()
{
	ListNode* t1 = new ListNode();
	ListNode* t2 = new ListNode();
	ListNode* t3 = new ListNode();
	ListNode* t4 = new ListNode();
	ListNode* t5 = new ListNode();
	ListNode* t6 = new ListNode();
	ListNode* t7 = new ListNode();
	t1->m_nValue = 1;
	t2->m_nValue = 2;
	t3->m_nValue = 3;
	t4->m_nValue = 4;
	t5->m_nValue = 5;
	t6->m_nValue = 6;
	t1->m_pNext = t2;
	t2->m_pNext = t3;
	t3->m_pNext = t4;
	t4->m_pNext = t5;
	t5->m_pNext = t6;
	t6->m_pNext = NULL;	
	t7->m_nValue = 7;
	ListNode* t = t1;
	t=ReverseList(t1);
	while (t!=NULL)
	{
		cout << t->m_nValue << " ";
		t = t->m_pNext;
	}
}*/