#include<iostream>
using namespace std;

#include<boost/foreach.hpp>
using namespace boost;
#include<vector>
int main()
{
	//C++ 
	int arr[5] = { 1,2,3,4,5 };
	for (size_t i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;

	//C++11 �ṩ������д��
	for (int e:arr)
	{
		cout << e << " ";
	}
	cout << endl;

	//ʹ��boost
	BOOST_FOREACH(auto& e, arr)//���ŷָ�
	{
		cout << e << " ";
	}
	cout << endl;

	vector<int> v;
	v.push_back(1);
	v.push_back(2);
	v.push_back(3);
	v.push_back(4);
	v.push_back(5);
	v.push_back(6);
	//for (vector<int>::iterator it = v.begin(); it != v.end(); it++)
	BOOST_FOREACH(auto& e, v)
	{
		cout << e << " ";
	}
	cout << endl;

	BOOST_REVERSE_FOREACH(auto& e, v)
	{
		cout << e << " ";
	}
	cout << endl;

	return 0;
}