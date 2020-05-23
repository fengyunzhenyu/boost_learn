#include<iostream>
#include<boost\thread.hpp>

using namespace std;
using namespace boost;


//boost::mutex m;//��ͨmutex�������λ�����

boost::recursive_mutex m;//�ݹ�mutex�����Զ�μ���

void ThreadFun1()
{

	m.lock();//��һ�μ���
	cout << "ThreadFun1��һ�μ���" << endl;
	m.lock();//�ڶ��μ���
	cout << "ThreadFun1�ڶ��μ���" << endl;

	m.unlock();
	cout << "ThreadFun1��һ�ν���" << endl;

	boost::this_thread::sleep(boost::posix_time::seconds(8));
	m.unlock();
	cout << "ThreadFun1�ڶ��ν���" << endl;

}

void ThreadFun2()
{
	//��֤���߳�1����ִ��
	boost::this_thread::sleep(boost::posix_time::seconds(1));
	bool b = m.try_lock();//����
	
	cout << "ThreadFun2 �����Ƿ�ɹ� " <<b << endl;
	
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