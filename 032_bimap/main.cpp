#include<iostream>
using namespace std;

#include <boost/bimap.hpp>
#include <boost/timer/timer.hpp>
#include <boost/format.hpp>
using namespace boost;
using namespace boost::timer;
#include <map>



int main()
{
	bimap<int, string> bm;

	//左视图，代表key类型是int，value类型是string
	bm.left.insert(make_pair(1, "AAAA"));
	bm.left.insert(make_pair(1, "AAAAA"));//不能插入重复的key


	//右视图，代表key类型是string，value类型是int
	bm.right.insert(make_pair("BBB", 2));
	bm.right.insert(make_pair("BBB", 222));//不能插入重复的key

	bm.left.insert(make_pair(4, "DDDD"));
	bm.right.insert(make_pair("CCC", 3));

	cout << bm.size() << endl;
	cout << bm.left.size() << ", " << bm.right.size() << endl;

	//查找
	auto it = bm.left.find(2);//左视图的key为整型
	if(it != bm.left.end())
		cout << it->first << "->" << it->second << endl;

	auto it2 = bm.right.find("CCC");//左视图的key为string
	if(it2 != bm.right.end())
		cout << it->first << "->" << it->second << endl;



	//左视图遍历
	for (auto it = bm.left.begin(); it != bm.left.end(); it++)
	{
		cout << it->first << "->" << it->second << endl;
	}

	//右视图遍历
	for (auto it = bm.right.begin(); it != bm.right.end(); it++)
	{
		cout << it->first << "->" << it->second << endl;
	}

	return 0;
}