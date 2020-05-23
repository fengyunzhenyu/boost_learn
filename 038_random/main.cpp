#include<iostream>
using namespace std;

#include<boost\random.hpp>
using namespace boost;

int main()
{
	//马特赛特旋转演算法
	mt19937 mt(time(0));
	cout << "随机数范围：" << mt.min() << "-" << mt.max() << endl;

	for (size_t i = 0; i < 5; i++)
	{
		cout << mt() << " , ";
	}
	cout << endl;

	//rand48 LCG线性同余算法
	rand48 r48;
	cout << "随机数范围：" << r48.min() << "-" << r48.max() << endl;

	for (size_t i = 0; i < 5; i++)
	{
		cout << r48() << " , ";
	}
	cout << endl;

	//小数 特定分布0-1
	uniform_01<mt19937> u01(mt);
	for (size_t i = 0; i < 5; i++)
	{
		cout << u01() << " , ";
	}
	cout << endl;

	//特定分布 0-100
	uniform_int<> ui(0, 100);
	for (size_t i = 0; i < 5; i++)
	{
		cout << ui(mt) << " , ";
	}
	cout << endl;

	return 0;
}