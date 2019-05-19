//26 复制一个复杂链表，在复杂链表中，每个结点除了有一个m_pNext指针指向下一个结点外，还有一个m_pSibling指向链表中的任意结点或者NULL
#include <iostream>
#include <vector>
using namespace std;

struct ComplexListNode
{
	int m_nValue;
	ComplexListNode* m_pNext;
	ComplexListNode* m_pSibling;
};

//复制原始链表的任意结点N并创建新结点N’，再把N'链接到N的后面
void CloneNodes(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;
	while (pNode!=NULL)
	{
		ComplexListNode* pCloned = new ComplexListNode();
		pCloned->m_nValue = pHead->m_nValue;
		pCloned->m_pNext = pNode->m_pNext;
		pNode->m_pNext = pCloned;

		pCloned->m_pSibling = NULL;

		pNode = pCloned->m_pNext;
	}
}

//如果原始链表上的结点N的m_pSibling指向S，则它对应的复制结点的N’的m_pSibling指向S的下一结点S’
void ConnectSiblingNodes(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;

	while (pNode!=NULL)
	{
		ComplexListNode* pCloned = pNode->m_pNext;
		if (pNode->m_pSibling)
		{
			pCloned->m_pSibling = pNode->m_pSibling->m_pNext;
		}

		pNode = pCloned->m_pNext;
	}
}

// 把第二步的链表拆分成两个链表，奇数位置上的结点组成原始链表，偶数位置上的结点组成复制出来的链表
ComplexListNode* ReconnectNodes(ComplexListNode* pHead)
{
	ComplexListNode* pNode = pHead;
	ComplexListNode* pClonedHead = NULL;
	ComplexListNode* pClonedNode = NULL;

	if (pNode != NULL)
	{
		pClonedHead = pClonedNode = pNode->m_pNext;
		pNode->m_pNext = pClonedNode->m_pNext;
		pNode = pNode->m_pNext;

	}

	while (pNode!=NULL)
	{
		pClonedNode->m_pNext = pNode->m_pNext;
		pClonedNode = pClonedNode->m_pNext;
		
		pNode->m_pNext = pClonedNode->m_pNext;
		pNode = pNode->m_pNext;
	}
	return pClonedHead;
}