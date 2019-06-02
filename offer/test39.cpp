//求二叉树的深度
#include <iostream>
struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

int TreeDepth(BinaryTreeNode* pRoot)
{
	if (pRoot == NULL)
	{
		return 0;
	}

	int left = TreeDepth(pRoot->m_pLeft);
	int right = TreeDepth(pRoot->m_pRight);

	return (left > right) ? left + 1 : right + 1;
}

//判断是否是平衡二叉树
bool IsBalanced(BinaryTreeNode* pRoot, int* pDepth)
{
	if (pRoot == NULL)
	{
		*pDepth = 0;
		return true;
	}

	int left, right;
	if (IsBalanced(pRoot->m_pLeft, &left) && IsBalanced(pRoot->m_pRight, &right))
	{
		int diff = left - right;
		if (diff <= 1 && diff >= -1)
		{
			*pDepth = 1 + (left > right ? left : right);
			return true;
		}
	}
	return false;
}

