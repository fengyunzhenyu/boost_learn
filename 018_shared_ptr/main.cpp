#include<iostream>
using namespace std;

#include<boost/scoped_ptr.hpp>
#include<boost/make_shared.hpp>
using namespace boost;

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
	boost::shared_ptr<A> p1(new A);//��ʼ���ü���Ϊ1
	p1->m_a = 100;
	//��ʱΨһ����A���ڴ�
	cout << p1.unique() << ", " << p1.use_count() << endl;

	//��������
	//��ʱ p1 p2ͬʱ����A���ڴ�
	boost::shared_ptr<A> p2(p1);//���ü��� +1
	cout << p2.unique() << ", " << p2.use_count() << endl;

	//��ֵ�����
	boost::shared_ptr<A> p3;
	p3 = p2;//���ü��� +1
	cout << p1.unique() << ", " << p1.use_count() << endl;
	//ָ����ͬ���ڴ��ַ
	cout << p1.get() << ", " << p2.get() << ", " << p3.get() << endl;

	//�ֶ��������Ȩ
	p1.reset(); // ���ü��� -1
	cout << p2.unique() << ", " << p2.use_count() << endl;
	p2.reset();
	p3.reset();//ȫ���ͷŹ���Ȩ
	cout << "������" << endl;

	return 0;
}
