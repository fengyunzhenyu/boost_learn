#include<iostream>
using namespace std;

#include <boost/array.hpp>
using namespace boost;

int main()
{
	boost::array<int, 6> arr = { 1,2,3,4,5,6 };
	
	//数组大小
	cout << arr.size() << endl;

	//小标访问
	cout << arr[5] << endl;
	cout << arr.at(4) << endl;

	//[] 与at 的区别在于是否跑出异常
	try
	{
		arr[100] = 100;
		arr.at(100) = 100;
	}
	catch (const std::exception& e)
	{
		cout << "抛出异常" << e.what() << endl;
	}


	//第一个  最后一个
	cout << arr.front() << ", " << arr.end() << endl;

	//与算法搭配使用
	copy(arr.cbegin(), arr.cend(), ostream_iterator<int>(cout, " "));


	return 0;
}