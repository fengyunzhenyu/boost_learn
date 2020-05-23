
#include <iostream>
using namespace std;

#include<boost/date_time/gregorian/gregorian.hpp>
#include<boost/date_time/posix_time/posix_time.hpp>

#pragma comment(lib, "libboost_date_time-vc142-mt-gd-x32-1_72.lib")
//�������
using namespace boost::gregorian;
//ʱ�����
using namespace boost::posix_time;
int main()
{
	//ʱ��Ĺ���
	//ptime t1(date(2000, 1, 1));
	ptime t1 = time_from_string("2000-01-01");
	cout << t1 << endl;

	ptime t2 = from_iso_string("20000101T10000202");//����ĸT�ָ����� ʱ��
	cout << t2 << endl;

	ptime t3 = second_clock::local_time();//�뾫��
	cout << t3 << endl;

	ptime t4 = microsec_clock::local_time();//΢�뾫��
	cout << t4 << endl;

	ptime t5(min_date_time);//����ֵ
	ptime t6(max_date_time);//
	cout << t5 << endl;
	cout << t6 << endl;


	//�������ڳ���date_duration��Ҳ��ʱ�䳤��

	//1Сʱ10����20��99����
	time_duration td1(1, 10, 20, 99*1000);//���һ�������ĵ�λ��΢��
	cout << td1 << endl;

	//1Сʱ10����21�루�Զ���ǰ��λ��
	time_duration td2(1, 10, 20, 1000 * 1000);//���һ�������ĵ�λ��΢��
	cout << td2 << endl;

	//1Сʱ10����21�� 1΢��
	time_duration td3 = duration_from_string("1:10:20:000001");//���һ�������ĵ�λ��΢��
	cout << td3 << endl;

	//hours
	hours h(1);
	cout << h.total_seconds() << h.total_milliseconds() << h.total_microseconds()
		<< h.total_nanoseconds() << endl;//�� ���� ΢�� ����

	//����ʱ�䳤�ȹ���
	time_duration td4 = hours(1) + minutes(10) + seconds(20) + milliseconds(30) + microseconds(40);
	cout << td4 << endl;

	//��ʼʱ��
	ptime p1 = time_from_string("2000-01-01 00:00:01");
	//����ʱ��
	ptime p2(date(2000, 1, 2));//Ĭ����2000-01-01 23:59:59.999��
	//����һ��ʱ�䷶Χ
	time_period tp(p1, p2);//p2>p1
	cout << tp << endl;

	time_duration td = tp.length();//����ʱ�䳤��
	cout << td << endl;

	//��ʱ�䷶Χ���ƽ��9��
	tp.shift(seconds(9));
	cout << tp << endl;

	//��ʱ������������1Сʱ
	tp.expand(hours(1));
	cout << tp << endl;


	//����ʱ���Ƿ������ʱ�䷶Χ��
	ptime p3 = time_from_string("2000-01-01 00:00:01");
	cout << tp.contains(p3) << endl;


	/////////////////////////////////////////////////////
	//�������ڵ����� year_iterator
	//ʱ������� time_iterator
	ptime p4 = time_from_string("2000-01-01 00:00:01");

	time_iterator ite(p4, seconds(10));//��10��Ϊ����
	++ite;
	cout << *ite << endl;

	time_iterator it(p4, hours(24));//��24СʱΪ����
	++it;
	cout << *it << endl;


	//����ʱ���ʽ��
	date d1 = day_clock::local_day();
	date_facet* pDF = new date_facet("%Y�� %m�� %d��");
	/*iso_base���imbue����ָ���������ԣ�locale�����������ʹ�õĵ�ǰ������Ϣ��
	getloc���������������ĵ�ǰ���Ի���*/
	cout.imbue(locale(cout.getloc(), pDF));//ָ������������Ի���
	cout << d1 << endl;


	ptime t11 = microsec_clock::local_time();

	time_facet* pTF = new time_facet("% Y�� % m�� % d�� %H:%M:%S %F");
	cout.imbue(locale(cout.getloc(), pTF));
	cout << t11 << endl;


	return 0;
}