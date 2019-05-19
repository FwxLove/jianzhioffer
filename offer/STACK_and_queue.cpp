#include <iostream>
#include <stack>

using namespace std;


//������ջʵ��һ�����У������������£��ֱ�����ڶ���β����������ڶ���ͷ��ɾ�����Ĺ���
template<typename T>
class CQueue
{
public:
	CQueue(void);
	~CQueue(void);

	void appendTail(const T& node)		//���β�����
	{
		stack1.push(node);
	}
	T deleteHead()			//�����ȳ���ɾ��ͷ���
	{
		if (stack2.size() <= 0)
		{
			while (stack1.size() > 0)
			{
				stack2.push(stack1.top());
				stack1.pop();
			}
		}
		if (stack2.size() == 0)
		{
			throw new exception("queue is empty");
		}
		T head = stack2.top();
		stack2.pop();
		return head;
	}
private:
	stack<T> stack1;
	stack<T> stack2;
};


