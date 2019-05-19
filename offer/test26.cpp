//26 ����һ�����������ڸ��������У�ÿ����������һ��m_pNextָ��ָ����һ������⣬����һ��m_pSiblingָ�������е����������NULL
#include <iostream>
#include <vector>
using namespace std;

struct ComplexListNode
{
	int m_nValue;
	ComplexListNode* m_pNext;
	ComplexListNode* m_pSibling;
};

//����ԭʼ�����������N�������½��N�����ٰ�N'���ӵ�N�ĺ���
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

//���ԭʼ�����ϵĽ��N��m_pSiblingָ��S��������Ӧ�ĸ��ƽ���N����m_pSiblingָ��S����һ���S��
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

// �ѵڶ����������ֳ�������������λ���ϵĽ�����ԭʼ����ż��λ���ϵĽ����ɸ��Ƴ���������
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