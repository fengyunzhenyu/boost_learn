#include<iostream>
using namespace std;

#include <boost/unordered_map.hpp>
#include <boost/timer/timer.hpp>
#include <boost/format.hpp>
using namespace boost;
using namespace boost::timer;
#include <map>



int main()
{
	//与STL map类似，key不能重复，value是可以重复，区别是无序的
	unordered_map<int, string> um;

	um.insert(make_pair(1,"111"));
	um.insert(make_pair(2, "333"));//重复的key是无法插入的
	um.insert(make_pair(1, "222"));
	um[2];//竟然插入了一个key为2 的键值对，value默认值
	um[3] = "BBB";//插入key为2, value wei BBB的键值对
	

	cout << um.size() << endl;


	auto itt = um.find(2);//根据key查抄
	if (itt != um.end())
	{
		cout << itt->first << "->" << itt->second << endl;
	}

	//遍历,元素是无序的
	um[3] = "CCC";//这个地方是赋值
	for (auto it = um.begin(); it != um.end(); it++)
	{
		cout << it->first << "->" << it->second << " ";
	}
	cout << endl;




	//测试性能
	unordered_map<int, string> us2;
	map<int, string> s2;
	for (int i = 0; i < 100000; i++)
	{
		boost::format fmt("%1%");
		fmt% i;
		us2.insert(make_pair(i, fmt.str()));
		s2.insert(make_pair(i, fmt.str()));
	}

	{
		auto_cpu_timer t(6, "unordered_map消耗时间%w\n");
		for (size_t i = 0; i < 10000; i++)
		{
			auto ret = us2.find(i);
		}
	}

	{
		auto_cpu_timer t(6, "map 消耗时间%w\n");
		for (size_t i = 0; i < 10000; i++)
		{
			auto ret = s2.find(i);
		}
	}


	return 0;
}