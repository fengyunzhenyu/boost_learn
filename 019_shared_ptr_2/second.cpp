
#include <iostream>
using namespace std;

#include <boost/make_shared.hpp>
#include <boost/scoped_ptr.hpp>

class B;//���ǰ������

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

	boost::shared_ptr<B>  m_pb;//ָ��B���ڴ�
};


class B
{
public:
	B()
	{
		cout << "����B�����" << endl;
	}

	~B()
	{
		cout << "����B�����" << endl;
	}

	boost::shared_ptr<A> m_pa;//ָ��a���ڴ�
};

int main()
{
	//��������shared_ptrѭ�����õ����ڴ�й©
	boost::shared_ptr<A> pA(new A);
	boost::shared_ptr<B> pB(new B);
	cout << pA.use_count() << " , " << pB.use_count() << endl;

	pA->m_pb = pB; //�˿̣�pBָ����ڴ����ü���Ϊ2
	pB->m_pa = pA; //�˿̣� pAָ����ڴ����ü���Ϊ2
	cout << pA.use_count() << " , " << pB.use_count() << endl;
	/*
	�˿̣�pA��pB������ʱ����ֻ�Ὣ���ü���-1������ʣ�����ü���Ϊ1���򲻻��ͷ�
	�Ӷ�����A��B�ڴ�й©
	*/


	//�����ģ�shared_ptr������ڴ������new������
	int* pInt = (int*)malloc(sizeof(int));
	boost::shared_ptr<int> p(pInt); //�����϶��������



	return 0;
}