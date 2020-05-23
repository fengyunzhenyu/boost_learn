
#include <iostream>
#include <boost/algorithm/string.hpp>
#include <vector>
#include <boost/typeof/typeof.hpp>
using namespace std;
using namespace boost;

int main()
{
	//分割字符串
	cout << "分割字符串" << endl;
	string str = "aaBBccAaXXaa";
	vector<string> v;//标准容器存放结果

	ifind_all(v, str, "aa");
	//for (vector<string>::iterator it = v.begin; it != v.end(); ++it)
	for(BOOST_AUTO(it, v.begin()); it != v.end(); ++it)
	{
		cout << *it << endl;
	}

	vector<iterator_range<string::iterator> > v2;
	ifind_all(v2, str, "aa");
	for (BOOST_AUTO(it, v2.begin()); it != v2.end(); ++it)
	{
		cout << it->begin() - str.begin() << "," << it->end() - str.begin() << endl;
	}

	//使用split分割
	string str2 = "AA*BB*CC-DD";
	list<string> l;

	split(l, str2, is_any_of("*"));//分隔符指定为* -
	for (auto e : l)
	{
		cout << e << endl;
	}


	// 合并字符串
	deque<string> d;
	d.push_back("AA");
	d.push_back("BB");
	d.push_back("CC");

	string str3 = join(d, "**");
	cout << str3 << endl;

	struct is_str
	{
		bool operator()(const string& str)
		{
			return starts_with(str, "A") || ends_with(str, "B");
		}
	};
	string str4 = join_if(d, "**", is_str());
	cout << str << endl;
	return 0;
}

