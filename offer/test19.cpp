//19 二叉树的镜像，完成一个函数，输入一个二叉树，该函数输出它的镜像
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