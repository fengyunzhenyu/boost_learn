#include<iostream>
using namespace std;
#include<functional>

#include<boost\bind.hpp>

int f1(int a)
{
	return a * a;
}

int f2(int a, int b)
{
	return a + b;
}

class A
{
public:
	int f1(int a)
	{
		return a * a;
	}

	static int f2(int a, int b)
	{
		return a + b;
	}
};

int main()
{
	//复习bind1st, bind2nd
	cout << "x < y " << less<int>()(3, 4) << endl;
	//只需要一个参数
	cout << "3 < y " << bind1st(less<int>(), 3)(4) << endl;

	cout << " x < 4 " << bind2nd(less<int>(), 4)(3) << endl;

	////////////////////////////////////////////////////
	cout << "f1(2) " << bind(f1, 2)() << endl;
	cout << "f2(2,3) " << bind(f2, 2, 3)() << endl;
	//使用占位符
	cout << "f2(2,3) " << bind(f2, _1, _2)(2, 3) << endl;

	//绑定类的普通成员函数
	A a;
	cout << "A::f1(2) " << bind(&A::f1, a, 2)() << endl;

	//绑定类的静态成员函数
	cout << "A::f2(2,3) " << bind(&A::f2, 2, 3)() << endl;


	return 0;
}