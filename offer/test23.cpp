//23 从上往下打印二叉树
#include <iostream>
#include <deque>
using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

void PrintFromTopToBottom(BinaryTreeNode* pTreeRoot)
{
	if (!pTreeRoot)
	{
		return;
	}

	deque<BinaryTreeNode*> dequeTreeNode;

	dequeTreeNode.push_back(pTreeRoot);

	while (dequeTreeNode.size())
	{
		BinaryTreeNode* pNode = dequeTreeNode.front();
		dequeTreeNode.pop_front();

		cout << pNode->m_nValue << " ";

		if (pNode->m_pLeft)
		{
			dequeTreeNode.push_back(pNode->m_pLeft);
		}
		if (pNode->m_pRight)
		{
			dequeTreeNode.push_back(pNode->m_pRight);
		}
	}
}