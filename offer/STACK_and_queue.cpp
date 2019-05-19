#include <iostream>
#include <stack>

using namespace std;


//用两个栈实现一个队列，队列声明如下，分别完成在队列尾部插入结点和在队列头部删除结点的功能
template<typename T>
class CQueue
{
public:
	CQueue(void);
	~CQueue(void);

	void appendTail(const T& node)		//添加尾部结点
	{
		stack1.push(node);
	}
	T deleteHead()			//先入先出，删除头结点
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


