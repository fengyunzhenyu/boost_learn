
#include <iostream>
using namespace std;

#include <boost/make_shared.hpp>
#include <boost/scoped_ptr.hpp>
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

	int m_a;
};
int main()
{
	//����1����Ҫ��ջ�ڴ��ַ����scoped_ptr��scoped_array��shared_ptr
	int a = 100;
	boost::shared_ptr<int> p(&a);
	cout << p.use_count() << endl;//����ʱ����


	//�������shared_ptr���ܶ������ͬһԭʼָ�룬����ͬһ�ڴ�ᱻdelete���
	A* pA = new A;
	boost::shared_ptr<A> p1(pA);
	cout << p1.use_count() << endl;

	boost::shared_ptr<A> p2(pA);//����p2����֪��p1�Ĵ���
	cout << p2.use_count() << endl;
	//p1 p2�ڶ�������ʱ�������delete pA���Ӷ�����
	//boost::shared_ptr<A> p2(p1);//��ȷ��д��

	return 0;
}