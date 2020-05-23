#include<iostream>
using namespace std;

#include<boost\random.hpp>
using namespace boost;

int main()
{
	//����������ת���㷨
	mt19937 mt(time(0));
	cout << "�������Χ��" << mt.min() << "-" << mt.max() << endl;

	for (size_t i = 0; i < 5; i++)
	{
		cout << mt() << " , ";
	}
	cout << endl;

	//rand48 LCG����ͬ���㷨
	rand48 r48;
	cout << "�������Χ��" << r48.min() << "-" << r48.max() << endl;

	for (size_t i = 0; i < 5; i++)
	{
		cout << r48() << " , ";
	}
	cout << endl;

	//С�� �ض��ֲ�0-1
	uniform_01<mt19937> u01(mt);
	for (size_t i = 0; i < 5; i++)
	{
		cout << u01() << " , ";
	}
	cout << endl;

	//�ض��ֲ� 0-100
	uniform_int<> ui(0, 100);
	for (size_t i = 0; i < 5; i++)
	{
		cout << ui(mt) << " , ";
	}
	cout << endl;

	return 0;
}