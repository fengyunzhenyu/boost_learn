#include <iostream>
using namespace std;

#include <boost/make_shared.hpp>
#include <boost/shared_array.hpp>
#include <boost/weak_ptr.hpp>

//class B;//���ǰ������

class A
{
public:
	A()
	{
		cout << "����A�����" << endl;
	}

	~A()
	{
		cout << "����A�����" << endl;
	}

	//boost::shared_ptr<B>  m_pb;//ָ��B���ڴ�
	int m_a;
};


int main()
{

	boost::shared_ptr<A> p1(new A);//���ü��� +1
	cout << p1.unique() << ", " << p1.use_count() << endl;

	//weak_ptr��shared_ptr��Э���ߣ�������һ����ǣ���Ҫ���ڹ۲�
	boost::weak_ptr<A> p2(p1);//���ı����ü���
	cout << p1.unique() << ", " << p1.use_count() << endl;
	cout << p2.expired()/*���ڹ۲�shared_ptrָ����ڴ��Ƿ��ͷ�*/ << ", " << p2.use_count() << endl;

	//weak_ptr����������ڴ�
	//p2->m_a; ����

	boost::shared_ptr<A> p3(p1);//���ü��� +1
	boost::shared_ptr<A> p4(p3);//���ü��� +1

	//��weak_ptr�۲�һ��
	cout << p2.expired()/*���ڹ۲�shared_ptrָ����ڴ��Ƿ��ͷ�*/ << ", " << p2.use_count() << endl;

	//�ͷŹ���Ȩ�����ü���-1
	p1.reset();
	cout << p2.expired()/*���ڹ۲�shared_ptrָ����ڴ��Ƿ��ͷ�*/ << ", " << p2.use_count() << endl;

	p3.reset();
	cout << p2.expired()/*���ڹ۲�shared_ptrָ����ڴ��Ƿ��ͷ�*/ << ", " << p2.use_count() << endl;

	p4.reset();
	cout << p2.expired()/*����1 ��ʾ�ڴ����ͷ�*/ << ", " << p2.use_count() << endl;


	return 0;
}