//48 用C++设计一个不能被继承的类
#include <iostream>
using namespace std;


//把构造函数设为私有函数
class SealedClass1
{
public:
	static SealedClass1* GetInstance()
	{
		return new SealedClass1();
	}

	static void DeleteInstance(SealedClass1* pInstance)
	{
		delete pInstance;
	}

private:
	SealedClass1() { }
	~SealedClass1() { }
};

//利用虚拟函数
template<typename T> class MakeSealed
{
	friend T;
private:
	MakeSealed();
	~MakeSealed();
};

class SealedClass2 :virtual public MakeSealed<SealedClass2>
{
public:
	SealedClass2() { }
	~SealedClass2() { }
};