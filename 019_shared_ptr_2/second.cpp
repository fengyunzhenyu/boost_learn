
#include <iostream>
using namespace std;

#include <boost/make_shared.hpp>
#include <boost/scoped_ptr.hpp>

class B;//类的前置声明

class A
{
public:
	A()
	{
		cout << "构造A类对象！" << endl;
	}

	~A()
	{
		cout << "析构A类对象！" << endl;
	}

	boost::shared_ptr<B>  m_pb;//指向B的内存
};


class B
{
public:
	B()
	{
		cout << "构造B类对象！" << endl;
	}

	~B()
	{
		cout << "析构B类对象！" << endl;
	}

	boost::shared_ptr<A> m_pa;//指向a的内存
};

int main()
{
	//陷阱三：shared_ptr循环引用导致内存泄漏
	boost::shared_ptr<A> pA(new A);
	boost::shared_ptr<B> pB(new B);
	cout << pA.use_count() << " , " << pB.use_count() << endl;

	pA->m_pb = pB; //此刻，pB指向的内存引用计数为2
	pB->m_pa = pA; //此刻， pA指向的内存引用计数为2
	cout << pA.use_count() << " , " << pB.use_count() << endl;
	/*
	此刻，pA，pB都析构时，都只会将引用计数-1，各自剩余引用计数为1，则不会释放
	从而导致A，B内存泄漏
	*/


	//陷阱四，shared_ptr管理的内存必须是new出来的
	int* pInt = (int*)malloc(sizeof(int));
	boost::shared_ptr<int> p(pInt); //这样肯定有问题的



	return 0;
}