#include <iostream>
using namespace std;

#include <boost/make_shared.hpp>
#include <boost/shared_array.hpp>
#include <boost/noncopyable.hpp>

//class B;//���ǰ������

//class A
//{
//public:
//	A()	{cout << "����A�����" << endl;}
//
//	~A(){cout << "����A�����" << endl;}
//
//
//private: //���ɣ�����ʹ�ÿ������캯��
//	A(const A& a){ cout << "��������A�����" << endl; }//�������캯��
//	A& operator=(const A& a)//��ֵ����
//	{
//		cout << "��ֵA�����" << endl;
//		return *this;
//	}
//
//};

class A:public boost::noncopyable  //���ɵĽ�ֹ��Ŀ�����ֵ
{
public:
	A() { cout << "����A�����" << endl; }

	~A() { cout << "����A�����" << endl; }

};

int main()
{
	A a;

	A b(a);

	A a2 = a;//���õ���Ȼ�ǿ�������

	A c;
	c = a;//���õĲ��� = ��ֵ


	return 0;
}