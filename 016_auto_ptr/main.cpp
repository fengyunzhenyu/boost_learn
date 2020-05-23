#include<iostream>
using namespace std;

#include<boost/scoped_ptr.hpp>
using namespace boost;

class A
{
public:
	A(int _a) :m_a(_a)
	{
		cout << "����A�����" << endl;
	}

	~A()
	{
		cout << "����A�����" << endl;
	}

	int m_a;
};

int main()
{
	//C++ 98 ��auto_ptr
	auto_ptr<A> p1(new A(100));
	cout << p1->m_a << endl;

	auto_ptr<A> p2(p1);//���ÿ������캯������ʱp1ʧȥ����Ȩ
	//auto_ptr<A> p3;
	//p3 = p1;//���ø�ֵ��������ʱp1ʧȥ����Ȩ
	//p1->m_a = 2000;//����
	cout << p1.get() << endl;//ΪNULL

	cout << p2->m_a << endl;

	auto_ptr<A> p3;
	p3 = p1;//���ø�ֵ��������ʱp1ʧȥ����Ȩ


	
	//ʹ��boost�� scoped_ptr

	scoped_ptr<A> s1(new A(1000));
	s1->m_a = 100;

	scoped_ptr<A> s2(s1);//�������캯����˽�е�private
	scoped_ptr<A> s3;
	s3 = s1; //=��������غ�����˽�е�private 
















	return 0;
}