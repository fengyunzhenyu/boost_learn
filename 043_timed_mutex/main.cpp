#include<iostream>
using namespace std;

#include<boost\thread.hpp>
#include<boost\thread\mutex.hpp>
using namespace boost;

//超时返回的mutex
boost::timed_mutex tmx;

void ThreadFun1()
{
	tmx.lock();
	cout << "ThreadFun1 先锁住8秒" << endl;
	boost::this_thread::sleep(posix_time::seconds(8));

	tmx.unlock();
	cout << "ThreadFun1 解锁" << endl;
}

void ThreadFun2()
{
	boost::this_thread::sleep(posix_time::seconds(1));

	//尝试锁住mutex,如果有其他线程锁住，最多阻塞3秒，然后返回0
	cout << "ThreadFun2 尝试加锁" << endl;
	bool bLock = tmx.try_lock_for(boost::chrono::seconds(3));//第三秒时，线程1仍然锁着，所以线程2无法枷锁，返回0
	//bool bLock = tmx.try_lock_for(boost::chrono::seconds(10));//第十秒时，线程1已经解锁，所以线程2可以加锁，返回1
	//boost::this_thread::sleep(posix_time::seconds(8));
	cout << "ThreadFun2 枷锁是否成功" << bLock << endl;
	tmx.unlock();
	//cout << "ThreadFun2 解锁" << endl;
}


int main()
{
	boost::thread t1(ThreadFun1);
	boost::thread t2(ThreadFun2);

	t1.join();
	t2.join();

	return 0;
}
