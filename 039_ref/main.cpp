#include <iostream>
using namespace std;

#include<boost/ref.hpp>

template <class T>
void Fun(T a)
{
	++a;
}

int main()
{
	//ʹ��ģ�庯��
	int a = 10;
	Fun<int>(a);//�����a������11����Ϊ�βεĿ���
	cout << "a ��ֵ" << a << endl;

	//��������ı���
	Fun<int&>(a);	//T ��Ϊ����
	cout << "a ��ֵ" << a << endl;

	//��β�ʹ��int &,������������Ըı�a��ֵ
	Fun(boost::reference_wrapper<int>(a));
	cout << "a ��ֵ" << a << endl;

	Fun(boost::ref(a));
	cout << "a ��ֵ" << a << endl;


	//reference_wrapper ���ð�װ����������&����
	int b = 10;
	boost::reference_wrapper<int> rw(b);//rw����b������
	//operator int & ()
	cout << "b��ֵ��" << rw << " " << rw.get() << endl;

	cout << "b�ĵ�ַ��" << &b << " " << rw.get_pointer() << endl;
	
	//rw = 20;//����ֱ�Ӹ�ֵ
	*rw.get_pointer() = 20;
	cout << "�ı�֮���ֵ" << b << " " << rw.get() << endl;

	//++ ����
	++rw;//������++ &b
	cout << "++֮���ֵ" << b << " " << rw.get() << endl;


	//ʹ�ù������������������reference_wrapper����
	int c = 10;
	boost::reference_wrapper<int> rc = boost::ref(c);
	++rc;

	boost::reference_wrapper<const int> crc = boost::cref(c);
	//++crc;//����������++
	return 0;
}