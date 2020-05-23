#include<boost\thread.hpp>
#include<iostream>
using namespace std;
using namespace boost;

//�����Ʊ����ͬʱ��Ʊ����Ʊ��100
int tickets = 100;

//���������
boost::mutex m;

void SellA()
{
	while (true)
	{
		m.lock();//����ͬһ����Դ��ͬһʱ��ֻ��һ������
		if (tickets > 0)
		{
			printf("A ����������%d��Ʊ\n", tickets);
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
			printf("B ����������%d��Ʊ\n", tickets);
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

	cout << "Ʊ������" << endl;


	return 0;
}