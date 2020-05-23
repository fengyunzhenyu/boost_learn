
#include <iostream>
#include <boost/typeof/typeof.hpp>

using namespace boost;
using namespace std;

int main()
{
	//c++11���Զ������Ƶ�
	auto a = 100; //ͨ��������ֵ�Ƶ�����
	cout << typeid(a).name() << endl;

	auto b = 1.234;//
	cout << typeid(b).name() << endl;

	decltype(a++) c;
	cout << a << typeid(c).name() << endl;

	decltype('A') d;
	cout << typeid(d).name() << endl;

	//boost ��
	BOOST_TYPEOF(1.235 + 100) e; //��decltype����
	cout << typeid(e).name() << endl;

	BOOST_AUTO(f, "sfdddf");//������boost_typeof������� + ��ʼ��
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