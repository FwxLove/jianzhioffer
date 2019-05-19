//25 二叉树中和为某一值的路径
//输入一颗二叉树和一个整数，输出二叉树中结点值的和为输入整数的所有路径。从根节点开始往下一直到叶节点所经过的结点形成一条路径
#include <iostream>
#include <vector>
using namespace std;

struct BinaryTreeNode
{
	int m_nValue;
	BinaryTreeNode* m_pLeft;
	BinaryTreeNode* m_pRight;
};

void FindPath(BinaryTreeNode* pRoot, int expectedSum)
{
	if (pRoot==NULL)
	{
		return;
	}

	vector<int> path;
	int currentSum = 0;
	FindPath(pRoot, expectedSum, path, currentSum);
}

void FindPath(BinaryTreeNode* pRoot, int expectedSum, vector<int>& path, int& currentSum)
{
	currentSum += pRoot->m_nValue;
	path.push_back(pRoot->m_nValue);

	//如果是叶节点，并且路径上结点的和等于输入的值
	//打印出这条路径
	bool isLeaf = pRoot->m_pLeft == NULL && pRoot->m_pRight == NULL;	
	if (currentSum == expectedSum && isLeaf)
	{
		printf("A path is found: ");
		vector<int>::iterator iter = path.begin();
		for ( ;  iter != path.end(); iter++)
		{
			printf("%d\t", *iter);
		}
		printf("\n");
	}

	//如果不是叶节点，则遍历他的子节点
	if (pRoot->m_pLeft != NULL)
	{
		FindPath(pRoot->m_pLeft, expectedSum, path, currentSum);
	}
	if (pRoot->m_pRight != NULL)
	{
		FindPath(pRoot->m_pRight, expectedSum, path, currentSum);
	}

	//在返回父节点之前，在路径上删除当前结点，
	//并在currentSum中减去当前结点的值
	currentSum -= pRoot->m_nValue;
	path.pop_back();
}