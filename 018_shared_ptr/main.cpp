#include<iostream>
using namespace std;

#include<boost/scoped_ptr.hpp>
#include<boost/make_shared.hpp>
using namespace boost;

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
	boost::shared_ptr<A> p1(new A);//初始引用计数为1
	p1->m_a = 100;
	//此时唯一管理A的内存
	cout << p1.unique() << ", " << p1.use_count() << endl;

	//拷贝构造
	//此时 p1 p2同时管理A的内存
	boost::shared_ptr<A> p2(p1);//引用计数 +1
	cout << p2.unique() << ", " << p2.use_count() << endl;

	//赋值运算符
	boost::shared_ptr<A> p3;
	p3 = p2;//引用计数 +1
	cout << p1.unique() << ", " << p1.use_count() << endl;
	//指向相同的内存地址
	cout << p1.get() << ", " << p2.get() << ", " << p3.get() << endl;

	//手动分离管理权
	p1.reset(); // 引用计数 -1
	cout << p2.unique() << ", " << p2.use_count() << endl;
	p2.reset();
	p3.reset();//全部释放管理权
	cout << "结束！" << endl;

	return 0;
}
