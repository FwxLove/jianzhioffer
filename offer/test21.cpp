//����ջ�����ݽṹ�����ڸ�������ʵ��һ���ܹ��õ�ջ����СԪ�ص�min�������ڸ�ջ�У�����min��push��pop��ʱ�临�Ӷȶ���O(1)
#include <iostream>
#include <stack>
#include <assert.h>
using namespace std;

template<typename T>
class StackWithMin
{
public:
	void push(const T& value);
	void pop();
	const T& min() const;
private:
	stack Stack_major;
	stack Stack_tmp;
};

template<typename T>
void StackWithMin<T>::push(const T& value)
{
	Stack_major.push(value);

	if (Stack_tmp.size() == 1 )
	{
		T t1;
		if (Stack_tmp.top() < value)
		{
			t1 = Stack_tmp.top();
			Stack_tmp.push(t1);
		}
		else
		{
			Stack_tmp.push(value);
		}
	}
}

template<typename T>
void StackWithMin<T>::pop()
{
	assert(Stack_major.size() > 0 && Stack_tmp.size() > 0);

	Stack_major.pop();
	Stack_tmp.pop();
}

template<typename T>
const T& StackWithMin<T>::min() const
{
	assert(Stack_major.size() > 0 && Stack_tmp.size() > 0);

	return Stack_tmp.top();
}

int main()
{
	const int i = 0;
	int *j = (int*)&i;
	*j = i;
	cout << i << " " << *j;
	return 0;
}