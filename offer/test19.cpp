//19 �������ľ������һ������������һ�����������ú���������ľ���
#include <iostream>
#include "TREE.cpp"
using namespace std;

extern struct BinaryTreeNode;


void MirrorRecursively(BinaryTreeNode* pNode)
{
	if ((pNode == NULL) || (pNode->m_pLeft == NULL) && (pNode->m_pRight == NULL))
	{
		return;
	}

	BinaryTreeNode* pTmp = NULL;
	pTmp = pNode->m_pLeft;
	pNode->m_pLeft = pNode->m_pRight;
	pNode->m_pRight = pTmp;

	if (pNode->m_pLeft)
	{
		MirrorRecursively(pNode->m_pLeft);
	}
	if (pNode->m_pRight)
	{
		MirrorRecursively(pNode->m_pRight);
	}
}