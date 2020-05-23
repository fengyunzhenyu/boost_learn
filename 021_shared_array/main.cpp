
#include <iostream>
using namespace std;

#include <boost/make_shared.hpp>
#include <boost/shared_array.hpp>

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
	A* pArr = new A[5];//pArr是数组指针
	//错误
	//boost::shared_ptr<A> p1(pArr);// delete 不能释放数组内存指针，应该使用delete[]

	boost::shared_array<A> p1(pArr);//适合数组内存指针
	cout << p1.unique() << ", " << p1.use_count() << endl;

	boost::shared_array<A> p2(p1);
	cout << p2.unique() << ", " << p2.use_count() << endl;

	return 0;
}