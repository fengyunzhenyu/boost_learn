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

	//boost::shared_ptr<B>  m_pb;//指向B的内存
	int m_a;
};


int main()
{

	boost::shared_ptr<A> p1(new A);//引用计数 +1
	cout << p1.unique() << ", " << p1.use_count() << endl;

	//weak_ptr是shared_ptr的协助者，或者是一个配角，主要用于观察
	boost::weak_ptr<A> p2(p1);//不改变引用计数
	cout << p1.unique() << ", " << p1.use_count() << endl;
	cout << p2.expired()/*用于观察shared_ptr指向的内存是否释放*/ << ", " << p2.use_count() << endl;

	//weak_ptr不管理这块内存
	//p2->m_a; 错误

	boost::shared_ptr<A> p3(p1);//引用计数 +1
	boost::shared_ptr<A> p4(p3);//引用计数 +1

	//用weak_ptr观察一下
	cout << p2.expired()/*用于观察shared_ptr指向的内存是否释放*/ << ", " << p2.use_count() << endl;

	//释放管理权，引用计数-1
	p1.reset();
	cout << p2.expired()/*用于观察shared_ptr指向的内存是否释放*/ << ", " << p2.use_count() << endl;

	p3.reset();
	cout << p2.expired()/*用于观察shared_ptr指向的内存是否释放*/ << ", " << p2.use_count() << endl;

	p4.reset();
	cout << p2.expired()/*返回1 表示内存已释放*/ << ", " << p2.use_count() << endl;


	return 0;
}