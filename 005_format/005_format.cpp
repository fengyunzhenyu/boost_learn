// 005_format.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <boost/format.hpp>

using namespace std;

int main()
{
	using boost::format;//使用format

	//使用一
	format fmt("%1%, %2% !!!");//先定义对象
	fmt % 123;
	fmt% "hello";
	cout << fmt << endl;

	// 使用二，可以不按照顺序，可以重复指定
	format fmt2("%2%---%1% --  %2% !!!");//先定义对象
	fmt2 % 123;
	fmt2 % "hello";
	cout << fmt2 << endl;

	//使用三，可以重复使用
	format fmt3("%2%---%1% --  %2% !!!");//先定义对象
	fmt3 % 123;
	fmt3 % "hello";
	cout << fmt3 << endl;

	fmt3 % 123.345;
	fmt3 % "CCC";
	cout << fmt3 << endl;

	//用法四，链式使用
	cout << format("***%1%***%2%!!") % "hello" % 1.2345f << endl;
	string strFmt;
	strFmt << (format("***%1%***%2%!!") % "hello" % 1.2345f).str(); 
	cout << strFmt << endl;


	//用法五，可以使用printf中的格式符
	cout << format("%d, %c, %f, %s") % 666 % 'A' % 1.23456f % "boost" << endl;

	//N$指定用哪个参数
	cout << format("%2$d, %1$s") % "boost" % 666 << endl;

	//用法六，直接转为string
	int age = 20;
	const char* name = "zhnagsan";
	//替代printf
	format fmt6("name:%1% age:%2%");
	fmt6% name% age;
	string strStu = fmt6.str();//转化为字符串
	cout << strStu << endl;

}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
