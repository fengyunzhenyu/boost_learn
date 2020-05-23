
#include<iostream>

using namespace std;

#include<boost/date_time/gregorian/gregorian.hpp>
using namespace boost::gregorian;

#pragma comment(lib, "libboost_date_time-vc142-mt-gd-x32-1_72.lib")

/*date_time���ṩ��ʱ��������صļ��㡢��ʽ����ת������������ȹ��ܣ�ΪC++������ʱ�����ṩ�˼������*/
int main()
{
	/*date����date_time�⴦�����ڵĺ����࣬����Ϊ��λ
	��ʾʱ�����date֧�ֱȽϲ�����������������ǿ���
	��ȫ���԰�������һ����int��string�����Ļ���������ʹ��*/
	//��������
	date d1(2000, 1, 1);
	date d2 = from_string("2010-02-02");
	date d3 = from_string("2010/03/03");
	date d4 = from_undelimited_string("20100404");

	date d5(min_date_time);//����ʱ��ֵ 1400-01-01
	date d6(max_date_time);//����ʱ��ֵ 9999-12-31
	cout << d1.year() << "��" << d1.month() << "��" << d1.day() << "��" << endl;
	cout << d1.year() << "��" <<(int) d1.month() << "��" << d1.day() << "��" << endl;
	cout << to_simple_string(d2) << endl;//YYYY-MMM-DD
	cout << to_iso_string(d3) << endl;//YYYYMMDD
	cout << to_iso_extended_string(d4) << endl;//YYYY-MM-DD
	cout << to_simple_string(d5) << endl;
	cout << to_simple_string(d6) << endl;

	//��ȡ���������
	date today = day_clock::local_day();
	cout <<"��"<< today.year() << endl;
	cout <<"��"<< today.month() << endl;
	cout <<"��"<< today.day() << endl;
	cout << "����" << today.day_of_week() << endl;
	cout << "һ���еĵڼ���" << today.week_number() << endl;
	cout << "һ���еĵڶ�����" << today.day_of_year() << endl;
	cout << "����µĽ�������" << today.end_of_month() << endl;

	//ʱ�䳤�ȣ���С��λ�� �죩
	days day1(10);
	days day2(-5);
	date_duration du1 = day1 + day2;
	cout << "10��-5��" << du1.days() << endl;

	weeks w1(1);
	cout << "һ�ܵ�����" << w1.days() << endl;
	date_duration du2 = w1 + day1;
	cout << "1��+10��" << du2.days() << endl;

	months mon1(1);//һ�����޷�֪���Ƕ����죬�����޷�������
	cout << "һ����" << mon1.number_of_months() << endl;
	
	years year1(1);//һ���޷�֪���Ƕ����죬�����޷�������
	cout << "һ��" << year1.number_of_years() << endl;

	//���֪��һ����ٸ���
	months mon2 = year1 + months(0);
	cout << "һ����ٸ���" << mon2.number_of_months() << endl;


	//����+���ڳ��� = ������
	date d10(2018, 1, 31);
	cout << "������ǰ��10���Ǽ��¼���" << d10 + days(-10) << endl;

	cout << "���������2���Ǽ��¼���" << to_iso_extended_string(d10 + weeks(2)) <<endl;

	cout << "����������һ���Ǽ��¼���" << to_iso_extended_string(d10 + years(1)) << endl;


	/*date_period��������ʾ���ڷ�Χ�ĸ������ʱ������һ������ҿ����䣬�˵�������date����*/
	date d11(2000, 1, 1);
	date d22(2000, 2, 1);
	//����һ�����ڷ�Χ
	date_period dp1(d11, d22);//��������ȷ��һ����Χ
	cout << dp1 << endl;//����ҿ����䣬������2000��2��1��
	cout << dp1.length() << endl;//���������Χ������

	//�����ڷ�Χƽ��
	dp1.shift(date_duration(10));
	cout << dp1 << endl;//����ƶ�10��

	//����������������
	dp1.expand(date_duration(1));//�������ƶ�һ��
	cout << dp1 << endl;

	//���ĳ�������Ƿ���������ڷ�Χ����
	cout << dp1.contains(date(2000, 1, 20)) << endl;


	//���ڵ�����
	date dd(2000, 1, 1);
	day_iterator it1(dd);//Ĭ�ϲ�����1
	//day_iterator it1(dd, 10);
	++it1;//����Ӱ��ԭ����dd��ֻ������
	cout << *it1 << endl;

	week_iterator it2(dd, 2);
	--it2;//��ǰ�ƶ�����
	cout << "week_iterator" << *it2 << endl;

	month_iterator it3(dd, 1);
	--it3;//��ǰ�ƶ�һ����
	cout << "month_iterator" << *it3 << endl;

	year_iterator it4(dd, 10);
	--it4;//����ƶ�10��
	cout << "year_iterator" << *it4 << endl;






	return 0;
}