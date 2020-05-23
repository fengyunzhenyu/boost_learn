#include <iostream>
using namespace std;

#include<boost/ref.hpp>

template <class T>
void Fun(T a)
{
	++a;
}

int main()
{
	//使用模板函数
	int a = 10;
	Fun<int>(a);//这里的a不会变成11，因为形参的拷贝
	cout << "a 的值" << a << endl;

	//如何让他改变呢
	Fun<int&>(a);	//T 变为引用
	cout << "a 的值" << a << endl;

	//如何不使用int &,让这个函数可以改变a的值
	Fun(boost::reference_wrapper<int>(a));
	cout << "a 的值" << a << endl;

	Fun(boost::ref(a));
	cout << "a 的值" << a << endl;


	//reference_wrapper 引用包装器，和引用&类似
	int b = 10;
	boost::reference_wrapper<int> rw(b);//rw就是b的引用
	//operator int & ()
	cout << "b的值是" << rw << " " << rw.get() << endl;

	cout << "b的地址是" << &b << " " << rw.get_pointer() << endl;
	
	//rw = 20;//不能直接赋值
	*rw.get_pointer() = 20;
	cout << "改变之后的值" << b << " " << rw.get() << endl;

	//++ 操作
	++rw;//本质是++ &b
	cout << "++之后的值" << b << " " << rw.get() << endl;


	//使用工厂函数，方便的生成reference_wrapper对象
	int c = 10;
	boost::reference_wrapper<int> rc = boost::ref(c);
	++rc;

	boost::reference_wrapper<const int> crc = boost::cref(c);
	//++crc;//常数，不能++
	return 0;
}