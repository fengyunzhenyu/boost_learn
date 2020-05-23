#include<iostream>
using namespace std;

#include <boost/unordered_set.hpp>
#include <boost/timer/timer.hpp>

using namespace boost;
using namespace boost::timer;
#include <set>



int main()
{
	//与STL set类似，元素可以重复，区别是无序的
	unordered_multiset<string> ums;

	ums.insert("111");
	ums.insert("333");
	ums.insert("222");
	ums.insert("333");//重复的元素可以插入

	cout << ums.size() << endl;


	auto itt = ums.find("333");//查找
	if (itt != ums.end())
	{
		cout << *itt << endl;
	}

	//遍历,元素是无序的
	for (auto it = ums.begin(); it != ums.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;




	//测试性能
	unordered_set<int> us2;
	multiset<int> s2;
	for (int i = 0; i < 100000; i++)
	{
		us2.insert(i % 10000);//可以插入重复元素
		s2.insert(i % 10000);
	}

	{
		auto_cpu_timer t(6, "unordered_set消耗时间%w\n");
		for (size_t i = 0; i < 10000; i++)
		{
			auto ret = us2.find(i);
		}
	}

	{
		auto_cpu_timer t(6, "set 消耗时间%w\n");
		for (size_t i = 0; i < 10000; i++)
		{
			auto ret = s2.find(i);
		}
	}


	return 0;
}