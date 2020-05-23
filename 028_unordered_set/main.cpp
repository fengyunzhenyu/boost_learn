#include<iostream>
using namespace std;

#include <boost/unordered_set.hpp>
#include <boost/timer/timer.hpp>

using namespace boost;
using namespace boost::timer;
#include <set>



int main()
{
	//��STL set���ƣ�Ԫ�ز����ظ��������������
	unordered_set<string> us;

	us.insert("111");
	us.insert("333");
	us.insert("222");
	us.insert("333");//�ظ���Ԫ���޷�����

	cout << us.size() << endl;


	auto itt = us.find("333");//����
	if (itt != us.end())
	{
		cout << *itt << endl;
	}

	//����,Ԫ���������
	for (auto it = us.begin(); it != us.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;




	//��������
	unordered_set<int> us2;
	set<int> s2;
	for (int i = 0; i < 100000; i++)
	{
		us2.insert(i);
		s2.insert(i);
	}

	{
		auto_cpu_timer t(6, "unordered_set����ʱ��%w\n");
		for (size_t i = 0; i < 10000; i++)
		{
			auto ret = us2.find(i);
		}
	}

	{
		auto_cpu_timer t(6, "set ����ʱ��%w\n");
		for (size_t i = 0; i < 10000; i++)
		{
			auto ret = s2.find(i);
		}
	}


	return 0;
}