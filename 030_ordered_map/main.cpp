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
	//��STL map���ƣ�key�����ظ���value�ǿ����ظ��������������
	unordered_map<int, string> um;

	um.insert(make_pair(1,"111"));
	um.insert(make_pair(2, "333"));//�ظ���key���޷������
	um.insert(make_pair(1, "222"));
	um[2];//��Ȼ������һ��keyΪ2 �ļ�ֵ�ԣ�valueĬ��ֵ
	um[3] = "BBB";//����keyΪ2, value wei BBB�ļ�ֵ��
	

	cout << um.size() << endl;


	auto itt = um.find(2);//����key�鳭
	if (itt != um.end())
	{
		cout << itt->first << "->" << itt->second << endl;
	}

	//����,Ԫ���������
	um[3] = "CCC";//����ط��Ǹ�ֵ
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
		boost::format fmt("%1%");
		fmt% i;
		us2.insert(make_pair(i, fmt.str()));
		s2.insert(make_pair(i, fmt.str()));
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