
#include <iostream>
#include <boost/typeof/typeof.hpp>

using namespace boost;
using namespace std;

int main()
{
	//c++11的自动类型推导
	auto a = 100; //通过变量的值推导类型
	cout << typeid(a).name() << endl;

	auto b = 1.234;//
	cout << typeid(b).name() << endl;

	decltype(a++) c;
	cout << a << typeid(c).name() << endl;

	decltype('A') d;
	cout << typeid(d).name() << endl;

	//boost 宏
	BOOST_TYPEOF(1.235 + 100) e; //和decltype类型
	cout << typeid(e).name() << endl;

	BOOST_AUTO(f, "sfdddf");//是利用boost_typeof定义变量 + 初始化
	cout << f << typeid(f).name() << endl;


	BOOST_AUTO(g, 1245);
	cout << g << typeid(g).name() << endl;

	//for (int i = 0;     i < 10; i++)
	for(BOOST_AUTO(i, 0); i < 10; i++)
	{
		cout << i << endl;
	}

	return 0;
}