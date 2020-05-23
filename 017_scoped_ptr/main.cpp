#include<iostream>
using namespace std;

#include<boost/scoped_ptr.hpp>
#include<boost/scoped_array.hpp>
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
	//ע�⣬scoped_ptr���ܽ�������ָ��
	scoped_ptr<A> p1(new A[5]);//�����������ָ��

	//c++�е� new ��delete��Ҫע���
	A* pA = new A;
	delete pA;

	A* pArr = new A[5];
	pArr[3].m_a = 1000;
	(pArr + 3)->m_a = 2000;
	delete []pArr;//ɾ������ָ��

	//ָ�������ڴ��ַ��ָ��
	scoped_array<A> p2(new A[5]);
	for (int i = 0; i < 5; i++)
	{
		p2[i].m_a = i;//֧��[]���ʣ���p2����������ʹ��
	}

	cout << p2[4].m_a << endl;//����������

	(p2 + 3)->m_a = 200;//���ַ�ʽ��֧��

	return 0;
}