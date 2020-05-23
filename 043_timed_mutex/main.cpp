#include<iostream>
using namespace std;

#include<boost\thread.hpp>
#include<boost\thread\mutex.hpp>
using namespace boost;

//��ʱ���ص�mutex
boost::timed_mutex tmx;

void ThreadFun1()
{
	tmx.lock();
	cout << "ThreadFun1 ����ס8��" << endl;
	boost::this_thread::sleep(posix_time::seconds(8));

	tmx.unlock();
	cout << "ThreadFun1 ����" << endl;
}

void ThreadFun2()
{
	boost::this_thread::sleep(posix_time::seconds(1));

	//������סmutex,����������߳���ס���������3�룬Ȼ�󷵻�0
	cout << "ThreadFun2 ���Լ���" << endl;
	bool bLock = tmx.try_lock_for(boost::chrono::seconds(3));//������ʱ���߳�1��Ȼ���ţ������߳�2�޷�����������0
	//bool bLock = tmx.try_lock_for(boost::chrono::seconds(10));//��ʮ��ʱ���߳�1�Ѿ������������߳�2���Լ���������1
	//boost::this_thread::sleep(posix_time::seconds(8));
	cout << "ThreadFun2 �����Ƿ�ɹ�" << bLock << endl;
	tmx.unlock();
	//cout << "ThreadFun2 ����" << endl;
}


int main()
{
	boost::thread t1(ThreadFun1);
	boost::thread t2(ThreadFun2);

	t1.join();
	t2.join();

	return 0;
}
