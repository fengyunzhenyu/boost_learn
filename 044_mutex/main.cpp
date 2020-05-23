#include<iostream>
#include<boost\thread.hpp>

using namespace std;
using namespace boost;


//boost::mutex m;//普通mutex枷锁两次会死锁

boost::recursive_mutex m;//递归mutex，可以多次枷锁

void ThreadFun1()
{

	m.lock();//第一次枷锁
	cout << "ThreadFun1第一次加锁" << endl;
	m.lock();//第二次枷锁
	cout << "ThreadFun1第二次加锁" << endl;

	m.unlock();
	cout << "ThreadFun1第一次解锁" << endl;

	boost::this_thread::sleep(boost::posix_time::seconds(8));
	m.unlock();
	cout << "ThreadFun1第二次解锁" << endl;

}

void ThreadFun2()
{
	//保证在线程1后面执行
	boost::this_thread::sleep(boost::posix_time::seconds(1));
	bool b = m.try_lock();//枷锁
	
	cout << "ThreadFun2 枷锁是否成功 " <<b << endl;
	
	m.unlock();


}

int main()
{
	boost::thread t1(ThreadFun1);

	boost::thread t2(ThreadFun2);


	t1.join();
	t2.join();


	return 0;
}