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

	//����ͼ������key������int��value������string
	bm.left.insert(make_pair(1, "AAAA"));
	bm.left.insert(make_pair(1, "AAAAA"));//���ܲ����ظ���key


	//����ͼ������key������string��value������int
	bm.right.insert(make_pair("BBB", 2));
	bm.right.insert(make_pair("BBB", 222));//���ܲ����ظ���key

	bm.left.insert(make_pair(4, "DDDD"));
	bm.right.insert(make_pair("CCC", 3));

	cout << bm.size() << endl;
	cout << bm.left.size() << ", " << bm.right.size() << endl;

	//����
	auto it = bm.left.find(2);//����ͼ��keyΪ����
	if(it != bm.left.end())
		cout << it->first << "->" << it->second << endl;

	auto it2 = bm.right.find("CCC");//����ͼ��keyΪstring
	if(it2 != bm.right.end())
		cout << it->first << "->" << it->second << endl;



	//����ͼ����
	for (auto it = bm.left.begin(); it != bm.left.end(); it++)
	{
		cout << it->first << "->" << it->second << endl;
	}

	//����ͼ����
	for (auto it = bm.right.begin(); it != bm.right.end(); it++)
	{
		cout << it->first << "->" << it->second << endl;
	}

	return 0;
}