
#include <boost/algorithm/string.hpp>
#include <iostream>

using namespace boost;
using namespace std;

int main()
{
	//�޼���ȥ�����ҵĿհ��ַ�
	string str = "   Hello   ";
	cout << str << endl;
	trim(str);//ֱ���޸�ԭ�ַ���
	cout << str << endl;
	
	string str2 = "   Hello  ";
	cout << trim_copy(str2) << endl;//���޸�ԭ�ַ���
	cout << str2 << endl;

	struct is_xing//��������
	{
		bool operator()(const char c)
		{
			return c == '*';
		}
	};
	string str3 = "******Hello****";
	trim_if(str3, is_xing());
	cout << str3 << endl;


	//����
	string str4 = "Hello,Hello, hello, Boost!!!";
	iterator_range<string::iterator> rge;

	rge = find_first(str4, "hello");//���ҵ�һ�γ��ֵ��ַ���
	//rge = ifind_first(str4, "hello");
	cout << rge << endl;
	cout << rge.begin() - str4.begin() << "," << rge.end() - str4.begin() << endl;
	
	rge = find_last(str4, "hello");//�������һ�γ��ֵ��ַ���
	//rge = ifind_first(str4, "hello");
	cout << rge << endl;
	cout << rge.begin() - str4.begin() << "," << rge.end() - str4.begin() << endl;

	rge = find_nth(str4, "o", 4);//���ҵڼ��γ��ֵ��ַ���
	cout << rge << endl;
	cout << rge.begin() - str4.begin() << "," << rge.end() - str4.begin() << endl;

	rge = find_head(str4, 4);//����ǰ�ĸ��ַ�
	cout << rge << endl;
	cout << rge.begin() - str4.begin() << "," << rge.end() - str4.begin() << endl;


	//�滻��ɾ��
	string str5 = "Hello,Hello, hello, Boost!!!";
	ireplace_first(str5, "Hello", "XXX");//�滻��һ���������ִ�Сд
	cout << str5 << endl;

	replace_all(str5, "hello", "YYY");//�滻ȫ��
	cout << str5 << endl;

	erase_last(str5, "YYY");//ɾ�����һ��
	cout << str5 << endl;

	return 0;
}