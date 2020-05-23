#include <iostream>
using namespace std;

#include <Windows.h>

#include <boost/timer/timer.hpp>
using namespace boost::timer;

int main()
{
	cpu_timer t;//自动start

	//t.start();

	Sleep(1234);//睡眠

	//t.stop();


	//for (size_t i = 0; i < 1000*10000; i++)
	//{
	//	int a = 100 * i;
	//}
	//默认格式 1.235031s wall, 0.000000s user + 0.000000s system = 0.000000s CPU(n / a%)
	string str = t.format();
	//string str = t.format(6, "消耗时间 %w 秒");

	cout << str << endl;



	cout << "------------auto_cpu_timer-----------" << endl;
	{

		auto_cpu_timer t2(5, "消耗时间 %w 秒");
		Sleep(3456);

	}//t2析构时自动打印消耗的时间


	return 0;
}