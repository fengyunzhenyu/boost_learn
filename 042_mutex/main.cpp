#include<boost\thread.hpp>
#include<iostream>
using namespace std;
using namespace boost;

//多个售票窗口同时卖票，总票数100
int tickets = 100;

//定义胡吃两
boost::mutex m;

void SellA()
{
	while (true)
	{
		m.lock();//保护同一种资源，同一时刻只有一个访问
		if (tickets > 0)
		{
			printf("A 窗口卖出第%d张票\n", tickets);
			--tickets;
		}
		m.unlock();
		if (tickets <= 0)
		{
			break;
		}
		boost::this_thread::sleep(posix_time::seconds(1));
		
	}
}


void SellB()
{
	while (true)
	{
		m.lock();
		if (tickets > 0)
		{
			printf("B 窗口卖出第%d张票\n", tickets);
			--tickets;
		}
		m.unlock();
		if (tickets <= 0)
		{
			break;
		}
		boost::this_thread::sleep(posix_time::seconds(1));
		
	}
}

int main()
{
	boost::thread a(SellA);
	boost::thread b(SellB);

	a.join();
	b.join();

	cout << "票卖光了" << endl;


	return 0;
}