#include <iostream>
#include <Windows.h>
#include "Header.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	
	StopWatch sw;

	/*sw.Start();
	cout << "���������� �������" << endl;
	sw.Show();

	Sleep(3000);
	sw.Stop();
	cout << "���������� ���������� ������ 3 ���" << endl;
	sw.Show();

	Sleep(5000);
	sw.Start();
	cout << "���������� ��������� ������ ������ 5 ������" << endl;
	sw.Show();*/


	cout << "������� 1 ��� ������" << endl;
	int a;
	cin >> a;

	if (a == 1)
	{
		sw.Start();
		cout << "���������� �������" << endl;
		sw.Show();
	}
	else
	{
		cout << "������� 1 ��� ������" << endl;
	}
	
	cout << "������� 2 ��� ���������" << endl;
	int b;
	cin >> b;

	if (b == 2)
	{
		sw.Stop();
		cout << "���������� ����������" << endl;
		sw.Show();
	}
	else
	{
		cout << "������� 2 ��� ���������" << endl;
	}
	

	

	cout << endl;
	return 0;
}