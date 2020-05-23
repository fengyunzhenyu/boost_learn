
#include <iostream>
using namespace std;

#include <boost/make_shared.hpp>
#include <boost/shared_array.hpp>

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
	A* pArr = new A[5];//pArr������ָ��
	//����
	//boost::shared_ptr<A> p1(pArr);// delete �����ͷ������ڴ�ָ�룬Ӧ��ʹ��delete[]

	boost::shared_array<A> p1(pArr);//�ʺ������ڴ�ָ��
	cout << p1.unique() << ", " << p1.use_count() << endl;

	boost::shared_array<A> p2(p1);
	cout << p2.unique() << ", " << p2.use_count() << endl;

	return 0;
}