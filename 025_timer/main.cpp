
#include <iostream>
#include <Windows.h>
using namespace std;

#include <boost/timer.hpp>
#include <boost/progress.hpp>
using namespace boost;

int main()
{
	timer t;
	/*
	cout << "��󾫶ȣ�" << t.elapsed_max() << endl;
	cout << "��󾫶ȣ�" << t.elapsed_max() / 3600 << "Сʱ" << endl;

	cout << "��С���ȣ�" << t.elapsed_min() << endl;//����

	//�Ӷ����嵽�˿̵�ʱ��
	cout << "���ŵ�ʱ�䣺" << t.elapsed() << endl;
	*/

	Sleep(1234);//˯�ߺ���
	//�Ӷ����嵽�˿̵�ʱ��
	cout << "���ŵ�ʱ�䣺" << t.elapsed() << endl;

	{
		progress_timer  pt;//�̳�timer
		//progress_timer pt2(pt);//noncopyable

		Sleep(2345);//˯��2345����

	}//����ʱ���Զ���ӡ����ʱ��


	return 0;
}