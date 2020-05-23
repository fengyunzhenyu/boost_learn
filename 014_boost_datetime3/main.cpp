
#include <iostream>
using namespace std;

#include<boost/date_time/gregorian/gregorian.hpp>
#include<boost/date_time/posix_time/posix_time.hpp>

#pragma comment(lib, "libboost_date_time-vc142-mt-gd-x32-1_72.lib")
//日期组件
using namespace boost::gregorian;
//时间组件
using namespace boost::posix_time;
int main()
{
	//时间的构造
	//ptime t1(date(2000, 1, 1));
	ptime t1 = time_from_string("2000-01-01");
	cout << t1 << endl;

	ptime t2 = from_iso_string("20000101T10000202");//用字母T分割日期 时间
	cout << t2 << endl;

	ptime t3 = second_clock::local_time();//秒精度
	cout << t3 << endl;

	ptime t4 = microsec_clock::local_time();//微秒精度
	cout << t4 << endl;

	ptime t5(min_date_time);//特殊值
	ptime t6(max_date_time);//
	cout << t5 << endl;
	cout << t6 << endl;


	//类似日期长度date_duration，也有时间长度

	//1小时10分钟20秒99毫秒
	time_duration td1(1, 10, 20, 99*1000);//最后一个参数的单位是微秒
	cout << td1 << endl;

	//1小时10分钟21秒（自动往前进位）
	time_duration td2(1, 10, 20, 1000 * 1000);//最后一个参数的单位是微秒
	cout << td2 << endl;

	//1小时10分钟21秒 1微秒
	time_duration td3 = duration_from_string("1:10:20:000001");//最后一个参数的单位是微秒
	cout << td3 << endl;

	//hours
	hours h(1);
	cout << h.total_seconds() << h.total_milliseconds() << h.total_microseconds()
		<< h.total_nanoseconds() << endl;//秒 毫秒 微秒 纳秒

	//利用时间长度构造
	time_duration td4 = hours(1) + minutes(10) + seconds(20) + milliseconds(30) + microseconds(40);
	cout << td4 << endl;

	//起始时间
	ptime p1 = time_from_string("2000-01-01 00:00:01");
	//结束时间
	ptime p2(date(2000, 1, 2));//默认是2000-01-01 23:59:59.999；
	//产生一个时间范围
	time_period tp(p1, p2);//p2>p1
	cout << tp << endl;

	time_duration td = tp.length();//返回时间长度
	cout << td << endl;

	//把时间范围向后平移9秒
	tp.shift(seconds(9));
	cout << tp << endl;

	//把时间向两边扩大1小时
	tp.expand(hours(1));
	cout << tp << endl;


	//摸个时间是否在这个时间范围内
	ptime p3 = time_from_string("2000-01-01 00:00:01");
	cout << tp.contains(p3) << endl;


	/////////////////////////////////////////////////////
	//类似日期迭代器 year_iterator
	//时间迭代器 time_iterator
	ptime p4 = time_from_string("2000-01-01 00:00:01");

	time_iterator ite(p4, seconds(10));//以10秒为步长
	++ite;
	cout << *ite << endl;

	time_iterator it(p4, hours(24));//以24小时为步长
	++it;
	cout << *it << endl;


	//日期时间格式化
	date d1 = day_clock::local_day();
	date_facet* pDF = new date_facet("%Y年 %m月 %d日");
	/*iso_base类的imbue方法指定区域语言，locale类决定程序所使用的当前语言信息，
	getloc方法返回流关联的当前语言环境*/
	cout.imbue(locale(cout.getloc(), pDF));//指定输出流的语言环境
	cout << d1 << endl;


	ptime t11 = microsec_clock::local_time();

	time_facet* pTF = new time_facet("% Y年 % m月 % d日 %H:%M:%S %F");
	cout.imbue(locale(cout.getloc(), pTF));
	cout << t11 << endl;


	return 0;
}