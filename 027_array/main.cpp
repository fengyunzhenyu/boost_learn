#include<iostream>
using namespace std;

#include <boost/array.hpp>
using namespace boost;

int main()
{
	boost::array<int, 6> arr = { 1,2,3,4,5,6 };
	
	//�����С
	cout << arr.size() << endl;

	//С�����
	cout << arr[5] << endl;
	cout << arr.at(4) << endl;

	//[] ��at �����������Ƿ��ܳ��쳣
	try
	{
		arr[100] = 100;
		arr.at(100) = 100;
	}
	catch (const std::exception& e)
	{
		cout << "�׳��쳣" << e.what() << endl;
	}


	//��һ��  ���һ��
	cout << arr.front() << ", " << arr.end() << endl;

	//���㷨����ʹ��
	copy(arr.cbegin(), arr.cend(), ostream_iterator<int>(cout, " "));


	return 0;
}