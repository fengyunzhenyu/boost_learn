
#include <boost/algorithm/string.hpp>
#include <iostream>

using namespace boost;
using namespace std;

int main()
{
	//修剪（去除左右的空白字符
	string str = "   Hello   ";
	cout << str << endl;
	trim(str);//直接修改原字符串
	cout << str << endl;
	
	string str2 = "   Hello  ";
	cout << trim_copy(str2) << endl;//不修改原字符串
	cout << str2 << endl;

	struct is_xing//函数对象
	{
		bool operator()(const char c)
		{
			return c == '*';
		}
	};
	string str3 = "******Hello****";
	trim_if(str3, is_xing());
	cout << str3 << endl;


	//查找
	string str4 = "Hello,Hello, hello, Boost!!!";
	iterator_range<string::iterator> rge;

	rge = find_first(str4, "hello");//查找第一次出现的字符串
	//rge = ifind_first(str4, "hello");
	cout << rge << endl;
	cout << rge.begin() - str4.begin() << "," << rge.end() - str4.begin() << endl;
	
	rge = find_last(str4, "hello");//查找最后一次出现的字符串
	//rge = ifind_first(str4, "hello");
	cout << rge << endl;
	cout << rge.begin() - str4.begin() << "," << rge.end() - str4.begin() << endl;

	rge = find_nth(str4, "o", 4);//查找第几次出现的字符串
	cout << rge << endl;
	cout << rge.begin() - str4.begin() << "," << rge.end() - str4.begin() << endl;

	rge = find_head(str4, 4);//查找前四个字符
	cout << rge << endl;
	cout << rge.begin() - str4.begin() << "," << rge.end() - str4.begin() << endl;


	//替换、删除
	string str5 = "Hello,Hello, hello, Boost!!!";
	ireplace_first(str5, "Hello", "XXX");//替换第一个，不区分大小写
	cout << str5 << endl;

	replace_all(str5, "hello", "YYY");//替换全部
	cout << str5 << endl;

	erase_last(str5, "YYY");//删除最后一个
	cout << str5 << endl;

	return 0;
}