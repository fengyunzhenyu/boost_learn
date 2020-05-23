#include<iostream>
using namespace std;

#include <boost/unordered_set.hpp>
#include <boost/timer/timer.hpp>

using namespace boost;
using namespace boost::timer;
#include <set>



int main()
{
	//��STL set���ƣ�Ԫ�ؿ����ظ��������������
	unordered_multiset<string> ums;

	ums.insert("111");
	ums.insert("333");
	ums.insert("222");
	ums.insert("333");//�ظ���Ԫ�ؿ��Բ���

	cout << ums.size() << endl;


	auto itt = ums.find("333");//����
	if (itt != ums.end())
	{
		cout << *itt << endl;
	}

	//����,Ԫ���������
	for (auto it = ums.begin(); it != ums.end(); it++)
	{
		cout << *it << " ";
	}
	cout << endl;




	//��������
	unordered_set<int> us2;
	multiset<int> s2;
	for (int i = 0; i < 100000; i++)
	{
		us2.insert(i % 10000);//���Բ����ظ�Ԫ��
		s2.insert(i % 10000);
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