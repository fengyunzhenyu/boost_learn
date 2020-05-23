#include<iostream>
using namespace std;

#include <boost/circular_buffer.hpp>
#include <boost/timer/timer.hpp>
#include <boost/format.hpp>
using namespace boost;
using namespace boost::timer;
#include <map>



int main()
{

	//环形缓冲，像队列
	circular_buffer<int> cb(3);//容量为3
	cb.push_back(1);//从尾部插入
	cb.push_back(2);
	cb.push_back(3);//容量已满
	for (auto it = 0; it < cb.size(); it++)
	{
		cout << cb[it] << " ";
	}
	cout << endl;

	//cb.push_front(1);//从头部插入
	//cb.push_front(2);
	//cb.push_front(3);//容量已满

	//容量已满，再次插入，踢出头部元素
	cb.push_back(4);
	for (auto it = 0; it < cb.size(); it++)
	{
		cout << cb[it] << " ";
	}
	cout << endl;

	//容量已满，头部插入，踢出尾部元素
	cb.push_front(5);
	for (auto it = 0; it < cb.size(); it++)
	{
		cout << cb[it] << " ";
	}
	cout << endl;

	cb.pop_back();//删除尾部的元素

	cb.pop_front();//删除头部的元素

	return 0;
}