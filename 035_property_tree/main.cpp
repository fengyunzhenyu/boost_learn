

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/xml_parser.hpp>
using namespace boost;
using namespace boost::property_tree;

#include<iostream>
using namespace std;

int main()
{
	//����basic_ptree<std::string, std::string> ����
	ptree pt;

	//��ȡxml�ļ�
	xml_parser::read_xml("test.xml", pt);

	//����xml
	cout << "������" << pt.get<string>("stu.name") << endl;
	cout << "���䣺" << pt.get<int>("stu.age") << endl;
	cout << "ƽ���֣�" << pt.get<float>("stu.score") << endl;
	//�Ҳ����ڵ㣬���Ĭ��ֵ
	cout << "�Ա�" << pt.get<string>("stu.sex", "����") << endl;

	//�ڵ���������ݲ������ݣ����ǽڵ�
	auto pt2 = pt.get_child("stu.lesson");
	for (auto it = pt2.begin(); it != pt2.end(); it++)
	{
		cout << it->first.data() << "->" << it->second.data() << endl;
	}

	//��ȡ�ڵ�����
	cout << "ѧ�ţ�" << pt.get<string>("stu.name.<xmlattr>.id") << endl;

	return 0;
}