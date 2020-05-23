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

	int m_a;
};

int main()
{
	boost::shared_ptr<A> p1(new A);//���ü��� +1
	p1->m_a = 1000;

	boost::shared_ptr<A> p2(p1);//���ü��� +1

	cout << p1.use_count() << ", " << p2.use_count() << endl;

	boost::weak_ptr<A> w1(p1);//��Ӱ�����ü������۲���
	cout << w1.expired() << ", " << w1.use_count() << endl;

	//�˿̣���p1�ͷŹ���Ȩ
	p1.reset();//���ü���-1
	cout << p1.get() << ", " << p1.use_count() << endl;

	//ͨ��w1���۲죨�ɴ˿ɼ�����Ȼp1�����˹���Ȩ������w1��Ȼ������������
	cout << w1.expired() << ", " << w1.use_count() << endl;

	if (w1.expired())//�۲���ڴ��ͷ���
	{
		cout << "�ڴ��ͷ���" << endl;
	}
	else
	{
		//cout << p1->m_a << endl;//�����Ѿ���������Ȩ��
		//w1->m_a;//����weak_ptr����->, ���ܹ�*
		boost::shared_ptr<A> p3 = w1.lock();//����ʹ��lock���ع���shared_ptr
		cout << p3->m_a << endl;

	}

	return 0;
}