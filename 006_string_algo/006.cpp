#include <iostream>

//string_algo 库的头文件
#include <boost/algorithm/string.hpp>

using namespace boost;
using namespace std;

int main()
{
	//大小写转换
	string str1 = "abc";
	to_upper(str1);//改变原字符串
	cout << str1 << endl;

	to_lower(str1);//改变原字符串
	cout << str1 << endl;

	string str2 = to_upper_copy(str1);//不改变原有字符串
	cout << str1 << endl;
	cout << str2 << endl;

	//判断式，返回bool
	cout << "--判断式---" << endl;
	cout << starts_with("Hello World", "He") << endl;//大小写敏感
	cout << starts_with("Hello World", "he") << endl;
	cout << istarts_with("Hello World", "he") << endl;//i大小写不敏感

	cout << ends_with("Hello World", "ld") << endl;//大小写敏感
	//cout << starts_with("Hello World", "he") << endl;
	cout << iends_with("Hello World", "Ld") << endl;//i大小写不敏感


	cout << contains("Hello World", "llo") << endl;//大小写敏感
	cout << icontains("Hello World", "LLO") << endl;//大小写不敏感


	cout << equals("abc", "abc") << endl;//内容是否相等
	cout << iequals("abc", "ABC") << endl;//内容是否相等，i忽略大小写

	cout << all("Hello", is_lower()) << endl;//判断每一个字符是否全是小写
	cout << all("hello", is_lower()) << endl;//

	cout << lexicographical_compare("abc", "xyz") << endl;//字典次序第一个是否小于后面的
	cout << ilexicographical_compare("abc", "XYZ") << endl;//i忽略大写小写

	cout << "判断式，函数对象" << endl;
	cout << is_equal()("abc", "abc") << endl;//内容是否相等，i忽略大小写
	is_equal eq;
	cout << eq("abc", "abc") << endl;
	cout << is_less()("abc", "xyz") << endl;//内容是否小于
	cout << is_not_greater()("abc", "xyz") << endl;//内容是否不大于

	cout << "分类" << endl;
	cout << is_alnum()('1') << endl;//判断是否是字母或者数字
	cout << is_alnum()('a') << endl;
	cout << is_alnum()(',') << endl;

	cout << is_alpha()('A') << endl;//是否字母
	cout << is_digit()('1') << endl;//是否数字
	cout << is_cntrl()('\n') << endl;//是否控制字符
	cout << is_any_of("ABCD")('A') << endl;//是否是ABCD中的任意一个

	cout << is_xdigit()('Q') << endl;//是否是16进制的字符
	cout << is_lower()('a') << endl;//是否小写字符


	return 0;
}