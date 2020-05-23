#include <iostream>
using namespace std;

#include <boost/make_shared.hpp>
#include <boost/shared_array.hpp>
#include <boost/noncopyable.hpp>

//class B;//类的前置声明

//class A
//{
//public:
//	A()	{cout << "构造A类对象！" << endl;}
//
//	~A(){cout << "析构A类对象！" << endl;}
//
//
//private: //技巧，避免使用拷贝构造函数
//	A(const A& a){ cout << "拷贝构造A类对象！" << endl; }//拷贝构造函数
//	A& operator=(const A& a)//赋值函数
//	{
//		cout << "赋值A类对象" << endl;
//		return *this;
//	}
//
//};

class A:public boost::noncopyable  //轻松的禁止类的拷贝赋值
{
public:
	A() { cout << "构造A类对象！" << endl; }

	~A() { cout << "析构A类对象！" << endl; }

};

int main()
{
	A a;

	A b(a);

	A a2 = a;//调用的依然是拷贝构造

	A c;
	c = a;//调用的才是 = 赋值


	return 0;
}