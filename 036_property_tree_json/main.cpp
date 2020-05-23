

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/json_parser.hpp>
using namespace boost;
using namespace boost::property_tree;
#include<Windows.h>
#include<iostream>
using namespace std;

int main()
{
	//����basic_ptree<std::string, std::string> ����
	ptree pt;

	//��ȡjson�ļ�
	read_json("test.json", pt);

	//����json����
	cout << "������" << pt.get<string>("stu.name") << endl;
	{
		//���ĵ������
		//����Ϊ�����

		string str = pt.get<string>("stu.name");
		cout << str.length() << endl;//С�� ��������ռ��6���ֽڣ�˵����utf-8����
		//cout�޷����utf-8�ı���
		//���濼��utf-8ת��ΪUnicode����wstring���գ�Ȼ����wcount���

		//��ת��ΪUnicode��Ҫ���Ŀռ���
		int len = MultiByteToWideChar(CP_UTF8, NULL, str.data(), str.length(), NULL, 0);
		//��ʼת������
		wchar_t* pw = new wchar_t[len + 1];
		MultiByteToWideChar(CP_UTF8, NULL, str.data(), str.length(), pw, len + 1);
		pw[len] = '\0';
		//����wcout���ػ���
		wcout.imbue(locale("", LC_CTYPE));
		wcout << L"������" << pw << endl;
	}
	cout << "���䣺" << pt.get<int>("stu.age") << endl;
	cout << "�ɼ���" << pt.get<float>("score") << endl;
	cout << "�Ա�" << pt.get<string>("sex","����") << endl;

	//��������������
	auto pt2 = pt.get_child("lesson");
	for (auto it = pt2.begin(); it != pt2.end(); it++)
	{
		cout << it->second.data() << endl;
	}

	return 0;
}