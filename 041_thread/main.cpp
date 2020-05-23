#include <boost/thread.hpp>
using namespace boost;

#include <iostream>
using namespace std;

void ThreadFun(string& threadName)
{
	for (size_t i = 0; i < 5; i++)
	{
		printf("%s", threadName.c_str());

		//�߳�˯��
		boost::this_thread::sleep(posix_time::seconds(10));
	}
}

int main()
{
	//�����سǶ����߳�ִ�к������������������캯��
	boost::thread t1(ThreadFun, string("�߳�1"));

	boost::thread t2(ThreadFun, string("�߳�2"));

	t1.join();//���������ȴ����߳�ִ����Ϻ󷵻�
	t2.join();

	t1.timed_join(posix_time::seconds(8));//����̻߳�û�н��������ȴ�8��

	cout << "main ���� "<< endl;
	return 0;
}