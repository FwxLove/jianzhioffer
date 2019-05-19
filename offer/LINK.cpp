#include <iostream>
#include <stack>
using namespace std;

struct ListNode
{
	int m_nValue;
	ListNode* m_pNext;
};

void AddToTail(ListNode **pHead, int value)					//添加一个节点
{
	ListNode* pNew = new ListNode();
	pNew->m_nValue = value;
	pNew->m_pNext = NULL;
	if (*pHead == NULL)
	{
		*pHead = pNew;
	}
	else
	{
		ListNode *pNode = *pHead;
		while (pNode->m_pNext)
		{
			pNode = pNode->m_pNext;
		}
		pNode->m_pNext = pNew;
	}

}

void RemoveNode(ListNode** pHead, int value)					//删除一个节点
{
	if (pHead==NULL || *pHead==NULL)
	{
		return;
	}
	ListNode* pToBeDeleted = NULL;
	if ((*pHead)->m_nValue == value)
	{
		pToBeDeleted = *pHead;
		*pHead = (*pHead)->m_pNext;
	}
	else
	{
		ListNode *pNoed = *pHead;
		while (pNoed->m_pNext)
		{
			if (pNoed->m_pNext->m_nValue == value)
			{
				pToBeDeleted = pNoed->m_pNext;
				break;
			}
			else
			{
				pNoed = pNoed->m_pNext;
			}
		}
		if (pNoed->m_pNext != NULL)
		{
			pNoed->m_pNext = pToBeDeleted->m_pNext;
		}
		
		
	}
	if (pToBeDeleted != NULL)
	{
		delete pToBeDeleted;
		pToBeDeleted = NULL;
	}
}

void PrintListReversingly_Iteratively(ListNode* pHead)				//用栈反向输出链表内容
{
	stack<ListNode*> nodes;
	if (pHead == NULL)
	{
		return;
	}

	ListNode* pNode = pHead;
	while (pNode!=NULL)
	{
		nodes.push(pNode);
		pNode = pNode->m_pNext;
	}
	while (!nodes.empty())
	{
		ListNode* tmp = NULL;
		tmp = nodes.top();
		nodes.pop();
		cout << tmp->m_nValue << " ";
	}
}

void PrintListReversingly_Recursively(ListNode* pHead)					//用递归反向输出链表内容
{
	if (pHead == NULL)
	{
		return;
	}
	PrintListReversingly_Recursively(pHead->m_pNext);
	cout << pHead->m_nValue << " ";
}



