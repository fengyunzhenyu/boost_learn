#include<iostream>
using namespace std;

#include <boost/circular_buffer.hpp>
#include <boost/timer/timer.hpp>
#include <boost/format.hpp>
#include <boost/multi_array.hpp>
#include <boost/array.hpp>
using namespace boost;
using namespace boost::timer;
#include <map>



int main()
{
	//����ʱ����̬����һά���飬���鳤�����û�ָ��
	//int a = 10;
	//cin >> a;//�û�����һ������
	//int* pArr1 = new int[a];

	//����ʱ����̬������ά���飬ά�����û�ָ��
	//int a = 3, b = 4;;
	//cin >> a;
	//cin >> b;
	//new int[a][b];//�����޷�ͨ�����룬�ڶ�ά�ĳ��ȱ����ǳ���

	//�ó����ۣ�C++�У����˵�һά�Ŀ����Ǳ����������ά�ȱ����ǳ�����Ҳ����˵
	//�����ʱ���Ҫȷ����С

	//Ϊʲô����ָ�����˵�һά֮���ά��
	int e[][3] = { 1,2,3,4,5,6 };
	/*
		�����������Զ������һά�� 2 ��6/3 = 2��
		1 2 3
		4 5 6
	*/
	/*
		int e[3][] = {1,2,3,4,5,6};��ʼ��ֵ�ø��������ܴ�������ĳ��ȣ���Ϊ��Ĭ��ֵ
		����int ee[5] = {1};

		��һ�� 1 3 4 5 6        1 2 3       1 2 3 4
		�ڶ��� 6 0 0 0 0        4 5 6       5 6 0 0
		������ 0 0 0 0 0        0 0 0       0 0 0 0   
	*/

	//multi_array
	int a = 2;
	int b = 3;
	int c = 4;//cin>>c ���û�����
	//������һ��3ά���飬ÿһά�ĳ��ȿ��Զ�ָ̬��������Ҫ����ʱָ��
	multi_array<int, 3> arr(extents[a][b][c]);
	//����ͨ����һ����ֵ
	arr[0][0][0] = 111;
	arr[1][2][3] = 666;

	//��ӡ�����ÿһά�ȵĳ���
	cout << arr.shape()[0] << ", " << arr.shape()[1] << ", " << arr.shape()[2] << endl;

	for (size_t i = 0; i < arr.shape()[0]; i++)
	{
		for (size_t j = 0; j < arr.shape()[1]; j++)
		{
			for (size_t k = 0; k < arr.shape()[2]; k++)
			{
				cout << arr[i][j][k] << " ";
			}
		}
	}

	cout << endl;

	//Ԫ���ܸ���
	cout << arr.num_elements() << endl;



	//��̬�ı��ά����ĳ��ȣ�ԭ�е�Ԫ�ؽ������Ƶ��µ��ڴ�
	arr.resize(extents[4][5][6]);//�ı����ά����
	arr[3][4][5] = 999;
	cout << arr[0][0][0] << ", " << arr[1][2][3] << ", " << arr[4][5][6] << endl;

	//�ı���״��Ԫ���ܸ������䣬4*5*6 = 2*5*12
	//Ԫ�ز���
	boost::array<int, 3> wd = { 2, 5,12 };
	arr.reshape(wd);


	//����һ��3 ά���飬ʹ��array����
	boost::array<int, 3> wd2 = { a,b,c };
	multi_array<int, 3> arr2(wd2);

	return 0;
}