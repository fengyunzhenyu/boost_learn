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
	//��STL multimap���ƣ�key�ǿ����ظ��������������
	unordered_multimap<int, string> um;

	um.insert(make_pair(1, "111"));
	um.insert(make_pair(2, "333"));//�ظ���key�ǲ����
	um.insert(make_pair(1, "222"));
	//um[2];
	//um[3] = "BBB";//���ṩ[] ���������Ϊͬһ��key���Զ�Ӧ���value
	um.insert(make_pair(3, "222"));

	cout << um.size() << endl;

	//����keyֵΪ1�ĸ���
	cout << um.count(1) << endl;


	auto itt = um.find(1);//����key�鳭
	if (itt != um.end())
	{
		cout << itt->first << "->" << itt->second << endl;
	}

	//��������keyΪ1��
	auto rge = um.equal_range(1);//���ز��ҽ���ķ�Χ
	for (auto it = rge.first; it != rge.second; it++)
	{
		cout << it->first << "->" << it->second << endl;
	}

	//����,Ԫ���������
	//um[3] = "CCC";//����ط��Ǹ�ֵ
	for (auto it = um.begin(); it != um.end(); it++)
	{
		cout << it->first << "->" << it->second << " ";
	}
	cout << endl;




	//��������
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
		auto_cpu_timer t(6, "unordered_map����ʱ��%w\n");
		for (size_t i = 0; i < 10000; i++)
		{
			auto ret = us2.find(i);
		}
	}

	{
		auto_cpu_timer t(6, "map ����ʱ��%w\n");
		for (size_t i = 0; i < 10000; i++)
		{
			auto ret = s2.find(i);
		}
	}


	return 0;
}