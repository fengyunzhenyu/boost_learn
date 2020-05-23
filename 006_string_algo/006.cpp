#include <iostream>

//string_algo ���ͷ�ļ�
#include <boost/algorithm/string.hpp>

using namespace boost;
using namespace std;

int main()
{
	//��Сдת��
	string str1 = "abc";
	to_upper(str1);//�ı�ԭ�ַ���
	cout << str1 << endl;

	to_lower(str1);//�ı�ԭ�ַ���
	cout << str1 << endl;

	string str2 = to_upper_copy(str1);//���ı�ԭ���ַ���
	cout << str1 << endl;
	cout << str2 << endl;

	//�ж�ʽ������bool
	cout << "--�ж�ʽ---" << endl;
	cout << starts_with("Hello World", "He") << endl;//��Сд����
	cout << starts_with("Hello World", "he") << endl;
	cout << istarts_with("Hello World", "he") << endl;//i��Сд������

	cout << ends_with("Hello World", "ld") << endl;//��Сд����
	//cout << starts_with("Hello World", "he") << endl;
	cout << iends_with("Hello World", "Ld") << endl;//i��Сд������


	cout << contains("Hello World", "llo") << endl;//��Сд����
	cout << icontains("Hello World", "LLO") << endl;//��Сд������


	cout << equals("abc", "abc") << endl;//�����Ƿ����
	cout << iequals("abc", "ABC") << endl;//�����Ƿ���ȣ�i���Դ�Сд

	cout << all("Hello", is_lower()) << endl;//�ж�ÿһ���ַ��Ƿ�ȫ��Сд
	cout << all("hello", is_lower()) << endl;//

	cout << lexicographical_compare("abc", "xyz") << endl;//�ֵ�����һ���Ƿ�С�ں����
	cout << ilexicographical_compare("abc", "XYZ") << endl;//i���Դ�дСд

	cout << "�ж�ʽ����������" << endl;
	cout << is_equal()("abc", "abc") << endl;//�����Ƿ���ȣ�i���Դ�Сд
	is_equal eq;
	cout << eq("abc", "abc") << endl;
	cout << is_less()("abc", "xyz") << endl;//�����Ƿ�С��
	cout << is_not_greater()("abc", "xyz") << endl;//�����Ƿ񲻴���

	cout << "����" << endl;
	cout << is_alnum()('1') << endl;//�ж��Ƿ�����ĸ��������
	cout << is_alnum()('a') << endl;
	cout << is_alnum()(',') << endl;

	cout << is_alpha()('A') << endl;//�Ƿ���ĸ
	cout << is_digit()('1') << endl;//�Ƿ�����
	cout << is_cntrl()('\n') << endl;//�Ƿ�����ַ�
	cout << is_any_of("ABCD")('A') << endl;//�Ƿ���ABCD�е�����һ��

	cout << is_xdigit()('Q') << endl;//�Ƿ���16���Ƶ��ַ�
	cout << is_lower()('a') << endl;//�Ƿ�Сд�ַ�


	return 0;
}