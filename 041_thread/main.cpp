#include <boost/thread.hpp>
using namespace boost;

#include <iostream>
using namespace std;

void ThreadFun(string& threadName)
{
	for (size_t i = 0; i < 5; i++)
	{
		printf("%s", threadName.c_str());

		//线程睡眠
		boost::this_thread::sleep(posix_time::seconds(10));
	}
}

int main()
{
	//定义县城对象，线程执行函数，函数参数，构造函数
	boost::thread t1(ThreadFun, string("线程1"));

	boost::thread t2(ThreadFun, string("线程2"));

	t1.join();//先阻塞，等待子线程执行完毕后返回
	t2.join();

	t1.timed_join(posix_time::seconds(8));//如果线程还没有结束，最多等待8秒

	cout << "main 结束 "<< endl;
	return 0;
}