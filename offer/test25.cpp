//25 �������к�Ϊĳһֵ��·��
//����һ�Ŷ�������һ������������������н��ֵ�ĺ�Ϊ��������������·�����Ӹ��ڵ㿪ʼ����һֱ��Ҷ�ڵ��������Ľ���γ�һ��·��
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

	//�����Ҷ�ڵ㣬����·���Ͻ��ĺ͵��������ֵ
	//��ӡ������·��
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

	//�������Ҷ�ڵ㣬����������ӽڵ�
	if (pRoot->m_pLeft != NULL)
	{
		FindPath(pRoot->m_pLeft, expectedSum, path, currentSum);
	}
	if (pRoot->m_pRight != NULL)
	{
		FindPath(pRoot->m_pRight, expectedSum, path, currentSum);
	}

	//�ڷ��ظ��ڵ�֮ǰ����·����ɾ����ǰ��㣬
	//����currentSum�м�ȥ��ǰ����ֵ
	currentSum -= pRoot->m_nValue;
	path.pop_back();
}