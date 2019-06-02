//48 ��C++���һ�����ܱ��̳е���
#include <iostream>
using namespace std;


//�ѹ��캯����Ϊ˽�к���
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

//�������⺯��
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