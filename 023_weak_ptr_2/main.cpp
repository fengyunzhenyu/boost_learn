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

	int m_a;
};

int main()
{
	boost::shared_ptr<A> p1(new A);//引用计数 +1
	p1->m_a = 1000;

	boost::shared_ptr<A> p2(p1);//引用计数 +1

	cout << p1.use_count() << ", " << p2.use_count() << endl;

	boost::weak_ptr<A> w1(p1);//不影响引用计数，观察者
	cout << w1.expired() << ", " << w1.use_count() << endl;

	//此刻，让p1释放管理权
	p1.reset();//引用计数-1
	cout << p1.get() << ", " << p1.use_count() << endl;

	//通过w1来观察（由此可见，虽然p1放弃了管理权，但是w1依然能正常工作）
	cout << w1.expired() << ", " << w1.use_count() << endl;

	if (w1.expired())//观测的内存释放了
	{
		cout << "内存释放了" << endl;
	}
	else
	{
		//cout << p1->m_a << endl;//错误，已经放弃管理权了
		//w1->m_a;//错误，weak_ptr不能->, 不能够*
		boost::shared_ptr<A> p3 = w1.lock();//可以使用lock返回共享shared_ptr
		cout << p3->m_a << endl;

	}

	return 0;
}