#include <iostream>
using namespace std;

#include <boost/make_shared.hpp>
#include <boost/shared_array.hpp>
#include <boost/weak_ptr.hpp>

//class B;//类的前置声明

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

	boost::shared_ptr<A> m_a;
	boost::weak_ptr<A> m_a;//解决方案，因为weak_ptr不会改变引用计数
};

int main()
{
	{
		boost::shared_ptr<A> p1(new A);//引用计数 +1

		cout << p1.unique() << ", " << p1.use_count() << endl;

		//现在制造循环引用
		p1->m_a = p1; //share_ptr赋值操作，导致引用计数 +1
		cout << p1.unique() << ", " << p1.use_count() << endl;
	}//到这里时候，p1生命周期结束，产生析构，导致引用计数-1， 但是注意，2-1>0
	//所以 new A这块内存不会被释放，所以m_a成员也不会释放，这样就导致了引用计数
	//一直不为0，则new A的这块内存泄漏



	return 0;
}