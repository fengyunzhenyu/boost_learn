#include <iostream>
using namespace std;

#include <boost/make_shared.hpp>


class A
{
public:
	A(int a, float b, char c, string d)
	{
		_a = a;
		_b = b;
		_c = c;
		_d = d;
		cout << "����A�����" << endl;
	}

	~A()
	{
		cout << "����A�����" << endl;
	}

	int _a;
	float _b; char _c; string _d;
};

int main()
{
	//ԭʼ�ķ�ʽ����shared_ptr,��Ҫnew������һ�ֲ��Գ�
	boost::shared_ptr<A> p1(new A(100, 1.234f, 'C', "hello"));
	cout << p1->_a << ", " << p1->_b << ", " << p1->_c << ", " << p1->_d << endl;

	//�Ƽ�ʹ�ù�������������new,����Ч
	boost::shared_ptr<A> p2 = boost::make_shared<A>(100, 1.234f, 'C', "hello");
	cout << p2->_a << ", " << p2->_b << ", " << p2->_c << ", " << p2->_d << endl;

	return 0;
}