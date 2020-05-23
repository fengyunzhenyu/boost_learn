#include<iostream>
using namespace std;

#include <boost/circular_buffer.hpp>
#include <boost/timer/timer.hpp>
#include <boost/format.hpp>
using namespace boost;
using namespace boost::timer;
#include <map>



int main()
{

	//���λ��壬�����
	circular_buffer<int> cb(3);//����Ϊ3
	cb.push_back(1);//��β������
	cb.push_back(2);
	cb.push_back(3);//��������
	for (auto it = 0; it < cb.size(); it++)
	{
		cout << cb[it] << " ";
	}
	cout << endl;

	//cb.push_front(1);//��ͷ������
	//cb.push_front(2);
	//cb.push_front(3);//��������

	//�����������ٴβ��룬�߳�ͷ��Ԫ��
	cb.push_back(4);
	for (auto it = 0; it < cb.size(); it++)
	{
		cout << cb[it] << " ";
	}
	cout << endl;

	//����������ͷ�����룬�߳�β��Ԫ��
	cb.push_front(5);
	for (auto it = 0; it < cb.size(); it++)
	{
		cout << cb[it] << " ";
	}
	cout << endl;

	cb.pop_back();//ɾ��β����Ԫ��

	cb.pop_front();//ɾ��ͷ����Ԫ��

	return 0;
}