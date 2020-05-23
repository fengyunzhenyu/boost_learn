
#include <iostream>
using namespace std;

#include <boost/make_shared.hpp>
#include <boost/scoped_ptr.hpp>
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
	//陷阱1，不要把栈内存地址赋给scoped_ptr，scoped_array，shared_ptr
	int a = 100;
	boost::shared_ptr<int> p(&a);
	cout << p.use_count() << endl;//运行时出错


	//陷阱二，shared_ptr不能多次引用同一原始指针，否则同一内存会被delete多次
	A* pA = new A;
	boost::shared_ptr<A> p1(pA);
	cout << p1.use_count() << endl;

	boost::shared_ptr<A> p2(pA);//这里p2并不知道p1的存在
	cout << p2.use_count() << endl;
	//p1 p2在对象析构时，会各自delete pA，从而报错
	//boost::shared_ptr<A> p2(p1);//正确的写法

	return 0;
}