
#include<iostream>

using namespace std;

#include<boost/date_time/gregorian/gregorian.hpp>
using namespace boost::gregorian;

#pragma comment(lib, "libboost_date_time-vc142-mt-gd-x32-1_72.lib")

/*date_time库提供了时间日期相关的计算、格式化、转换、输入输出等功能，为C++的日期时间编程提供了极大便利*/
int main()
{
	/*date类是date_time库处理日期的核心类，以天为单位
	表示时间点概念，date支持比较操作和输入输出，我们可以
	完全可以把它当成一个像int、string那样的基本类型来使用*/
	//构造日期
	date d1(2000, 1, 1);
	date d2 = from_string("2010-02-02");
	date d3 = from_string("2010/03/03");
	date d4 = from_undelimited_string("20100404");

	date d5(min_date_time);//特殊时间值 1400-01-01
	date d6(max_date_time);//特殊时间值 9999-12-31
	cout << d1.year() << "年" << d1.month() << "月" << d1.day() << "日" << endl;
	cout << d1.year() << "年" <<(int) d1.month() << "月" << d1.day() << "日" << endl;
	cout << to_simple_string(d2) << endl;//YYYY-MMM-DD
	cout << to_iso_string(d3) << endl;//YYYYMMDD
	cout << to_iso_extended_string(d4) << endl;//YYYY-MM-DD
	cout << to_simple_string(d5) << endl;
	cout << to_simple_string(d6) << endl;

	//获取今天的日期
	date today = day_clock::local_day();
	cout <<"年"<< today.year() << endl;
	cout <<"月"<< today.month() << endl;
	cout <<"日"<< today.day() << endl;
	cout << "星期" << today.day_of_week() << endl;
	cout << "一年中的第几周" << today.week_number() << endl;
	cout << "一年中的第多少天" << today.day_of_year() << endl;
	cout << "这个月的结束日期" << today.end_of_month() << endl;

	//时间长度（最小单位是 天）
	days day1(10);
	days day2(-5);
	date_duration du1 = day1 + day2;
	cout << "10天-5天" << du1.days() << endl;

	weeks w1(1);
	cout << "一周的天数" << w1.days() << endl;
	date_duration du2 = w1 + day1;
	cout << "1周+10天" << du2.days() << endl;

	months mon1(1);//一个月无法知道是多少天，并且无法加天数
	cout << "一个月" << mon1.number_of_months() << endl;
	
	years year1(1);//一年无法知道是多少天，并且无法加天数
	cout << "一年" << year1.number_of_years() << endl;

	//如何知道一年多少个月
	months mon2 = year1 + months(0);
	cout << "一年多少个月" << mon2.number_of_months() << endl;


	//日期+日期长度 = 新日期
	date d10(2018, 1, 31);
	cout << "几天往前推10天是几月几日" << d10 + days(-10) << endl;

	cout << "今天往后加2周是几月几日" << to_iso_extended_string(d10 + weeks(2)) <<endl;

	cout << "今天往后推一年是几月几日" << to_iso_extended_string(d10 + years(1)) << endl;


	/*date_period类用来表示日期范围的概念，他是时间轴上一个左闭右开区间，端点是两个date对象*/
	date d11(2000, 1, 1);
	date d22(2000, 2, 1);
	//构造一个日期范围
	date_period dp1(d11, d22);//两个日期确定一个范围
	cout << dp1 << endl;//左闭右开区间，不包含2000年2月1日
	cout << dp1.length() << endl;//返回这个范围的天数

	//把日期范围平移
	dp1.shift(date_duration(10));
	cout << dp1 << endl;//向后移动10天

	//把日期向两边延伸
	dp1.expand(date_duration(1));//向两边移动一天
	cout << dp1 << endl;

	//检测某个日期是否在这个日期范围里面
	cout << dp1.contains(date(2000, 1, 20)) << endl;


	//日期迭代器
	date dd(2000, 1, 1);
	day_iterator it1(dd);//默认步长是1
	//day_iterator it1(dd, 10);
	++it1;//不会影响原日期dd，只输出结果
	cout << *it1 << endl;

	week_iterator it2(dd, 2);
	--it2;//向前移动两周
	cout << "week_iterator" << *it2 << endl;

	month_iterator it3(dd, 1);
	--it3;//向前移动一个月
	cout << "month_iterator" << *it3 << endl;

	year_iterator it4(dd, 10);
	--it4;//向后移动10年
	cout << "year_iterator" << *it4 << endl;






	return 0;
}