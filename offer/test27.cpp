//27 ������������˫������  ����һ�Ŷ��������������ö���������ת����һ�������˫������Ҫ���ܴ����κ��µĽ�㣬ֻ�ܵ������н��ָ��
//��ָ��
#include <iostream>
#include <vector>
using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

void ConvertNode(BinaryTreeNode* pNode, BinaryTreeNode** pLastNodeInList)
{
	if (pNode == NULL)
	{
		return;
	}

	BinaryTreeNode* pCurrent = pNode;

	if (pCurrent->m_pLeft != NULL)
	{
		ConvertNode(pCurrent->m_pLeft, pLastNodeInList);
	}

	pCurrent->m_pLeft = *pLastNodeInList;
	if (*pLastNodeInList != NULL)
	{
		(*pLastNodeInList)->m_pRight = pCurrent;
	}

	*pLastNodeInList = pCurrent;

	if (pCurrent->m_pRight != NULL)
	{
		ConvertNode(pCurrent->m_pRight, pLastNodeInList);
	}
}

BinaryTreeNode* Convert(BinaryTreeNode* pRootOfTree)
{
	BinaryTreeNode* pLastNodeInList = NULL;						//ָ��˫�������β���
	ConvertNode(pRootOfTree, &pLastNodeInList);

	//��Ҫ����ͷ���
	BinaryTreeNode* pHeadOfList = pLastNodeInList;
	while (pHeadOfList !=NULL && pHeadOfList->m_pLeft !=NULL)
	{
		pHeadOfList = pHeadOfList->m_pLeft;
	}
	return pHeadOfList;
}