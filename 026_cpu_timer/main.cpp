#include <iostream>
using namespace std;

#include <Windows.h>

#include <boost/timer/timer.hpp>
using namespace boost::timer;

int main()
{
	cpu_timer t;//�Զ�start

	//t.start();

	Sleep(1234);//˯��

	//t.stop();


	//for (size_t i = 0; i < 1000*10000; i++)
	//{
	//	int a = 100 * i;
	//}
	//Ĭ�ϸ�ʽ 1.235031s wall, 0.000000s user + 0.000000s system = 0.000000s CPU(n / a%)
	string str = t.format();
	//string str = t.format(6, "����ʱ�� %w ��");

	cout << str << endl;



	cout << "------------auto_cpu_timer-----------" << endl;
	{

		auto_cpu_timer t2(5, "����ʱ�� %w ��");
		Sleep(3456);

	}//t2����ʱ�Զ���ӡ���ĵ�ʱ��


	return 0;
}