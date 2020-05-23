

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
using namespace boost;
using namespace boost::property_tree;
#include<Windows.h>
#include<iostream>
using namespace std;

int main()
{
	//定义basic_ptree<std::string, std::string> 对象
	ptree pt;

	//读取json文件
	read_json("test.json", pt);

	//解析json内容
	cout << "姓名：" << pt.get<string>("stu.name") << endl;
	{
		//中文的情况下
		//仅仅为了输出

		string str = pt.get<string>("stu.name");
		cout << str.length() << endl;//小明 两个中文占了6个字节，说明是utf-8编码
		//cout无法输出utf-8的编码
		//下面考虑utf-8转换为Unicode，用wstring接收，然后用wcount输出

		//求转换为Unicode需要多大的空间存放
		int len = MultiByteToWideChar(CP_UTF8, NULL, str.data(), str.length(), NULL, 0);
		//开始转换编码
		wchar_t* pw = new wchar_t[len + 1];
		MultiByteToWideChar(CP_UTF8, NULL, str.data(), str.length(), pw, len + 1);
		pw[len] = '\0';
		//设置wcout本地环境
		wcout.imbue(locale("", LC_CTYPE));
		wcout << L"姓名：" << pw << endl;
	}
	cout << "年龄：" << pt.get<int>("stu.age") << endl;
	cout << "成绩：" << pt.get<float>("score") << endl;
	cout << "性别：" << pt.get<string>("sex","保密") << endl;

	//属性下面是数组
	auto pt2 = pt.get_child("lesson");
	for (auto it = pt2.begin(); it != pt2.end(); it++)
	{
		cout << it->second.data() << endl;
	}

	return 0;
}