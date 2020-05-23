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
	//与STL multimap类似，key是可以重复，区别是无序的
	unordered_multimap<int, string> um;

	um.insert(make_pair(1, "111"));
	um.insert(make_pair(2, "333"));//重复的key是插入的
	um.insert(make_pair(1, "222"));
	//um[2];
	//um[3] = "BBB";//不提供[] 运算符，因为同一个key可以对应多个value
	um.insert(make_pair(3, "222"));

	cout << um.size() << endl;

	//返回key值为1的个数
	cout << um.count(1) << endl;


	auto itt = um.find(1);//根据key查抄
	if (itt != um.end())
	{
		cout << itt->first << "->" << itt->second << endl;
	}

	//查找所有key为1的
	auto rge = um.equal_range(1);//返回查找结果的范围
	for (auto it = rge.first; it != rge.second; it++)
	{
		cout << it->first << "->" << it->second << endl;
	}

	//遍历,元素是无序的
	//um[3] = "CCC";//这个地方是赋值
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
		int elem = i % 10000;
		boost::format fmt("%1%");
		fmt% elem;
		us2.insert(make_pair(elem, fmt.str()));
		s2.insert(make_pair(elem, fmt.str()));
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